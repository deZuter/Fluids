#pragma once

class BronzeAlloyFactory : FluidFactory
{
public:
	std::shared_ptr<BaseFluid> CreateFluid(double capacity) override
	{
		return std::make_shared<BronzeAlloy>(capacity);
	}
};