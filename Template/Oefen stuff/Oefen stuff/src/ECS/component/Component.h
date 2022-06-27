#pragma once
#include <iostream>
#include <memory>

class Entity;

class Component
{
public:
	Entity* entity;

	Component()
	{
		entity = nullptr;
		std::cout << "Component created" << std::endl;
	}

	virtual ~Component()
	{
		std::cout << "Component deconstructed" << std::endl;
	}

	virtual void init()
	{
		std::cout << "Component created!" << std::endl;
	}
};
