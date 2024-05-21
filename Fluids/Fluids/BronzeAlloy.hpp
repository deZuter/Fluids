#pragma once
#include "BaseFluid.hpp"

class BronzeAlloy : public BaseFluid
{
public:
	BronzeAlloy(double capacity) : BaseFluid("bronzeAlloy", capacity, 8.6, true) {}
};