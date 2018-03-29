#pragma once

namespace core {

	enum class SystemType : unsigned __int8{

		WINDOW,
		INPUT,
		AI,
		PHYSICS,
		TOTAL_SYSTEMS

	};

class System
{

public:
	const SystemType type;
	System(SystemType st);
	~System();

	virtual bool Init();
	virtual void Update();
	virtual void Draw() const;
	virtual bool Shutdown();
};

}



