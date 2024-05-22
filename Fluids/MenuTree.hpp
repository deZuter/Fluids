#pragma once
#include <vector>

//меню в данной программе представляет из себя дерево
class MenuItem
{

	//Название пункта меню
	std::string _menuItemName;
	//Делегат, соответствующий выбору в меню
	std::function<void()> _operation;
	//Список подменю
	std::vector<std::shared_ptr<MenuItem>> _menuItemList;
public:

	//Конструктор пункта для выбора
	MenuItem(std::string menuItemName, std::function<void()> operation) : _menuItemName(menuItemName), _operation(operation) {}
	
	//Если в конструктор меню не передали делагат, то этот пункт нельзя будет выбрать, но он также должен отображаться (сделано для оглавления меню)
	MenuItem(std::string menuItemName) : _menuItemName(menuItemName), _operation(0) {}

	void AddMenuItem(std::shared_ptr<MenuItem> menuItem) 
	{
		_menuItemList.push_back(menuItem);
	}

	//обращение по индексу в подменю
	std::shared_ptr<MenuItem> operator[](int index) const
	{
		//меньше size т.к. если один элемент -> size == 1 но  обратиться можно по нулевому индексу
		if(index >= 0 && index < _menuItemList.size())
			return _menuItemList[index];
		else return nullptr;
	}

	void Print() const
	{
		std::cout<< _menuItemName << std::endl;
	}

	size_t MenuItemsCount() const
	{
		return _menuItemList.size();
	}

	~MenuItem()=default;
};