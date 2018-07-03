#pragma once

#include "FileSystem.h"

class MyFileSystem : public FileSystem
{
public:
	MyFileSystem(std::unique_ptr<MapLoader> mapLoader);
	~MyFileSystem();

	std::unique_ptr<std::string> readFile(const std::string& fileName);
};

