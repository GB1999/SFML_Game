#include "Wall.h"



Wall::Wall(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, bool hasCollider)
{
	body.setSize(size);
	body.setPosition(position);
	body.setTexture(texture);
	body.setOrigin(size / 2.0f);

	this->hasCollider = hasCollider;
}
Wall::Wall()
{
	body.setSize(sf::Vector2f(0.0f,0.0f));
	body.setPosition(sf::Vector2f(0.0f, 0.0f));
	body.setTexture(nullptr);
	body.setOrigin(sf::Vector2f(0.0f, 0.0f));
}


Wall::~Wall()
{
}

void Wall::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}
