#include "Map.h"



Map::Map(sf::Texture* texture, sf::Vector2f start, vector<vector<Enemy>> &enemyLayout)
{
	this->start = start;
	this->enemyLayout = enemyLayout;
	Clear();
	Generate(texture, 4,4,2);
	Populate();
	
}


Map::~Map()
{
}

void Map::Clear() 
{
	for (int x = 0; x < mapSize.x; x++)
	{
		layout.push_back(vector<Room>());
		for (int y = 0; y < mapSize.y; y++)
		{
			layout[x].push_back(Room(nullptr, start + sf::Vector2f(1500.0f * x, 900.0f * y), 0));
		}
	}
}


void Map::Generate(sf::Texture* texture, int x, int y, int openingDirection) 
{		
		//counter++;
		if (x >= mapSize.x || y >= mapSize.y || x <= 1 || y <= 1  || layout[x][y].taken)
		{
			if (x >= mapSize.x || y >= mapSize.y)
			{
				cout << "//////////////////////////////cannot place room at" << x << " " << y << endl;
				if (openingDirection == 1)
				{
					cout << "***************sealing bottom";
					layout[x][y - 1].sealExit(texture, 1);
				}
				if (openingDirection == 2)
				{
					cout << "***************sealing left";
					layout[x+1][y].sealExit(texture, 2);
				}
				if (openingDirection == 3)
				{
					cout << "***************sealing top";
					layout[x][y + 1].sealExit(texture, 3);
				}
				if (openingDirection == 4)
				{
					cout << "***************sealing right";
					layout[x - 1][y].sealExit(texture, 4);
				}

			}
			else if (x <= mapSize.x && y <= mapSize.y && layout[x][y].taken)
			{
				cout << x << " " << y << " is already taken" <<endl;
			}
		}
		// Room open top
		else if (openingDirection == 1) 
		{
			int r = top[rand() % 6 + 1];
			cout << "the random top room is " << r << endl;
			cout << x << " " << y << endl;
			cout << endl;
			layout[x][y] = Room(texture,start + sf::Vector2f(1500.0f * x, 900.0f * y), r);
			layout[x][y].taken = true;
			Generate(texture, x, y - 1, 3);
			if (exists( (left), 7, r))
			{
				cout << "this room also opens left T" << endl;
				Generate(texture, x - 1, y, 2);
			}
			if (exists( (right), 7, r))
			{
				cout << "this room also opens right T" << endl;
				Generate(texture, x + 1, y, 4);
			}
			if (exists( (bottom), 7, r))
			{
				cout << "this room also opens down T" << endl;
				Generate(texture, x, y + 1, 1);
			}
		}
		// Room opens right
		else if (openingDirection == 2) 
		{
			
			int r = right[rand() % 6 + 1];
			cout << "the random right room is " << r << endl;
			cout << x << " " << y << endl;
			cout << endl;
			layout[x][y] = Room(texture, start + sf::Vector2f(1500.0f * x, 900.0f * y), r);
			layout[x][y].taken = true;
			Generate(texture, x+1,y,4);
			if (exists( (bottom), 7, r))
			{
				cout << "this room also opens down R" << endl;
				Generate(texture, x, y + 1, 1);
			}
			if (exists( (left), 7, r))
			{
				cout << "this room also opens left R" << endl;
				Generate(texture, x - 1, y, 2);
			}
			if (exists( (top), 7, r))
			{
				cout << "this room also opens up R" << endl;
				Generate(texture, x, y - 1, 3);
			}
		}
		// Room opens bottom
		else if (openingDirection == 3) 
		{
			
			int r = bottom[rand() % 6 + 1];
			cout << "the random bottom room is " << r << endl;
			cout << x << " " << y << endl;
			cout << endl;
			layout[x][y] = Room(texture, start + sf::Vector2f(1500.0f * x, 900.0f * y), r);
			layout[x][y].taken = true;
			Generate(texture, x, y + 1, 1);
			if (exists( (right), 7, r))
			{
				cout << "this room also opens right1 B" << endl;
				Generate(texture, x + 1, y, 4);

			}
			if (exists( (left), 7, r))
			{
				cout << "this room also opens left B" << endl;
				Generate(texture, x - 1, y, 2);
			}
			if (exists( (top), 7, r))
			{
				cout << "this room also opens up B" << endl;
				Generate(texture, x, y - 1, 3);
			}
			
		}
		// Room opens left
		else if (openingDirection == 4) 
		{
			
			int r = left[rand() % 6 + 1];
			cout << "the random left room is " << r << endl;
			cout << x << " " << y << endl;
			cout << endl;
			layout[x][y] = Room(texture, start + sf::Vector2f(1500.0f * x, 900.0f * y), r);
			layout[x][y].taken = true;
			Generate(texture, x - 1, y, 2);
			if (exists( (bottom), 7, r))
			{
				cout << "this room also opens down L" << endl;
				Generate(texture, x, y + 1, 1);
			}
			if (exists( (right), 7, r))
			{
				cout << "this room also opens right L" << endl;
				Generate(texture, x + 1, y, 4);
			}
			if (exists( (top), 7, r))
			{
				cout << "this room also opens up L" << endl;
				Generate(texture, x, y - 1, 3);
			}
		}
}

void Map::Populate()
{
	for (int i = 0; i < mapSize.x; i++)
	{
		for (int j = 0; j < mapSize.y; j++)
		{
			layout[i][j].enemies = enemyLayout[rand() % 5];
			layout[i][j].placeEnemies();
		}
	}
}


//This class originally returned a room, but that created issues
vector<int> Map::findActive(Player &player)
{
	vector<int> location;
	for (int i = 0; i < mapSize.x; i++)
	{
		for (int j = 0; j < mapSize.y; j++)
		{
			if (layout[i][j].Active(player))
			{
				location.push_back(i);
				location.push_back(j);
				return location;
			}
				
		}
			
	}
}

void Map::Display(sf::RenderWindow & window, Collider playerCollider, Player &player)
{
	//Room activeRoom = findActive(player);
	//activeRoom.Display(window, playerCollider, player);
	
}
void Map::displayAll(sf::RenderWindow & window, Collider playerCollider, Player &player)
{
	for (int i = 0; i < mapSize.x; i++)
	{
		for (int j = 0; j < mapSize.y; j++)
		{
			if (layout[i][j].Active(player))
			{
				layout[i][j].Display(window, playerCollider, player);
				layout[i][j].activateEnemies();
			}

		}

	}
	
}

void Map::miniMap(sf::RenderWindow & window)
{
	for (int i = 0; i < mapSize.x; i++)
	{
		for (int j = 0; j < mapSize.y; j++)
		{
			layout[i][j].miniMap(window);

		}

	}
}

sf::Vector2f Map::getOrigin()
{
	return layout[4][4].center;
}

// Simple array search 
bool Map::exists(int ints[], int size, int k)
{
	for (int i = 0; i <= size; i++)
	{
		if (ints[i] == k)
		{
			return true;
		}
	}
	return false;
}
