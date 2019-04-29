#include "Projectile.h"


Projectile::Projectile(sf::Texture* texture, sf::Vector2f size, float speed, float damage, float fireRate)
{
	this->speed = speed;
	this->damage = damage;
	this->fireRate = fireRate;
	body.setSize(size);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
	lifeTime = speed;
}
Projectile::Projectile()
{
}
Projectile::~Projectile()
{
}

void Projectile::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.x += startDirection.x * speed * deltaTime;
	movement.y += startDirection.y * speed * deltaTime;
	
	body.move(movement);
	lifeTime--;
}

void Projectile::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
