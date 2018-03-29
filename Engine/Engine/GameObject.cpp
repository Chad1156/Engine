#include "GameObject.h"
#include "SDL.h"
#include <iostream>

namespace scene {

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

bool GameObject::Init() {

	return true;

}

void GameObject::Update() {




}

void GameObject::Draw() const {

	bool success = true;

	screenSurface == SDL_LoadBMP("animal.bmp");
	if (screenSurface == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", screenSurface, SDL_GetError());
		success = false;
	}
	
}

bool GameObject::Shutdown() {

	return true;

}


}


