#include "Weapon.h"



Weapon::Weapon(sf::Texture* texture, sf::Vector2f size, float damage, float swingRate)
{
	this->damage = damage;
	this->swingRate = swingRate;
	body.setSize(size);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
}


Weapon::~Weapon()
{
}
void Weapon::Update(float deltaTime)
{

}
void Weapon::Draw(sf::RenderWindow& window)
{

}


