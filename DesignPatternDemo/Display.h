#pragma once

#include "MapAreaInterface.h"
#include <memory>

class Display
{
public:
	Display();
	virtual ~Display();

	std::vector<MyObjectDisplayData*> getDisplayData();

	void init(MapAreaInterface* const mapAreaInterface);

	virtual void start() = 0;
	virtual void draw() = 0;
	virtual void initObjects(std::vector<MyObjectDisplayData*>* objects) = 0;
	virtual void loadTexture(std::vector<MyObjectDisplayData*>* objects) = 0;
	virtual void addObjectToRender(MyObjectDisplayData* object) = 0;
	virtual void addObjectsToRender(std::vector<MyObjectDisplayData*>* objects) = 0;

private:
	MapAreaInterface* _mapAreaInterface;
};

