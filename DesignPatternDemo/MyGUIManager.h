#pragma once

#include "GUIManager.h"

class MyGUIManager : public GUIManager
{
public:
	MyGUIManager();
	~MyGUIManager();

	void loadGUI(std::string& guiFile) override;

private:
	

	void createGUIElements(std::vector<std::map<std::string, std::string>>& data) override;

};

