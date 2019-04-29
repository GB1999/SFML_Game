#include "Room.h"
#include <iostream>

Room::Room()
{

}

Room::Room(sf::Texture* texture, sf::Vector2f spawnPos, int roomType)
{
	xBound1 = spawnPos.x;
	xBound2 = spawnPos.x + maxSize.x *100.0f;

	yBound1 = spawnPos.y;
	yBound2 = spawnPos.y + maxSize.y *100.0f;

	center = spawnPos + sf::Vector2f(7*100.0f, 4*100.0f);
	// "null" room
	if (roomType == 0)
	{
		for (int x = 0; x < maxSize.x; x++)
		{
			layout.push_back(vector<Wall>());
			for (int y = 0; y < maxSize.y; y++)
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}
		}
	}

	//Room with 4 exits 
	else if (roomType == 1)
	{
		for (int x = 0; x < maxSize.x; x++)
		{
			layout.push_back(vector<Wall>());
			for (int y = 0; y < maxSize.y; y++)
			{
				if (x == 0 || x == maxSize.x - 1)
				{
					if (y != 5)
					{
						layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
					}
					else
					{
						layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
					}

				}
				else if (y == 0 || y == maxSize.y - 1)
				{
					if (x != 8)
					{
						layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
					}
					else
					{
						layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
					}
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
		}
	}

	//Room with 3 exits (T,R,L)
	else if (roomType == 2)
	{
		for (int x = 0; x < maxSize.x; x++)
		{
			layout.push_back(vector<Wall>());
			for (int y = 0; y < maxSize.y; y++)
			{
				if (x == 0 || x == maxSize.x - 1)
				{
					if (y != 5)
					{
						layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
					}
					else
					{
						layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
					}

				}
				else if (y == maxSize.y - 1)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
					
				}
				else if (y == 0)
				{
					if (x != 8)
					{
						layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
					}
					else
					{
						layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
					}
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
		}
	}

	//Room with 3 exits (T,R,B)
	else if (roomType == 3)
	{
		for (int x = 0; x < maxSize.x; x++)
		{
			layout.push_back(vector<Wall>());
			for (int y = 0; y < maxSize.y; y++)
			{
				if (x == 0)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));

				}
				else if (x == maxSize.x - 1)
				{
					if (y != 5)
					{
						layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
					}
					else
					{
						layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
					}
				}
				else if (y == 0 || y == maxSize.y - 1)
				{
					if (x != 8)
					{
						layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
					}
					else
					{
						layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
					}
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
		}
	}

	//Room with 3 exits (R,B,L)
	else if (roomType == 4)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == 0 || x == maxSize.x - 1)
			{
				if (y != 5)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
			else if (y == 0)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else if ( y == maxSize.y - 1)
			{
				if (x != 8)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}
			}
			
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

	//Room with 3 exits (T,B,L)
	else if (roomType == 5)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == maxSize.x - 1)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));

			}
			else if (x == 0)
			{
				if (y != 5)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}
			}
			else if (y == 0 || y == maxSize.y - 1)
			{
				if (x != 8)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

	//Room with 2 exits (T,B)
	else if (roomType == 6)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == 0 || x == maxSize.x - 1)
			{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else if (y == 0 || y == maxSize.y - 1)
			{
				if (x != 8)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

	//Room with 2 exits (R,L)
	else if (roomType == 7)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == 0 || x == maxSize.x - 1)
			{
				if (y != 5)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
			else if (y == 0 || y == maxSize.y - 1)
			{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}
	
	//Room with 2 exits (T,R)
	else if (roomType == 8)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == maxSize.x - 1)
			{
				if (y != 5)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
			else if (x == 0)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else if (y == 0)
			{
				if (x != 8)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}
			}
			else if (y == maxSize.y - 1)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

	//Room with 2 exits (R,B)
	else if (roomType == 9)
	{
		for (int x = 0; x < maxSize.x; x++)
		{
			layout.push_back(vector<Wall>());
			for (int y = 0; y < maxSize.y; y++)
			{
				if (x == maxSize.x - 1)
				{
					if (y != 5)
					{
						layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
					}
					else
					{
						layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
					}

				}
				else if (x == 0)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else if (y == maxSize.y - 1)
				{
					if (x != 8)
					{
						layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
					}
					else
					{
						layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
					}
				}
				else if (y == 0)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
		}
	}

	//Room with 2 exits (B,L)
	else if (roomType == 10)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == 0)
			{
				if (y != 5)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
			else if (x == maxSize.x - 1)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else if (y == maxSize.y - 1)
			{
				if (x != 8)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}
			}
			else if (y == 0)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

	//Room with 2 exits (T,L)
	else if (roomType == 11)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == 0)
			{
				if (y != 5)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
			else if (x == maxSize.x - 1)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else if (y == 0)
			{
				if (x != 8)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}
			}
			else if (y == maxSize.y - 1)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

	//Room with 1 exit (T) 
	else if (roomType == 12)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == 0 || x == maxSize.x - 1)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else if (y == 0)
			{
				if (x != 8)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}
			}
			else if (y == maxSize.y - 1)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

	//Room with 1 exits (L) 
	else if (roomType == 13)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == maxSize.x - 1)
			{
				if (y != 5)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
			else if (x == 0)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else if (y == 0 || y == maxSize.y - 1)
			{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

	//Room with 1 exits (B) 
	else if (roomType == 14)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == 0 || x == maxSize.x - 1)
			{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else if (y == maxSize.y - 1)
			{
				if (x != 8)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}
			}
			else if (y == 0)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

	//Room with 4 exits 
	else if (roomType == 15)
	{
	for (int x = 0; x < maxSize.x; x++)
	{
		layout.push_back(vector<Wall>());
		for (int y = 0; y < maxSize.y; y++)
		{
			if (x == 0 )
			{
				if (y != 5)
				{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
				}
				else
				{
					layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
				}

			}
			else if (x == maxSize.x - 1)
			{
				layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else if (y == 0 || y == maxSize.y - 1)
			{
					layout[x].push_back(Wall(texture, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), true));
			}
			else
			{
				layout[x].push_back(Wall(nullptr, sf::Vector2f(100.0f, 100.f), spawnPos + sf::Vector2f(100.0f * x, 100.0f * y), false));
			}

		}
	}
	}

}

