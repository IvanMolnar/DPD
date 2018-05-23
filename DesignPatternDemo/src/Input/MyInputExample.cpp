#include "MyInputExample.h"

#include <functional>

MyInputExample::MyInputExample() : Input ()
{
	Input::addInputAction(inputAction(SDL_Scancode::SDL_SCANCODE_W, Events::walk, Directions::North));
	Input::addInputAction(inputAction(SDL_Scancode::SDL_SCANCODE_S, Events::walk, Directions::South));
	Input::addInputAction(inputAction(SDL_Scancode::SDL_SCANCODE_A, Events::walk, Directions::West));
	Input::addInputAction(inputAction(SDL_Scancode::SDL_SCANCODE_D, Events::walk, Directions::East));
}

MyInputExample::~MyInputExample()
{
	_inputInterface->destroy();
	::FreeLibrary(_dllHandle);
}

void MyInputExample::init()
{
	_dllHandle = ::LoadLibraryA(InputModuleInfo::DllName);
	if (!_dllHandle)
	{
		//	cerr << "Unable to load DLL!\n";
		//	return 1;
	};

	FARPROC lpfnGetProcessID = ::GetProcAddress(_dllHandle, InputModuleInfo::GetInstanceFunction);

	if (!lpfnGetProcessID)
	{
		//	cerr << "Unable to load create_klass from DLL!\n";
		::FreeLibrary(_dllHandle);
		//	return 1;
	}

	std::function<InputInterface*(void)> getInstance(reinterpret_cast<InputInterface*(__stdcall *)()>(lpfnGetProcessID));

	_inputInterface = getInstance();
}

SDL_Event* MyInputExample::waitForInput()
{
	SDL_Event* event = _inputInterface->getInput();

	return event;
}
