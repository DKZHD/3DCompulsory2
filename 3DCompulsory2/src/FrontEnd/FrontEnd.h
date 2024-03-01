#pragma once
#include "../Backend/Backend.h"

class FrontEnd : public Backend
{
public:
	FrontEnd() = default;
	
	void create() override;
	void Update(float deltaTime) override;

	~FrontEnd() override = default;
};

