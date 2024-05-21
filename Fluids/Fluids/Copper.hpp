#pragma once
#include "BaseFluid.hpp"
 
class Copper : public BaseFluid
{
public:
	Copper(double capacity) : BaseFluid("copper", capacity, 8.0, false) {}
};
