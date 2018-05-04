#include "MyMapLoader.h"



MyMapLoader::MyMapLoader()
{
}


MyMapLoader::~MyMapLoader()
{
}

std::vector<std::shared_ptr<GameObject>> MyMapLoader::parseGameObject(std::unique_ptr<std::string>& data)
{
	std::vector<std::shared_ptr<GameObject>> result;

	//parse data


	//test

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

	result.push_back(std::move(enemy));

	return result;
}

std::vector<std::shared_ptr<Tile>> MyMapLoader::parseTile(std::unique_ptr<std::string>& data)
{
	std::vector<std::shared_ptr<Tile>> result;

	//parse data


	//test
	int row = 0;
	int column = 0;
	for (int i = 0; i < 20; i++, column++)
	{
		std::shared_ptr<Tile> newTile = TileFactory::getInstance()->create(TileType::Grass);

		newTile->_position.x = column;
		newTile->_position.y = row;
		newTile->_dimension.w = 50;
		newTile->_dimension.h = 50;

		newTile->texturePath = "grass.png";

		result.push_back(newTile);

		if (column == 4)
		{
			column = -1;
			++row;
		}
	}


	return result;
}