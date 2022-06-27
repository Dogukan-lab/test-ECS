#pragma once
#include <string>

#include "Component.h"

struct Transform : public Component
{
public:

	Transform(float posx, float posy) : posX(posx), posY(posy) {}

	~Transform() override = default;


	inline std::string posToString()
	{
		return "PosX: " + std::to_string(posX) + "  PosY: " + std::to_string(posY) + "\n";
	}

private:
	float posX;
	float posY;
};
