#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Projectile.h"
using namespace std;

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f spawnPos, Projectile projectile, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void updateProjectiles(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void drawProjectiles(sf::RenderWindow& window);
	void takeDamage(float damage);
	void addScore(float score);
	void bump();
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
	vector<Projectile> projectiles;
private:
	sf::RectangleShape body;
	Animation animation;
	Projectile playerProjectile;
	

	sf::Vector2f direction;
	unsigned int row;
	float speed;
	float currentSpeed;
	float pause = .2f;
	float health = 100;
	float score;
	float timeDelay;

	bool faceRight;
	bool faceUp;




};

