#pragma once

namespace BlazeGameWorld { class Entity; }

class Component
{
public:

protected:
	
private:
	BlazeGameWorld::Entity* p_entity;

	////////////////////////////////////////////////////////

public:
	Component();
	~Component();

	void Update();
protected:

private:
};

