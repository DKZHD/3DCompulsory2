#pragma once
#include "../Backend/Backend.h"

class FrontEnd : public Backend
{
public:
	void initialize() override;
	void Update(float deltaTime) override;
};

