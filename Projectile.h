#pragma once
#include "Animation.h"
#include "Collider.h"
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;

class Projectile
{
public:
	Projectile(sf::Texture* texture, sf::Vector2f size, float speed, float damage, float fireRate);
	Projectile();
	~Projectile();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void setStartDirection(sf::Vector2f startDirection)
	{
		this->startDirection = startDirection;
	}
	Collider getCollider()
	{
		return Collider(body);
	}

	int getLifetime()
	{
		return lifeTime;
	}

	sf::RectangleShape body;
	sf::Vector2f startDirection;
	sf::Vector2f position;

	//vector<Collider> proxColliders;

	float speed;
	float damage;
	float fireRate;
	int lifeTime;

};

