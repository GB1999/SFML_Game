#include "Enemy.h"



Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f spawnPos, Projectile projectile, float switchTime, int type) :
	animation(texture, imageCount, switchTime)
{
	active = false;
	speed = 200.0f;
	currentSpeed = speed;
	EnemyProjectile = projectile;
	
	timeDelay = 0;
	row = 0;
	faceRight = true;
	damage = 10;
	if (type == 1)
	{
		health = 300;
		speed = 50;
		body.setSize(sf::Vector2f(200.0f, 200.0f));
		
	}
	if (type == 2)
	{
		health = 100;
		body.setSize(sf::Vector2f(75.0f, 75.0f));
	}

	if (type == 3)
	{
		health = 50;
		speed = 200;
		body.setSize(sf::Vector2f(50.0f, 50.0f));
	}

	this->type = type;

	body.setOrigin(body.getSize() / 2.0f);
	//body.setPosition(spawnPos);
	body.setTexture(texture);
}

void Enemy::Update(float deltaTime, Player player)
{
	float xDif = player.getPostition().x - body.getPosition().x;
	float yDif = player.getPostition().y - body.getPosition().y;
	timeDelay += deltaTime;

	if (active)
	{
		// Enemy type 1, chases the player
		if (type == 1)
		{
			currentSpeed = speed;
			//summation of time between frames
			movement = sf::Vector2f(0.0f, 0.0f);

			//if Player is above enemy --> set movement direction up
			if (yDif < -100 && abs(yDif) > abs(xDif))
			{
				direction = sf::Vector2f(0.0f, -1.0f);
				movement.y -= currentSpeed * deltaTime;
			}
			//if player is to the right of enemy
			else if (xDif > 100 && abs(xDif) > abs(yDif))
			{
				direction = sf::Vector2f(1.0f, 0.0f);
				movement.x += currentSpeed * deltaTime;

			}
			//if player is to the left of enemy
			else if (xDif < -100 && abs(xDif) > abs(yDif))
			{
				direction = sf::Vector2f(-1.0f, 0.0f);
				movement.x -= currentSpeed * deltaTime;
			}
			//if player is below enemy
			else if (yDif > 100 && abs(yDif) > abs(xDif))
			{
				direction = sf::Vector2f(0.0f, 1.0f);
				movement.y += currentSpeed * deltaTime;
			}

			else if (movement.x != 0)
			{
				row = 1;
				if (movement.x > 0.0f)
				{
					faceRight = true;
				}
				else
				{
					faceRight = false;
				}
			}
			else if (movement.y != 0)
			{
				if (movement.y > 0.0f)
				{
					row = 2;
					faceUp = true;
				}
				else
				{
					row = 4;
					faceUp = false;
				}
			}
		}

		// Enemy type 2, snipes the player from static location
		else if (type == 2)
		{
			float yCoordinate = yDif / (sqrt(pow(xDif, 2) + pow(yDif, 2)));
			float xCoordinate = xDif / (sqrt(pow(xDif, 2) + pow(yDif, 2)));

			if (timeDelay >= EnemyProjectile.fireRate)
			{
				timeDelay = 0;
				projectiles.push_back(EnemyProjectile);
				projectiles.back().body.setPosition(body.getPosition());
				projectiles.back().setStartDirection(sf::Vector2f(xCoordinate, yCoordinate));
			}
			if (timeDelay <= pause)
			{
				currentSpeed = 0;
			}
		}

		// Enemy type 3, charges the enemy after a countdown
		else if (type == 3)
		{
			row = 0;
			float yCoordinate = yDif / (sqrt(pow(xDif, 2) + pow(yDif, 2)));
			float xCoordinate = xDif / (sqrt(pow(xDif, 2) + pow(yDif, 2)));

			if (timeDelay >= chargeTime)
			{
				steps += 1;
				direction = sf::Vector2f(xCoordinate, yCoordinate);
				movement.x += direction.x * speed * deltaTime;
				movement.y += direction.y * speed * deltaTime;
				if (steps >= 30)
				{
					steps = 0;
					timeDelay = 0;
				}
			}
			else
			{
				movement.x = 0;
				movement.y = 0;
			}


		}
	}
	
	

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}
void Enemy::updateProjectiles(float deltaTime)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Update(deltaTime);
		if (projectiles[i].lifeTime <= 0)
		{
			projectiles.erase(projectiles.begin()+i);
		}
	}
}
void Enemy::takeDamage(float damage)
{
	health -= damage;
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
void Enemy::drawProjectiles(sf::RenderWindow& window)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Draw(window);
	}
}
void Enemy::setActive()
{
	active = true;
}
Enemy::~Enemy()
{
}
