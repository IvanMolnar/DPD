#include "MyDisplayExample.h"

//test
#include <functional>

MyDisplayExample::MyDisplayExample() : _graphicEngineInterface(nullptr)
{
}


MyDisplayExample::~MyDisplayExample()
{
	_graphicEngineInterface->destroy();
	::FreeLibrary(_dllHandle);
}

void MyDisplayExample::start()
{
	HINSTANCE _dllHandle = ::LoadLibraryA(GraphicEngineModuleInfo::DllName);
	if (!_dllHandle)
	{
	//	cerr << "Unable to load DLL!\n";
	//	return 1;
	};

	FARPROC lpfnGetProcessID = ::GetProcAddress(_dllHandle, GraphicEngineModuleInfo::GetInstanceFunction);

	if (!lpfnGetProcessID)
	{
	//	cerr << "Unable to load create_klass from DLL!\n";
		::FreeLibrary(_dllHandle);
	//	return 1;
	}

	std::function<GraphicEngineInterface*(void)> getInstance(reinterpret_cast<GraphicEngineInterface*(__stdcall *)()>(lpfnGetProcessID));

	_graphicEngineInterface = getInstance();

	_graphicEngineInterface->init();
}

void MyDisplayExample::draw()
{
	auto displayData = getDisplayData();
	
	for (auto& data : displayData)
	{

	}

	_graphicEngineInterface->tick();
}
