#pragma once

#include "ObjectModifier.h"

class Armor : public ObjectModifier
{
public:
	Armor();
	~Armor();

	bool apply(ObjectModifierInterface* objectModifierInterface, std::array<float, 3> modifiers);
	bool applySelf(ObjectModifierInterface* objectModifierInterface, std::array<float, 3> modifiers);
};

