#pragma once

#include "Display.h"

#include "../../../../2D_Engine/2D_Engine/2D_Engine.h"

class MyDisplayExample : public Display
{
public:
	MyDisplayExample();
	~MyDisplayExample();

	void start() override;
	void draw() override;

	void initObjects(std::vector<MyObjectDisplayData*>* objects) override;
	void loadTexture(std::vector<MyObjectDisplayData*>* objects) override;

	void addObjectToRender(MyObjectDisplayData* object) override;
	void addObjectsToRender(std::vector<MyObjectDisplayData*>* objects) override;

private:

	GraphicEngineInterface* _graphicEngineInterface;

	HINSTANCE _dllHandle;

	std::vector<MyObjectDisplayData*> _displayData;
};