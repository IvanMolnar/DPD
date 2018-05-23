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