#include "GUIManager.h"

GUIManager::GUIManager()
{
}

GUIManager::~GUIManager()
{
}

std::unique_ptr<GUIElement> GUIManager::createGUIElement(GUIElementType type)
{
	return GUIElementFactory::getInstance()->create(type);
}

std::vector<std::unique_ptr<GUIElement>> const & GUIManager::getGUIElements()
{
	return _guiElements;
}

std::vector<MyObjectDisplayData*> GUIManager::getDisplayData()
{
	std::vector<MyObjectDisplayData*> result;

	for (auto& data : _guiElements)
	{
		result.push_back(static_cast<MyObjectDisplayData*>(data.get()));
	}

	return result;
}