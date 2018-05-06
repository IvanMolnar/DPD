#include "MyMapLoader.h"



MyMapLoader::MyMapLoader()
{
}


MyMapLoader::~MyMapLoader()
{
}

std::vector<std::shared_ptr<GameObject>> MyMapLoader::parseGameObject(std::vector<std::map<std::string, std::string>>& data)
{
	std::vector<std::shared_ptr<GameObject>> result;

	//parse data

	//neki switch da li je gameObject ili tile

	for (auto& chunk : data)
	{
		std::string value = chunk["Type"];

		GameObjectType type = GameObjectType::Enemy;

		if (value.size() > 0)
		{
			type = static_cast<GameObjectType>(std::stoi(value));
		}

		auto gameObject = createGameObject(type);
		gameObject->deserialize(chunk);
		result.push_back(std::move(gameObject));
	}


	//test
	/*
	auto player = createGameObject(GameObjectType::Player);
	player->_position.x = 0;
	player->_position.y = 0;

	player->_dimension.w = 50;
	player->_dimension.h = 50;

	player->texturePath = "player.png";

	result.push_back(std::move(player));

	auto enemy = createGameObject(GameObjectType::Enemy);
	enemy->_position.x = 2;
	enemy->_position.y = 1;

	enemy->_dimension.w = 50;
	enemy->_dimension.h = 50;

	enemy->texturePath = "enemy.png";

	result.push_back(std::move(enemy));*/

	return result;
}