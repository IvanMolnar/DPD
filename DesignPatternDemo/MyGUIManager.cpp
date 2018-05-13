#include "MyGUIManager.h"

#include "GUIButton.h"

MyGUIManager::MyGUIManager()
{
	GUIElementFactory::getInstance()->registerInstance<GUIButton>(GUIElementType::button);
}

MyGUIManager::~MyGUIManager()
{
}

void MyGUIManager::createGUIElements(std::vector<std::map<std::string, std::string>>& data)
{

	for (auto& chunk : data)
	{
		std::string value = chunk["Type"];

		GUIElementType type = GUIElementType::button;

		if (value.size() > 0)
		{
			type = static_cast<GUIElementType>(std::stoi(value));
		}

		auto guiElement = GUIManager::createGUIElement(type);
		guiElement->deserialize(chunk);
		_guiElements.push_back(std::move(guiElement));
	}
}

void MyGUIManager::loadGUI(std::string& guiFile)
{
	IniParser iniParser;

	std::string guiDatabaseFile = "GuiDatabase.ini";

	std::vector<std::map<std::string, std::string>> dataChunks = iniParser.getObjectData(guiFile, guiDatabaseFile);

	createGUIElements(dataChunks);
}