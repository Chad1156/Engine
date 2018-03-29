#pragma once
#include "Manager.h"
#include "Scene.h"
#include <vector>

namespace core {

class SceneManager : public Manager
{
private:
	std::vector<class Scene*> scene;

public:
	SceneManager();
	~SceneManager();
};

}



