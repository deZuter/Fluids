#pragma once
#include "BaseFluid.hpp"

class Tin : public BaseFluid
{
public:
	Tin(double capacity) : BaseFluid("tin",capacity, 7.3, false) {}
};