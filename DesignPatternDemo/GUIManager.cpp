#include "GUIManager.h"

#include "GUIElementFactory.h"


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