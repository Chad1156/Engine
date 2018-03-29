#include "Engine.h"
#include "Scene.h"
#include <iostream>
#include "SystemManager.h"
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;




namespace core {

	Engine::Engine(scene::Scene* s) :
		mainScene(s),
		isRunning(false)
	{

		managers.push_back(SystemManager::getInstance());

	}


	Engine::~Engine()
	{
	}

	int Engine::Init() {

		int initResult = 0;

		//Initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

			initResult = ENGINE_INIT_ERROR;

		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

				initResult = ENGINE_INIT_ERROR;
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);

				//Wait two seconds
				//SDL_Delay(20000);
			}
		}

		mainScene->Init();

		return initResult;

	}

	int Engine::run() {

		isRunning = true;


		while (!inputSystem.RequestedQuit()) {

			//update
			Update();
			//render
			Draw();

		}

		return ShutDown();

	}

	void Engine::print() {

		std::cout << "This is a test" << std::endl;

	}

	void Engine::Update() {

		mainScene->Update();

		inputSystem.Update();

		//Fill the surface white
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xf46036, 0xFF, 0xFF));

		//Update the surface
		SDL_UpdateWindowSurface(window);


	}

	void Engine::Draw() const {

		mainScene->Draw();

	}

	int Engine::ShutDown() {

		if (mainScene->Shutdown()) {

			return 1;

		}

		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();
		return 0;

	}


}
