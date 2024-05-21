#pragma once

class TinFactory : public FluidFactory
{
public:
	std::shared_ptr<BaseFluid> CreateFluid(double capacity) override
	{
		return std::make_shared<Tin>(capacity);
	}
};
