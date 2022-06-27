#pragma once
#include "Entity.h"

struct Enemy : public Entity
{
	size_t health;
	size_t attack;
};