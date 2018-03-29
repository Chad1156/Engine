#pragma once
#include "System.h"
#include "Scene.h"
#include "SDL.h"

namespace core {

	class InputSystem : public System
	{

		bool requestedQuit;

		bool e_leftPressed = false;
		bool e_rightPressed = false;
		bool e_upPressed = false;
		bool e_downPressed = false;

	public:
		InputSystem();
		~InputSystem();
		void Update() override;

		inline bool IsLeftPressed() const { return e_leftPressed; }

		inline bool IsRightPressed() const { return e_rightPressed; }

		inline bool IsUpPressed() const { return e_upPressed; }

		inline bool IsDownPressed() const { return e_downPressed; }

		inline bool RequestedQuit() const { return requestedQuit; }

	};
}