void Room::sealExit(sf::Texture * texture, int roomType)
{
	if (roomType == 1)
	{
		layout[maxSize.x / 2 + 1 ][maxSize.y - 1] = (Wall(nullptr, sf::Vector2f(100.0f, 100.f), sf::Vector2f(100.0f * 5 + xBound1, 100.0f * 0 + yBound1), true));
	}
	if (roomType == 2)
	{
		layout[0][maxSize.y / 2 + 1] = (Wall(nullptr, sf::Vector2f(100.0f, 100.f), sf::Vector2f(100.0f * 5 + xBound1, 100.0f * 0 + yBound1), true));
	}
	if (roomType == 3)
	{
		layout[maxSize.x /2 + 1][0] = (Wall(nullptr, sf::Vector2f(100.0f, 100.f), sf::Vector2f(100.0f * 5 + xBound1, 100.0f * 0 + yBound1), true));
	}
	if (roomType == 4)
	{
		layout[maxSize.x - 1][maxSize.y / 2 + 1] = (Wall(nullptr, sf::Vector2f(100.0f, 100.f), sf::Vector2f(100.0f * 5 + xBound1, 100.0f * 0 + yBound1), true));
		
	}

}

Room::~Room()
{
}

bool Room::Active(Player player) 
{
	return(player.getPostition().x > xBound1 && player.getPostition().x < xBound2 && player.getPostition().y > yBound1 && player.getPostition().y < yBound2);
}

bool Room::enemiesDefeated()
{
	if (enemies.size() == 0)
	{
		return true;
	}
}

void Room::Display(sf::RenderWindow & window, Collider playerCollider, Player &player)
{
	
	// Check if Player is touching a wall
	for (int x = 0; x < maxSize.x; x++)
	{
		for (int y = 0; y < maxSize.y; y++)
		{
			layout[x][y].Draw(window);
			if (layout[x][y].getcolliderState() == true)
			{
				Collider wallCollider = layout[x][y].getCollider();
				playerCollider.checkCollider(wallCollider, 0.0f);
				//Check if enemy is touching a wall
				/*
				for (int i = 0; i < enemies.size(); i++)
				{
					Collider enemyCollider = enemies[i].getCollider();
					enemyCollider.checkCollider(wallCollider, 0.0f);
				}
				*/
			}
			
		}
	}
	
	// for each enemy in the room
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].Draw(window);
		enemies[i].drawProjectiles(window);
		Collider enemyCollider = enemies[i].getCollider();
		// Check if enemy is touching the player
		if (playerCollider.checkCollider(enemyCollider, 0.0f))
		{
			player.takeDamage(enemies[i].getDamage());
			cout << "Don't touch that" << endl;
		}
		// check if enemy touches a projectile
		int numProjectiles = player.getProjectiles().size();
		for (int j = 0; j < numProjectiles; j++)
		{
			Collider projectileCollider = player.projectiles[j].getCollider();
			if (projectileCollider.checkCollider(enemyCollider, 0.0f))
			{
				enemies[i].takeDamage(player.projectiles[j].damage);
				player.projectiles.erase(player.projectiles.begin() + j);
				cout << "enemy " << i << "took damage" << endl;
				cout << "their health is now" <<  enemies[i].getHealth() << endl;
				if (enemies[i].getHealth() < 0)
				{
					enemies.erase(enemies.begin() + i);
				}
			}
		}
		

	}
	// check if player is touching enemy projectiles
	for (int i = 0; i < enemies.size(); i++)
	{
		int numEnemyProjectiles = enemies[i].getProjectiles().size();
		for (int k = 0; k < numEnemyProjectiles; k++)
		{
			Collider enemyProjectileCollider = enemies[i].projectiles[k].getCollider();
			if (enemyProjectileCollider.checkCollider(playerCollider, 1.0f))
			{
				player.takeDamage(enemies[i].projectiles[k].damage);
				enemies[i].projectiles.erase(enemies[i].projectiles.begin() + k);
				cout << "ouch you shot me" << endl;
			}
		}
	}
	
	player.Draw(window);
	player.drawProjectiles(window);
}

void Room::miniMap(sf::RenderWindow & window)
{
	for (int x = 0; x < maxSize.x; x++)
	{
		for (int y = 0; y < maxSize.y; y++)
		{
			layout[x][y].Draw(window);
		}
	}
}

void Room::activateEnemies()
{
	for (int e = 0; e < enemies.size(); e++)
	{
		enemies[e].setActive();
	}
}

void Room::placeEnemies()
{
	for (int e = 0; e < enemies.size(); e++)
	{
		if (e % 2 == 0)
		{
			enemies[e].setPostion(center + sf::Vector2f(100.0f * e, 100.0f * e));
		}
		else
		{
			enemies[e].setPostion(center + sf::Vector2f(100.0f * -e, 100.0f * -e));
		}
		
	}
}