#pragma once

#include "ObjectModifierInterface.h"

class ObjectModifierVisitor
{
public:
	ObjectModifierVisitor() {};
	~ObjectModifierVisitor() {};

	// applying to object that is attacked
	// returns if enemy is alive
	virtual bool apply(ObjectModifierInterface* objectModifierInterface, array<float, 3> modifiers) = 0;

	// applying to object that is attacking
	virtual bool applySelf(ObjectModifierInterface* objectModifierInterface, array<float, 3> modifiers) = 0;
};

