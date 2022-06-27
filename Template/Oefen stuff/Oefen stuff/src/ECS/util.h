#pragma once
#include <array>
#include <bitset>
#include <memory>

/**
 * @brief Utilities for getting ID's and certain constexprs
 */

class Component;
class Entity;

namespace util
{
	typedef uint32_t EntityID;
	typedef uint32_t ComponentID;
	constexpr uint32_t MAX_ENTITIES = 10;
	constexpr uint32_t MAX_COMPONENTS = 32;

	using ComponentList = std::array<std::shared_ptr<Component>, MAX_ENTITIES>;
	using ComponentBitset = std::bitset<MAX_COMPONENTS>;


	inline EntityID getUniqueEntityID()
	{
		static EntityID lastID = 0u;
		return lastID++;
	}

	inline ComponentID getUniqueComponentID()
	{
		static ComponentID lastID = 0u;
		return lastID++;
	}

	template <typename T> ComponentID getUniqueComponentID() noexcept
	{
		//static_assert(std::is_base_of<Component, T>::value, "Provided component is not a derivative of the base!");
		static ComponentID typeID = getUniqueComponentID();
		return typeID;
	}
}
