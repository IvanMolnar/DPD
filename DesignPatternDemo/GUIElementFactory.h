#pragma once

#include "GenericFactory.h"
#include "GUIElement.h"

class GUIElementFactory : public GenericFactory<GUIElementType, GUIElement>
{

};