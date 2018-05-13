#pragma once

#include "GUIElementFactory.h"
#include "GUIElement.h"
#include "IniParser.h"

class GUIManager
{
public:
	GUIManager();
	virtual ~GUIManager();
	
	std::unique_ptr<GUIElement> GUIManager::createGUIElement(GUIElementType type);

	const std::vector<std::unique_ptr<GUIElement>> & getGUIElements();
	std::vector<MyObjectDisplayData*> getDisplayData();

	virtual void createGUIElements(std::vector<std::map<std::string, std::string>>& data) = 0;
	virtual void loadGUI(std::string& guiFile) = 0;

protected:
	std::vector<std::unique_ptr<GUIElement>> _guiElements;
};

