#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H
#include "SDL.h"
#include "InputSystem.h"
#include "SystemManager.h"
#include "Manager.h"

#include <vector>

#define ENGINE_INIT_ERROR 1
#define ENGINE_SHUTDOWN_ERROR 2

//const int SCREEN_WIDTH = 620;
//const int SCREEN_HEIGHT = 480;

namespace scene {

	class Scene;

}

namespace core {

	class Engine
	{
	private:
		bool isRunning;
		std::vector<Manager*> managers;

		scene::Scene* mainScene;

		//The window we'll be rendering to
		SDL_Window* window = NULL;

		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;

		InputSystem inputSystem;

	public:
		Engine(scene::Scene* s);
		~Engine();

		int Init();
		int run();
		void print();
	private:
		void Update();
		void Draw() const;
		int ShutDown();
	};

}

#endif // !_ENGINE_H

