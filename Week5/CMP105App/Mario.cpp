#include "Mario.h"
Mario::Mario()
{// Setup walk animation.  //left top width height
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));


	duck.addFrame(sf::IntRect(0, 41, 16, 20));





	walk.setFrameSpeed(1.f / 10.f);
	setTextureRect(walk.getCurrentFrame());
}
Mario::~Mario()
{}

void Mario::update(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Left) || input->isKeyDown(sf::Keyboard::Right))
	{
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
		setTextureRect(duck.getCurrentFrame());
		duck.setLooping(false);
	}

}

void Mario::handleInput(float dt)
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