#pragma once
#include <vector>
#include "Manager.h"
#include "System.h"

namespace core {
	
	/*Class Singleton{
	
	static getInstance();

	}
	*/

class SystemManager : public Manager
{

	std::vector<class System*> system;
	SystemManager();

	static SystemManager* s_instance;

public:
	
	~SystemManager();

	bool Init();
	void Update();
	bool Shutdown();
	void Draw() const;

	static SystemManager* getInstance()
	{
		if (s_instance == NULL)
		{
			s_instance = new SystemManager();
		}
		return s_instance;
	}

	System* GetSystem(SystemType st)
	{
		for (System* s : system)
		{
			if (s->type == st)
			{
				return s;
			}

		}
		return nullptr;
	}
};
}





