#include "MyGUIManager.h"



MyGUIManager::MyGUIManager()
{
}

MyGUIManager::~MyGUIManager()
{
}

void MyGUIManager::createGUIElement(chunk& chunkData)
{
	std::string value = chunkData.data["Type"];

	GUIElementType type = GUIElementType::button;

	if (value.size() > 0)
	{
		type = static_cast<GUIElementType>(std::stoi(value));
	}

	auto guiElement = GUIManager::createGUIElement(type);
	guiElement->deserialize(chunkData.data);
	_guiElements.push_back(std::move(guiElement));
}

void MyGUIManager::loadGUI(std::string& guiFile)
{
	IniParser iniParser;
	iniParser.readData(guiFile);

	for (auto& chunk : iniParser)
	{
		createGUIElement(chunk);
	}
}