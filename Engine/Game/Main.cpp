#include <iostream>
#include <Engine.h>
#include <SDL.h>
#include "stdafx.h"

#include "MainScene.h"

int main(int argc, char* args[]) {

	using namespace core;
	Engine e(new MainScene);

	if (e.Init() == 0) {

		return e.run();

	}

	return 0;

}
