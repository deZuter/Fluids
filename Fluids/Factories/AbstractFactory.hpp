#pragma once
#include "Fluids.hpp"

class FluidFactory
{
public:
	virtual std::shared_ptr<BaseFluid> CreateFluid(double capacity) = 0;
	~FluidFactory() {}
};
