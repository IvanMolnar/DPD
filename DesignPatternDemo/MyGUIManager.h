#pragma once

#include "GUIManager.h"

class MyGUIManager : public GUIManager
{
public:
	MyGUIManager();
	~MyGUIManager();

	void loadGUI(std::string& guiFile) override;

private:
	std::vector<std::unique_ptr<GUIElement>> _guiElements;

	void createGUIElement(chunk& chunkData) override;

};

