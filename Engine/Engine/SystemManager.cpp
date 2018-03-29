#include "SystemManager.h"
#include "System.h"
#include "InputSystem.h"
#include "Window.h"

namespace core {

	SystemManager* SystemManager::s_instance = nullptr;
	SystemManager::SystemManager()
	{
		system.push_back(new InputSystem());
		system.push_back(new Window());

	}


	SystemManager::~SystemManager()
	{
	}
	bool SystemManager::Init()
	{
		for (System* s : system)
		{
			if (!s->Init())
			{
				return false;
			}
		}

		return true;
	}
	void SystemManager::Update()
	{
		for (System* s : system)
		{
			s->Update();
		}
	}
	void SystemManager::Draw() const
	{
		for (System* s : system)
		{
			s->Draw();
		}
	}
	bool SystemManager::Shutdown()
	{

		for (System* s : system)
		{
			if (!s->Shutdown())
			{
				return false;
			}
			delete s;
			s = nullptr;
		}

		system.clear();
		return true;
	}

}


