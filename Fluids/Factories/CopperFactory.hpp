#pragma once

class CopperFactory : public FluidFactory
{
public:
	std::shared_ptr<BaseFluid> CreateFluid(double capacity) override
	{
		return std::make_shared<Copper>(capacity);
	}
};