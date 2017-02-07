#pragma once

namespace BlazeGameWorld { class Entity; }

class Component
{
public:

protected:
	
private:

	////////////////////////////////////////////////////////

public:
	Component();
	~Component();

	virtual void Update() = 0;

	virtual bool Initialize(BlazeGameWorld::Entity* entity) = 0;
protected:

private:
};

