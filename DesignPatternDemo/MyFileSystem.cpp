#include "MyFileSystem.h"



MyFileSystem::MyFileSystem(std::unique_ptr<MapLoader> mapLoader) :
	FileSystem(std::move(mapLoader))
{
}


MyFileSystem::~MyFileSystem()
{
}

std::unique_ptr<std::string> MyFileSystem::readFile(const std::string& fileName)
{
	std::ifstream reader(fileName);
	std::stringstream buffer;
	buffer << reader.rdbuf();
	reader.close();

	return std::unique_ptr<std::string>(new std::string(buffer.str()));
}

/*
std::unique_ptr<MapArea> MyFileSystem::loadMapArea(const std::string& areaName)
{
	std::ifstream reader(areaName);
	std::stringstream buffer;
	buffer << reader.rdbuf();
	reader.close();

	std::unique_ptr<std::string> strResult = std::unique_ptr<std::string>(new std::string(buffer.str()));

	std::unique_ptr<MapArea> result = std::unique_ptr<MapArea>(new MapArea(strResult));

}*/