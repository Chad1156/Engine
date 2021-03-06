#pragma once
#include <Scene.h>


class MainScene : public scene::Scene
{
public:
	MainScene();
	~MainScene();

	bool Init();
	void Update();
	void Draw() const;
	bool Shutdown();
};

