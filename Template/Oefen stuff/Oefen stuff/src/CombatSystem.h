#pragma once
#include <vector>

#include "Entity.h"

/**
 * A system that will check 
 */
struct CombatSystem
{
	std::vector<std::unique_ptr<Entity>> entities;

	CombatSystem(const std::vector<std::unique_ptr<Entity>>& entities)
	{
		this->entities = entities;
		std::cout << "System created! " << std::endl;
	}


	void attack()
	{
		for(auto& entity : this->entities)
		{
			
		}
	}
};
