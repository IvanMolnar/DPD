#pragma once

#include "GUIElement.h"
#include "IniParser.h"

class GUIManager
{
public:
	GUIManager();
	virtual ~GUIManager();
	
	std::unique_ptr<GUIElement> GUIManager::createGUIElement(GUIElementType type);

	virtual void createGUIElement(chunk& chunkData) = 0;
	virtual void loadGUI(std::string& guiFile) = 0;

};

