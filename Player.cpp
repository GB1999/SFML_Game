#include "Player.h"
#include <iostream>



Player::Player(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f spawnPos, Projectile projectile, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	currentSpeed = speed;
	playerProjectile = projectile;
	
	timeDelay = 0;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(75.0f, 75.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(spawnPos);
	body.setTexture(texture);
}

void Player::Update(float deltaTime)
{
	currentSpeed = speed;
	//summation of time between frames
	timeDelay += deltaTime;
	sf::Vector2f movement(0.0f, 0.0f);

	//if player is facing left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction = sf::Vector2f(-1.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeDelay >= playerProjectile.fireRate)
		{
			timeDelay = 0;
			projectiles.push_back(playerProjectile);
			projectiles.back().body.setPosition(body.getPosition());
			projectiles.back().setStartDirection(direction);
		}
		if(timeDelay <= pause)
		{
			currentSpeed = 0;
		}
		movement.x -= currentSpeed * deltaTime;
	}
	//if player is facing right
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = sf::Vector2f(1.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeDelay >= playerProjectile.fireRate)
		{
			timeDelay = 0;
			projectiles.push_back(playerProjectile);
			projectiles.back().body.setPosition(body.getPosition());
			projectiles.back().setStartDirection(direction);
		}
		if (timeDelay <= pause)
		{
			currentSpeed = 0;
		}
		movement.x += currentSpeed * deltaTime;

	}
	//if player is facing up
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{	
		direction = sf::Vector2f(0.0f, -1.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeDelay >= playerProjectile.fireRate)
		{
			timeDelay = 0;
			projectiles.push_back(playerProjectile);
			projectiles.back().body.setPosition(body.getPosition());
			projectiles.back().setStartDirection(direction);
		}
		if (timeDelay <= pause)
		{
			currentSpeed = 0;
		}
		movement.y -= currentSpeed * deltaTime;
	}
	//if player is facing down
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = sf::Vector2f(0.0f, 1.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeDelay >= playerProjectile.fireRate)
		{
			timeDelay = 0;
			projectiles.push_back(playerProjectile);
			projectiles.back().body.setPosition(body.getPosition());
			projectiles.back().setStartDirection(direction);
		}
		if (timeDelay <= pause)
		{
			currentSpeed = 0;
		}
		movement.y += currentSpeed * deltaTime;
	}

	//otherwise, if player is standing still
	if (movement.x == 0 && movement.y == 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timeDelay >= playerProjectile.fireRate)
		{
			timeDelay = 0;
			projectiles.push_back(playerProjectile);
			projectiles.back().body.setPosition(body.getPosition());
			projectiles.back().setStartDirection(sf::Vector2f(direction));
		}
	}

	else if(movement.x != 0)
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

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}
void Player::updateProjectiles(float deltaTime) 
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Update(deltaTime);
	}
}
void Player::takeDamage(float damage)
{
	health -=  damage;
	//bump();
	cout << "player health" << health << endl;
}
void Player::addScore(float score)
{
	this->score += score;
}
void Player :: bump()
{
	body.move(sf::Vector2f(100.0f, 100.0f));
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
void Player::drawProjectiles(sf::RenderWindow& window)
{
	for (int i = 0; i < projectiles.size(); i++)
	{
		projectiles[i].Draw(window);
	}
}

Player::~Player()
{
}
