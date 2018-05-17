#include "GUIElement.h"


GUIElement::GUIElement(void* gameLogicInterface) : _mouseIsInside(false)
{
}

GUIElement::~GUIElement()
{
}

std::map<std::string, std::string> GUIElement::serialize()
{
	std::map<std::string, std::string> serializedData;

	MyObjectDisplayData* displayData = dynamic_cast<MyObjectDisplayData*>(this);

	serializedData["Type"] = static_cast<int>(_type);
	serializedData["Texture"] = displayData->texturePath;
	serializedData["DimensionH"] = displayData->_dimension.h;
	serializedData["DimensionW"] = displayData->_dimension.w;
	serializedData["PositionX"] = displayData->_position.x;
	serializedData["PositionY"] = displayData->_position.y;
	serializedData["DrawLayer"] = static_cast<int>(displayData->_drawLayer);

	return serializedData;
}

void GUIElement::deserialize(std::map<std::string, std::string>& data)
{
	MyObjectDisplayData* displayData = dynamic_cast<MyObjectDisplayData*>(this);

	_type = static_cast<GUIElementType>(std::stoi(data["Type"]));

	displayData->texturePath = data["Texture"];

	displayData->_dimension.h = std::stoi(data["DimensionH"]);
	displayData->_dimension.w = std::stoi(data["DimensionW"]);

	displayData->_position.x = std::stoi(data["PositionX"]);
	displayData->_position.y = std::stoi(data["PositionY"]);

	displayData->_drawLayer = DrawingLayer::UI;
}