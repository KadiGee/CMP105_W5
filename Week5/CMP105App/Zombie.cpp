#include "Zombie.h"

Zombie::Zombie()
{// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);
	setTextureRect(walk.getCurrentFrame());
}
Zombie::~Zombie()
{}

void Zombie::update(float dt) 
{
	if (input->isKeyDown(sf::Keyboard::Left) || input->isKeyDown(sf::Keyboard::Right))
	{
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
}

void Zombie::handleInput(float dt)
{

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		walk.setFlipped(false);
		velocity.x = 500;
		velocity.y = 0;
		move(velocity * dt);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		walk.setFlipped(true);
		velocity.x = 500;
		velocity.y = 0;
		move(-velocity * dt);

	}
}
