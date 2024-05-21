#pragma once

class IronFactory : FluidFactory
{
public:
	std::shared_ptr<BaseFluid> CreateFluid(double capacity) override
	{
		return std::make_shared<Iron>(capacity);
	}
};