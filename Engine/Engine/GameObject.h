#pragma once
#include "SDL.h"

namespace scene {

class GameObject
{
public:

	SDL_Surface * screenSurface = NULL;

	GameObject();
	virtual ~GameObject();
	bool Init();
	void Update();
	void Draw() const;
	bool Shutdown();
};

}

