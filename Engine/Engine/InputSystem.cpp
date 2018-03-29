#include "InputSystem.h"

namespace core {

	InputSystem::InputSystem() :
		System(SystemType::INPUT),
		requestedQuit(false)
	{
	}


	InputSystem::~InputSystem()
	{
	}

	void InputSystem::Update() {

		SDL_Event e;

		while (SDL_PollEvent(&e) != 0)
		{
			//printf("TEST");

			switch (e.type)
			{
			case (SDL_KEYDOWN):
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					printf("UP");
					e_upPressed = true;
					break;

				case SDLK_DOWN:
					printf("DOWN");
					e_downPressed = true;
					break;

				case SDLK_RIGHT:
					printf("RIGHT");
					e_rightPressed = true;
					break;

				case SDLK_LEFT:
					printf("LEFT");
					e_leftPressed = true;
					break;

				case SDLK_ESCAPE:
					requestedQuit = true;
					break;
				}

				//printf("You pressed something");
				//break;

			case (SDL_KEYUP):
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					e_leftPressed = false;
					printf("Up released");
					break;
				case SDLK_DOWN:
					e_leftPressed = false;
					printf("Down released");
					break;
				case SDLK_LEFT:
					e_leftPressed = false;
					printf("Left released");
					break;
				case SDLK_RIGHT:
					e_leftPressed = false;
					printf("Right released");
					break;
				}

			default:
				break;
			}

		}
	}
}
