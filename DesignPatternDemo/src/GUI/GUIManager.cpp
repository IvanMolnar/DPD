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

void GUIManager::processMouseEvent(unsigned char clickType, int x, int y)
{
	for (auto& guiElement : _guiElements)
	{
		if (x >= guiElement->_position.x && y >= guiElement->_position.y &&
			 x <= (guiElement->_position.x + guiElement->_dimension.w) && y <= (guiElement->_position.y + guiElement->_dimension.h))
		{

			// move event
			if (clickType <= 0)
			{
				if (guiElement->_mouseIsInside == false)
				{
					guiElement->_mouseIsInside = true;
					guiElement->onMouseEnter();
				}
				
			}
			// click event
			// for now we don't care if it was double click
			else
			{
				guiElement->onClick();
			}

		}
		// we check for mouse leave event
		else
		{
			if (guiElement->_mouseIsInside)
			{
				guiElement->_mouseIsInside = false;
				guiElement->onMouseLeave();
			}
		}
	}
}