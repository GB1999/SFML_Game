#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"
class Wall
{
public:
	Wall(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, bool hasCollider);
	Wall();
	~Wall();

	void Draw(sf::RenderWindow& window);

	Collider getCollider()
	{
		return Collider(body);
	}

	sf::RectangleShape getBody()
	{
		return body;
	}

	bool getcolliderState()
	{
		return hasCollider;
	}

private:
	sf::RectangleShape body;
	bool hasCollider;

};

