#pragma once

#include "Factories\GUIElementFactory.h"
#include "GUI\GUIElement.h"
#include "Utility\IniParser.h"

class GUIManager
{
public:
	GUIManager();
	virtual ~GUIManager();
	
	std::unique_ptr<GUIElement> GUIManager::createGUIElement(GUIElementType type);

	const std::vector<std::unique_ptr<GUIElement>> & getGUIElements();
	std::vector<MyObjectDisplayData*> getDisplayData();
	
	virtual void processMouseEvent(unsigned char clickType, int x, int y);

	virtual void createGUIElements(std::vector<std::map<std::string, std::string>>& data) = 0;
	virtual void loadGUI(std::string& guiFile) = 0;

protected:
	std::vector<std::unique_ptr<GUIElement>> _guiElements;
};

