#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

struct chunk
{
	std::string sectionName;
	std::map<std::string, std::string> data;
};

class IniParser
{
public:
	IniParser();
	~IniParser();

	void readData(std::string filePath);
	void setData(std::string fileData);

	std::vector<std::map<std::string, std::string>> getObjectData(std::string& file, std::string& databaseFile, bool fromFile = true);

	std::vector<chunk>::iterator begin();
	std::vector<chunk>::iterator end();

private:
	std::ifstream _stream;
	unsigned int _currentLine;
	std::vector<std::string> _loadedFile;

	bool isNewSection(std::string& data);

	chunk getNextChunk();
	void parseAllData();

	std::vector<chunk> parsedChunks;
};

