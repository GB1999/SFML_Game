#include "Hazard.h"

Hazard::Hazard(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, float damage)
{
	body.setSize(size);
	body.setPosition(position);
	body.setTexture(texture);
	body.setOrigin(size / 2.0f);
	this->damage = damage;
}


Hazard::~Hazard()
{
}

void Hazard::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}


