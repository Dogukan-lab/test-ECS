#include "EntityManager.h"
#include "Player.h"
#include "Transform.h"

int main()
{
	EntityManager manager;

	auto& entity = manager.addEntity<Player>("Test");

	entity.addComponent<Transform>(100.0f,100.0f);

	std::cout << "Position is: " << entity.getComponent<Transform>().posToString() << std::endl;

	/*const auto& w = manager.addEntity<Player>("Big dub the 2nd");
	const auto& walt = manager.addEntity<Player>("Walter the white man");
	const auto& henry = manager.addEntity<Player>("Henry Cavil");
	const auto& pieter = manager.addEntity<Player>("Pieter van de Kop Walter");
	const auto& jan = manager.addEntity<Player>("Jan oost indonesisch");*/
}
