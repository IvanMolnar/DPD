#pragma once

#include "../../2D_Engine/2D_Engine/MyObjectDisplayData.h"
#include "Serializer.h"

enum class GUIElementType
{
	button
};

class GUIElement : public MyObjectDisplayData, public Serializer
{
public:
	GUIElement(void* gameLogicInterface);
	virtual ~GUIElement();

	virtual void onPress() = 0;
	virtual void update(void* data) = 0;

	std::map<std::string, std::string> serialize();
	void deserialize(std::map<std::string, std::string>& data);

protected:
	GUIElementType _type;

};