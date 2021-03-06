#pragma once

#include <vector>

namespace scene {

class Scene
{
private:
	std::vector<class  GameObject*> gameObject;

public:
	Scene();
	virtual ~Scene();

	virtual bool Init();
	virtual void Update();
	virtual void Draw() const;
	virtual bool Shutdown();

};

}



