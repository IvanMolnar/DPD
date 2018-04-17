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

	player->_objectRect.updateDimenstion(player->_dimension);
	player->_objectRect.updatePosition(player->_position);

	player->texturePath = "player.png";

	result.push_back(std::move(player));

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
		newTile->_objectRect.updateDimenstion(newTile->_dimension);
		newTile->_objectRect.updatePosition(newTile->_position);

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