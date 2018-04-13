#include "MyDisplayExample.h"

//test
#include <functional>

MyDisplayExample::MyDisplayExample() : _graphicEngineInterface(nullptr)
{
}


MyDisplayExample::~MyDisplayExample()
{
	// Destroy it explicitly
	_graphicEngineInterface->destroy();
	::FreeLibrary(_dllHandle);
}

void MyDisplayExample::start()
{
	// Load the DLL
	HINSTANCE _dllHandle = ::LoadLibraryA(GraphicEngineModuleInfo::DllName);
	if (!_dllHandle)
	{
	//	cerr << "Unable to load DLL!\n";
	//	return 1;
	};

	// Get the function from the DLL
//	std::function<GraphicEngineInterface*()> getInstance = reinterpret_cast<iklass_factory>(::GetProcAddress(dll_handle, "createInstance"));

	FARPROC lpfnGetProcessID = ::GetProcAddress(_dllHandle, GraphicEngineModuleInfo::GetInstanceFunction);

	if (!lpfnGetProcessID)
	{
	//	cerr << "Unable to load create_klass from DLL!\n";
		::FreeLibrary(_dllHandle);
	//	return 1;
	}

	std::function<GraphicEngineInterface*(void)> getInstance(reinterpret_cast<GraphicEngineInterface*(__stdcall *)()>(lpfnGetProcessID));

	// Ask the factory for a new object implementing the IKlass
	// interface
	_graphicEngineInterface = getInstance();

	// Play with the object
	_graphicEngineInterface->init();
}

void MyDisplayExample::draw()
{
	auto displayData = getDisplayData();
	
	for (auto& data : displayData)
	{

	}
}
