#include "stdafx.h"
#include "IniParser.h"


#include <memory>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 

IniParser::IniParser()
{
}


IniParser::~IniParser()
{
}

void IniParser::open(std::string filePath)
{
	if (_stream.is_open())
	{
		_stream.close();
	}

	_currentLine = 0;
	_loadedFile.clear();
	_stream.open(filePath);

	std::string line;

	while (_stream >> line)
	{
		_loadedFile.push_back(line);
	}

	_stream.close();
}

void IniParser::setData(std::string fileData)
{
	_currentLine = 0;
	_loadedFile.clear();

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