#pragma once
#include <iostream>
#include "util.h"
#include "Component.h"

/**
 * @class Base class for every entity within the structure
 */
class Entity
{
public:

	uint32_t entityID;

	std::vector<std::shared_ptr<Component>> components;

	util::ComponentBitset componentBitset;
	util::ComponentList componentList;

	Entity()
	{
		entityID = util::getUniqueEntityID();
		components.reserve(util::MAX_COMPONENTS);
		std::cout << "Entity with id: " << entityID << " created! " << std::endl;
	}

	virtual ~Entity()
	{
		std::cout << "Entity destructed with id:  " << entityID << std::endl;
	}

	template <typename T>
	bool hasComponent() const
	{
		return this->componentBitset[util::getUniqueComponentID<T>()];
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... args)
	{
		T* component(new T(std::forward<TArgs>(args)...));

		component->entity = this;
		auto ptr = std::make_shared<T>(*component);
		this->components.push_back(ptr);

		this->componentList[util::getUniqueComponentID<T>()] = ptr;
		this->componentBitset[util::getUniqueComponentID<T>()] = true;

		component->init();
		return *component;
	}

	//template <typename T>
	//T& addComponent()
	//{
	//	T* component(new T());

	//	component->entity = this;
	//	auto ptr = std::make_shared<T>(*component);
	//	this->components.push_back(ptr);

	//	this->componentList[util::getUniqueComponentID<T>()] = ptr;
	//	this->componentBitset[util::getUniqueComponentID<T>()] = true;

	//	component->init();
	//	return *component;
	//}

	template <typename T>
	T& getComponent() const
	{
		static_assert(std::is_base_of<Component, T>::value && "Component is not a derived class");
		auto ptr = std::make_shared<T>(this->componentList[util::getUniqueComponentID<T>()]);

		return *ptr;
	}

	virtual void update() = 0;
};
