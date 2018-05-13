#include "MyInputExample.h"
#include "../../2D_Engine/2D_Engine/InputInterface.h"

#include <functional>

MyInputExample::MyInputExample() : Input ()
{
	Input::addInputAction(inputAction(SDL_Scancode::SDL_SCANCODE_W, "North", Events::walk, Directions::North, GameStates::Unchanged, 0, 0));
	Input::addInputAction(inputAction(SDL_Scancode::SDL_SCANCODE_S, "South", Events::walk, Directions::South, GameStates::Unchanged, 0, 0));
	Input::addInputAction(inputAction(SDL_Scancode::SDL_SCANCODE_A, "West", Events::walk, Directions::West, GameStates::Unchanged, 0, 0));
	Input::addInputAction(inputAction(SDL_Scancode::SDL_SCANCODE_D, "East", Events::walk, Directions::East, GameStates::Unchanged, 0, 0));
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

unsigned int MyInputExample::waitForInput()
{
	SDL_Event* event = _inputInterface->getInput();

	if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		return event.button;
	}
	else if (event->type == SDL_KEYDOWN)
	{
		return event->key.keysym.scancode;
	}

	return 0;
}
