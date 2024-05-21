#pragma once
#include "BaseFluid.hpp"
 
 class Iron : public BaseFluid
{
public:
	Iron(double capacity) : BaseFluid("iron", capacity, 7.8, false) {}
};