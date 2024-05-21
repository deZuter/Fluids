#pragma once
#include <vector>

class Cauldron 
{
	private:	
		std::vector<std::shared_ptr<BaseFluid>> _fluids;
		void CheckForAlloy(std::vector<std::shared_ptr<BaseFluid>> _fluids)
		{
			//пока ничего, но будет перебор пар и проверка на сплавы
		}

        //простая сортировка пузырьком (алгоритм сильнее не нужен т.к. вектор ожидается маленьким)
        void SortForDensity(std::vector<std::shared_ptr<BaseFluid>> _fluids)
        {
            for (int i = 0; i < _fluids.size(); i++)
            {
                for(int j = 0; j < _fluids.size() - 1; j++)
                {
                    if (_fluids[j]->GetDensity() > _fluids[j + 1]->GetDensity())
                    {
                        auto temp = _fluids[j+1];
                        _fluids[j+1] = _fluids[j];
                        _fluids[j]=_fluids[j+1];
                    }
                }
            }
        }
        
	public:
		Cauldron() = default;

		void ClearCauldron() 
		{	
			_fluids.clear();
		}

		void AddFluid(std::shared_ptr<BaseFluid> fluid)
		{
			_fluids.push_back(fluid);
            SortForDensity(_fluids);
			CheckForAlloy(_fluids);
		}
		
		void PrintFluids() const
		{
			for (auto fluid : _fluids)
            {
                fluid->Print();
            }
		}
		
		~Cauldron() {}
};
