#pragma once
#include "Animation.h"
#include "Collider.h"
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
class Weapon
{
public:
	Weapon(sf::Texture* texture, sf::Vector2f size, float damage, float swingRate);
	~Weapon();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void setPosition(sf::Vector2f playerPos) 
	{
		body.setPosition(playerPos + offset);
	}


	sf::RectangleShape body;
	sf::Vector2f offset;
	float swingRate;
	float damage;
};

