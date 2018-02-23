#include "MyMapLoader.h"



MyMapLoader::MyMapLoader()
{
}


MyMapLoader::~MyMapLoader()
{
}

std::vector<std::unique_ptr<GameObject>> MyMapLoader::parse(std::unique_ptr<std::string>& data)
{
	std::vector<std::unique_ptr<GameObject>> result;

	//parse data


	//test
	result.push_back(std::move(createGameObject(GameObjectTypes::typePlayer)));
	result.push_back(std::move(createGameObject(GameObjectTypes::typeEnemy)));


	return result;
}
