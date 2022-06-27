#pragma once

#include "Entity.h"

/**
 * @brief Player class for doing combat and displaying itself
 */
struct Player : public Entity
{
public:
	float health;
	float attack;
	std::string name;

	Player() = default;

	explicit Player(const std::string& name)
	{
		health = 100;
		attack = 5;
		this->name = name;
	}

	~Player() override
	{
		std::cout << "Player destroyed: " << name << std::endl;
	}

	void update() override
	{
		std::cout << "Player: "<< this->name <<  " Attacking: " << this->attack << '\n';
	}
};