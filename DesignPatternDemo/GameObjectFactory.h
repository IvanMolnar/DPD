#pragma once

#include "GenericFactory.h"
#include "GameObject.h"

class GameObjectFactory : public GenericFactory<GameObjectType, GameObject>
{

};