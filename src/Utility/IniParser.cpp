#include "Utility\IniParser.h"
#include "Log\Log.h"

#include <memory>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 

static const std::string __namespace__ = "IniParser";

IniParser::IniParser()
{
}


IniParser::~IniParser()
{
}

void IniParser::readData(std::string filePath)
{
	if (_stream.is_open())
	{
		_stream.close();
	}

	_currentLine = 0;
	_loadedFile.clear();
	parsedChunks.clear();

	_stream.open(filePath);

	std::string line;

	while (_stream >> line)
	{
		_loadedFile.push_back(line);
	}

	_stream.close();

	parseAllData();
}

void IniParser::setData(std::string fileData)
{
	_currentLine = 0;
	_loadedFile.clear();
	parsedChunks.clear();

	size_t pos = fileData.find('\n');

	while (pos != std::string::npos)
	{
		std::string substr = fileData.substr(0, pos);

		if (substr.size() > 2)
		{
			_loadedFile.push_back(substr);
		}
		
		fileData = fileData.substr(pos + 1);
		pos = fileData.find('\n');
	}

	if (fileData.size() > 2)
	{
		_loadedFile.push_back(fileData);
	}

	parseAllData();
}

bool IniParser::isNewSection(std::string& data)
{
	return (data.size() > 1) && (data[0] == '[');
}

chunk IniParser::getNextChunk()
{
	chunk result;
	bool inSection = false;

	for (; _currentLine < _loadedFile.size(); ++_currentLine)
	{
		std::string line = _loadedFile[_currentLine];

		if (inSection == false)
		{
			if (isNewSection(line))
			{
				result.sectionName = line.substr(1).substr(0, line.size() - 2);
				inSection = true;
			}
		}
		else
		{
			if (isNewSection(line) == false)
			{
				size_t pos = line.find("=");
				std::string key = line.substr(0, pos);
				std::string value = line.substr(pos + 1);

				result.data[key] = value;
			}
			else
			{
				--_currentLine;
				return result;
			}
		}
	}

	return result;
}

void IniParser::parseAllData()
{
	chunk data = getNextChunk();

	while (data.sectionName.size() > 0)
	{
		parsedChunks.push_back(data);
		data = getNextChunk();
	}
}

std::vector<chunk>::iterator IniParser::begin()
{
	return parsedChunks.begin();
}

std::vector<chunk>::iterator IniParser::end()
{
	return parsedChunks.end();
}

std::vector<std::map<std::string, std::string>> IniParser::getObjectData(std::string& data, std::string& databaseFile, bool fromFile)
{
	std::vector<std::map<std::string, std::string>> result;

	std::vector<chunk> mapInfo;

	if (fromFile)
	{
		readData(data);
	}
	else
	{
		setData(data);
	}
	

	for (auto& dataChunk : parsedChunks)
	{
		mapInfo.push_back(dataChunk);
	}

	readData(databaseFile);
	std::vector<chunk> ObjectDatabase;

	for (auto& dataChunk : parsedChunks)
	{
		ObjectDatabase.push_back(dataChunk);
	}

	for (auto& chunk : mapInfo)
	{
		bool foundInDatabase = false;

		for (auto& chunkDatabase : ObjectDatabase)
		{
			if (chunk.sectionName == chunkDatabase.sectionName)
			{
				std::map<std::string, std::string> objectForLoading;

				objectForLoading = chunkDatabase.data;

				for (auto& map : chunk.data)
				{
					objectForLoading[map.first] = map.second;
				}

				result.push_back(objectForLoading);

				foundInDatabase = true;

				break;
			}
		}

		if (foundInDatabase == false)
		{
			WRITE_LOG_WARNING("Object " + chunk.sectionName + " was not found in database");
		}

	}

	return result;
}