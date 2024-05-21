#pragma once

class SteelAlloyFactory : FluidFactory
{
public:
	std::shared_ptr<BaseFluid> CreateFluid(double capacity) override
	{
		//return new SteelAlloy(capacity);
		return std::make_shared<SteelAlloy>(capacity);
	}
};
