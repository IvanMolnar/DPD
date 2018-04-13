#include "MyMapLoader.h"



MyMapLoader::MyMapLoader()
{
}


MyMapLoader::~MyMapLoader()
{
}

void MyMapLoader::parse(std::unique_ptr<std::string>& data)
{
	/*
	parseTile(data);
	parseGameObject(data);

	for (auto& object : result)
	{

	}*/

}

std::vector<std::unique_ptr<GameObject>> MyMapLoader::parseGameObject(std::unique_ptr<std::string>& data)
{
	std::vector<std::unique_ptr<GameObject>> result;

	//parse data


	//test

	result.push_back(std::move(createGameObject(GameObjectType::Player)));
	result.push_back(std::move(createGameObject(GameObjectType::Enemy)));


	return result;
}

std::vector<std::unique_ptr<Tile>> MyMapLoader::parseTile(std::unique_ptr<std::string>& data)
{
	std::vector<std::unique_ptr<Tile>> result;

	//parse data


	//test

	result.push_back(createTile(TileType::Grass));


	return result;
}