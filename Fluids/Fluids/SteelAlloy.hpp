#pragma once
#include "BaseFluid.hpp"
//@TODO
//нужно добавить сильный нагрев чтобы железо стало сталью
class SteelAlloy : public BaseFluid
{
public:
	SteelAlloy(double capacity) : BaseFluid("steelAlloy",capacity, 7.8, true) {}
};