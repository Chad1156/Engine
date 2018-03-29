#include "MainScene.h"
#include <InputSystem.h>
#include <SystemManager.h>
#include <iostream>
#include "stdafx.h"
#include <GameObject.h>
using namespace std;


MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

bool MainScene::Init() {


	return true;

}
void MainScene::Update() {

	using namespace core;
	SystemManager* sm = core::SystemManager::getInstance();
	System* someSystemThatWeDontKnowYet = sm->getInstance()->GetSystem(core::SystemType::INPUT);


	InputSystem* inputSystem = dynamic_cast<InputSystem*>(someSystemThatWeDontKnowYet);

	if (inputSystem->IsLeftPressed())
	{
		printf("left pressed from scene!!");
	}
	

}
void MainScene::Draw() const {

	core::InputSystem iSystem;
	using namespace scene;

	GameObject gameObject;
	gameObject.Draw();
	

}
bool MainScene::Shutdown() {

	return true;

}
