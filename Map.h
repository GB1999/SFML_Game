#pragma once
#include "Room.h"
#include "Enemy.h"
#include <random>
#include <time.h> 
#include <algorithm>

class Map
{
public:
	Map(sf::Texture* texture, sf::Vector2f start, vector<vector<Enemy>> &enemyLayout);
	~Map();

	void Clear();
	void Generate(sf::Texture* texture, int x, int y, int openingDirection);
	void Populate();
	void Display(sf::RenderWindow & window, Collider playerCollider, Player &player);
	void displayAll(sf::RenderWindow & window, Collider playerCollider, Player &player);
	void miniMap(sf::RenderWindow & window);
	bool exists(int ints[], int size, int k);
	//sf::Vector2f getSpawn();
	vector<int>  findActive(Player &player);
	sf::Vector2f getOrigin();
	sf::Vector2f mapSize = sf::Vector2f(9.0f, 9.0f);
	sf::Vector2f start = sf::Vector2f(0.0f, 0.0f);

	int top[7] = { 12,6,8,11,2,3,5 };
	int right[7] = { 13,7,8,9,2,3,4 };
	int bottom[7] = { 14,6,9,10,3,4,5 };
	int left[7] = { 15,7,10,11,2,4,5 };
	int counter = 0;

	vector<Room> dungeonRooms;
	vector<vector<Room>> layout;
	vector<vector<Enemy>> enemyLayout;

};

