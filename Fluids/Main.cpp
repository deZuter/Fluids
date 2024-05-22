#include <iostream>
#include <list>
#include <functional>
#include <map>
#include <stack>
#include <memory>
#include "Fluids/Fluids.hpp"
#include "Factories/FluidFactory.hpp"
#include "MenuTree.hpp"
#include "Cauldron.hpp"

class ProgramInterface
{
private:
	std::unique_ptr<MenuItem> _menuTree;
	std::stack<MenuItem> _movementOrder;
	void InitMainMenuTree(Cauldron &cauldron) 
	{
		_menuTree = std::make_unique<MenuItem>("Меню переплавки");
		_menuTree->AddMenuItem(std::make_shared<MenuItem>("Добавление металла"));
		//заполнение меню добавления металлов
		InitAddFluidMenuTree(*(*_menuTree)[0]);
		_menuTree->AddMenuItem(std::make_shared<MenuItem>("Очистить котёл", std::bind(&Cauldron::ClearCauldron, &cauldron)));
		_menuTree->AddMenuItem(std::make_shared<MenuItem>("Показать содержимое", std::bind(&Cauldron::PrintFluids, &cauldron))); 
		_menuTree->AddMenuItem(std::make_shared<MenuItem>("Выйти из программы", std::bind(&ProgramInterface::CloseProgram, this)));
	}

	void CloseProgram()
	{
		// не знаю, хорошая ли это идея
		this->~ProgramInterface();
	}

	void InitAddFluidMenuTree(MenuItem& menuItem)
	{
		menuItem.AddMenuItem(std::make_shared<MenuItem>("1. Copper"));
		menuItem.AddMenuItem(std::make_shared<MenuItem>("2. Iron"));
		menuItem.AddMenuItem(std::make_shared<MenuItem>("3. Tin"));
		//реализация добавления металлов в котел (можно как-то сделать динамческий вывод всех доступных металлов, но пока что статически)

	}
public:

	ProgramInterface(Cauldron &cauldron) 
	{
		InitMainMenuTree(cauldron);
	}
	
	void EnterMenu()
	{
		bool isNeedToContinue = true;
		int choice = -1;
		do
		{
			//@TODO записать в стек корень дерева, при выборе элемента либо перейти в подменю (если нет привязанной функции), либо выполнить привязанную функцию
			for(int i = 0; i < _menuTree->MenuItemsCount(); i++)
			{
				std::cout<< i+1 << ". "; (*_menuTree)[i]->Print();
			}
			//ввод идекса выбора в меню
			std::cin>>choice;
		} while (isNeedToContinue);
	}
	~ProgramInterface() = default;
};


int main(int argc, char** argv) 
{

	//создание котла, в котором будут плавиться жидкости и смешиваться в сплавы
	std::unique_ptr<Cauldron> cauldron = std::make_unique<Cauldron>();

	//создание программного интерфейса, в котором и будет происходить основной цикл программы
	std::unique_ptr<ProgramInterface> programInterface = std::make_unique<ProgramInterface>(*cauldron);

	programInterface->EnterMenu();
	return 0;
}