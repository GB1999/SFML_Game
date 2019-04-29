#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Wall.h"
#include "Hazard.h"
#include "Room.h"
#include "Map.h"

using namespace std;
static const float VIEW_HEIGHT = 900.0f;
static const float VIEW_HEIGHT2 = 8100.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Dungeon Crawler", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	//////////////////////////////////////////////// Load Texture Files
	sf::Texture playerTexture;
	playerTexture.loadFromFile("Textures/sprite_sheet.png");

	sf::Texture hazardTexture;
	hazardTexture.loadFromFile("Textures/Demon.png");

	sf::Texture zombieTexture;
	zombieTexture.loadFromFile("Textures/Zombie.png");

	sf::Texture chargerTexture;
	chargerTexture.loadFromFile("Textures/Charger.png");

	sf::Texture wallTexture;
	wallTexture.loadFromFile("Textures/wall.jpg");

	sf::Texture fireballTexture;
	fireballTexture.loadFromFile("Textures/fireball.png");

	sf::Texture arrowTexture;
	arrowTexture.loadFromFile("Textures/arrow.png");
	////////////////////////////////////////////////

	//////////////////////////////////////////////// Initialize Game Objects
	

	//Projectiles
	Projectile fireBall(&fireballTexture, sf::Vector2f(10.0f, 10.0f), 900.0f, 100.0f, 0.5f);
	Projectile arrow(&arrowTexture, sf::Vector2f(10.0f, 10.0f), 700.0f, 8.0f, 1.0f);

	//Enemies
	Enemy monster(&hazardTexture, sf::Vector2u(4, 4), sf::Vector2f(500.0f, 500.0f), fireBall, .15f, 1);
	Enemy zombie(&zombieTexture, sf::Vector2u(1, 1), sf::Vector2f(200.0f, 100.0f), arrow, 1.0f, 2);
	Enemy charger(&chargerTexture, sf::Vector2u(4,3), sf::Vector2f(200.0f, 200.0f), arrow, .10f, 3);

	vector<Enemy> enemyPreset1;
	enemyPreset1.push_back(monster);
	enemyPreset1.push_back(zombie);
	enemyPreset1.push_back(charger);

	vector<Enemy> enemyVariety1;
	vector<Enemy> enemyVariety2;
	vector<Enemy> enemyVariety3;
	vector<Enemy> enemyVariety4;
	vector<Enemy> enemyVariety5;

	vector<vector<Enemy>> enemySelection;

	enemySelection.push_back(enemyVariety1);
	enemySelection.push_back(enemyVariety2);
	enemySelection.push_back(enemyVariety3);
	enemySelection.push_back(enemyVariety4);
	enemySelection.push_back(enemyVariety5);

	for (int i = 0; i < enemySelection.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int r = rand() % 3;
			cout << "the random number is " << r << endl;
			enemySelection[i].push_back(enemyPreset1[r]);
		}
	}

	Map map1(&wallTexture, sf::Vector2f(0.0f, 0.0f), enemySelection);
	sf::Vector2f center = map1.getOrigin();
	sf::Vector2f center2 = map1.getOrigin() + sf::Vector2f(900.0f, 100.0f);

	
	
	

	
	
	Player player(&playerTexture, sf::Vector2u(12, 9), center, fireBall, 0.035f, 300.0f);
	

	


	//map1.layout[4][4].enemies = enemySelection[1];
	//map1.layout[4][4].placeEnemies();


	Hazard hazard1(&hazardTexture, sf::Vector2f(100.0f, 100.f), sf::Vector2f(6800.0f,4100.0f), 20);


	float deltaTime = 0.0f;
	sf::Clock clock;

	


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case::sf::Event::Resized:

				ResizeView(window, view);
				break;
			}
		}

		player.Update(deltaTime);

		player.updateProjectiles(deltaTime);
		Collider playerCollider = player.getCollider();

		vector<int> activeRoom = map1.findActive(player);
		for (int i = 0; i < map1.layout[activeRoom[0]][activeRoom[1]].enemies.size(); i++)
		{
			map1.layout[activeRoom[0]][activeRoom[1]].enemies[i].Update(deltaTime, player);
		}
		for (int i = 0; i < map1.layout[activeRoom[0]][activeRoom[1]].enemies.size(); i++)
		{
			map1.layout[activeRoom[0]][activeRoom[1]].enemies[i].updateProjectiles(deltaTime);
		}
		view.setCenter(map1.layout[activeRoom[0]][activeRoom[1]].center);

		window.clear();
		window.setView(view);

		//map1.Display(window, playerCollider, player);
		map1.displayAll(window, playerCollider, player);
		window.display();
		
		
	}

	return 0;
}