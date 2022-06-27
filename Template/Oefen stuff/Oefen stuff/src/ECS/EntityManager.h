#pragma once
#include <vector>
#include "Entity.h"

struct EntityManager
{
public:

	/*
	 * TODO: Have a generic add method for derivatives of @Entity
	 * TODO: Have a generic get method for derivatives of @Entity
	 * TODO: Have a generic delete/destroy method for derivatives of @Entity
	 */

	std::vector<std::unique_ptr<Entity>> entities;


	//void makeEntities()
	//{
	//	for (int i = 0; i < util::MAX_ENTITIES; i++)
	//	{
	//		auto ptr = std::make_unique<Entity>();
	//		this->entities.push_back(std::move(ptr));
	//	}
	//}

	/**
	 * Sets the list of entities up with w/a standard size 
	 */
	EntityManager()
	{
		entities.reserve(util::MAX_ENTITIES + 1);
	}

	~EntityManager()
	{
		this->entities.clear();
	}

	/**
	 * @brief generic add function for adding entities to the manager
	 */
	template <typename T>
	T& addEntity()
	{
		static_assert(std::is_base_of<Entity, T>::value && "Provided entity is not derivative of Entity!");
		T* entity(new T());
		auto ptr = std::make_unique<T>(*entity);
		this->entities.push_back(std::move(ptr));
		return *entity;
	}

	/**
	 * @see original @addEntity()
	 * Overloaded function to pass args as well
	 */
	template <typename T, typename... TArgs>
	T& addEntity(TArgs&&... args)
	{
		static_assert(std::is_base_of<Entity, T>::value && "Provided entity is not derivative of Entity!");
		T* entity(new T(std::forward<TArgs>(args)...));
		auto ptr = std::make_unique<T>(*entity);
		this->entities.push_back(std::move(ptr));

		return *entity;
	}


	/**
	 * TODO Make this function pass an @Entity id instead
	 */

	std::unique_ptr<Entity> destroyEntity(const Entity& entity)
	{
		//static_assert(std::is_base_of<Entity, T>::value && "Provided entity is not derivative of Entity!");

		const auto it = std::find_if(
			this->entities.begin(), 
			this->entities.end(), 
			[&](const std::unique_ptr<Entity>& obj) 
							{ return obj->entityID == entity.entityID; });

		if (it != this->entities.end()) {
			auto retval = std::move(*it);
			this->entities.erase(it);
			return std::move(retval);
		}

		return nullptr;
	}

	std::vector<std::unique_ptr<Entity>>& getEntities()
	{
		return this->entities;
	}

	Entity& getEntity(const int& index) const
	{
		return *this->entities.at(index);
	}

	void update()
	{
		for(const auto& entity : this->entities)
		{
			entity->update();
		}
	}
};
