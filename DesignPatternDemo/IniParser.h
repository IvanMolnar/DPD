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

	void open(std::string filePath);
	chunk getNextChunk();
	void setData(std::string fileData);

private:
	std::ifstream _stream;
	unsigned int _currentLine;
	std::vector<std::string> _loadedFile;

	bool isNewSection(std::string& data);

};

