#include <iostream>
#include <list>
#include <functional>
#include <map>
#include <stack>
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
		_menuTree = std::make_unique<MenuItem>(0, "Меню переплавки");
		_menuTree->AddMenuItem(std::make_shared<MenuItem>(1, "Добавление металла"));
		//заполнение меню добавления металлов
		InitAddFluidMenuTree((*_menuTree)[1]);
		_menuTree->AddMenuItem(std::make_shared<MenuItem>(2, "Очистить котёл", std::bind(&Cauldron::ClearCauldron, &cauldron)));
		_menuTree->AddMenuItem(std::make_shared<MenuItem>(3, "Показать содержимое", std::bind(&Cauldron::PrintFluids, &cauldron))); 
		_menuTree->AddMenuItem(std::make_shared<MenuItem>(1, "Выйти из программы", std::bind(&ProgramInterface::CloseProgram, this)));
	}

	void CloseProgram()
	{
		// не знаю, хорошая ли это идея
		this->~ProgramInterface();
	}

	void InitAddFluidMenuTree(std::shared_ptr<MenuItem> menuItem)
	{
		menuItem->AddMenuItem(std::make_shared<MenuItem>(0, "Какой металл добавить в котёл?"));
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
		do
		{
			for(int i = 0; i < _menuTree->MenuItemsCount(); i++)
			{
				(*_menuTree)[i]->Print();
			}
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