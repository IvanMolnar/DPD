#pragma once

#include "ObjectModifier.h"

class Sword: public ObjectModifier
{
public:
	Sword();
	~Sword();

	bool apply(ObjectModifierInterface* objectModifierInterface, std::array<float, 3> modifiers);
	bool applySelf(ObjectModifierInterface* objectModifierInterface, std::array<float, 3> modifiers);
};

