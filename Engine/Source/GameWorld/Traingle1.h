#pragma once
#include "Entity.h"

class Traingle1 : public Entity
{
public:
	Traingle1();
	~Traingle1();

	virtual void Update() override;
	virtual void Initialize() override;
};

