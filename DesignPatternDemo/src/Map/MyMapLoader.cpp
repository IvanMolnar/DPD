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

	return result;
}