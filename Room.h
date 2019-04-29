#pragma once
#include <random>
#include "Wall.h"
#include "Player.h"
#include <vector>
#include "Enemy.h"

using namespace std;

class Room
{
public:
	Room(sf::Texture* texture, sf::Vector2f spawnPos, int roomType);
	void sealExit(sf::Texture* texture, int roomType);
	void miniMap(sf::RenderWindow & window);
	void placeEnemies();
	void activateEnemies();
	bool enemiesDefeated();
	Room();
	~Room();

	vector<vector<Wall>> layout;
	vector<Enemy> enemies;
	sf::Vector2f maxSize = sf::Vector2f(15.0f,9.0f);
	sf::Vector2f center;

	float xBound1;
	float xBound2;
	float yBound1;
	float yBound2;

	bool start;
	bool end;
	bool taken = false;

	bool Active(Player player);
	void Display(sf::RenderWindow & window, Collider playerCollider, Player &player);
	

};

