#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"

class Hazard
{
public:
	Hazard(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float damage);
	~Hazard();
	void Draw(sf::RenderWindow& window);
	float getDamage() 
	{
		return damage;
	}

	Collider getCollider()
	{
		return Collider(body);
	}

private:
	sf::RectangleShape body;
	float damage;
};

