#pragma once

#include "Factories\GenericFactory.h"
#include "GameObjects\GameObject.h"

class GameObjectFactory : public GenericFactory<GameObjectType, GameObject>
{

};