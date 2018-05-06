#pragma once

#include <string>
#include <map>

class Serializer
{
public:
	virtual std::map<std::string, std::string> serialize() = 0;
	virtual void deserialize(std::map<std::string, std::string>& data) = 0;
};