#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Projectile.h"
#include "Player.h"
using namespace std;

class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f spawnPos, Projectile projectile, float switchTime, int type);
	~Enemy();

	
	void Update(float deltaTime, Player player);
	void updateProjectiles(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void drawProjectiles(sf::RenderWindow& window);
	void takeDamage(float damage);
	void setActive();

	sf::Vector2f getPostition()
	{
		return body.getPosition();
	}

	Collider getCollider()
	{
		return Collider(body);
	}

	float getHealth()
	{
		return health;
	}

	vector<Projectile> getProjectiles()
	{
		return projectiles;
	}
	float getDamage()
	{
		return damage;
	}

	void setPostion(sf::Vector2f startPos)
	{
		body.setPosition(startPos);
	}
	vector<Projectile> projectiles;

private:
	sf::RectangleShape body;
	Animation animation;
	Projectile EnemyProjectile;
	

	sf::Vector2f direction;
	sf::Vector2f movement;

	unsigned int row;
	float speed;
	float currentSpeed;
	float pause = .2f;
	float health;
	float timeDelay;
	float damage;
	float chargeTime = 3;
	float steps = 0;
	int type;

	bool faceRight;
	bool faceUp;
	bool active;
};

