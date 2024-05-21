#pragma once

class BaseFluid
{
protected:
	double			_capacity;
	const double	_density;
	const bool		_isAlloy;
	std::string 	_name;
public:
	BaseFluid(std::string name, double capacity, double density, bool isAlloy) : _name(name), _capacity(capacity), _density(density), _isAlloy(isAlloy) {}
	double GetCapacity()
	{
		return _capacity;
	};

    //получить плотность жидкости
	double GetDensity() 
	{
		return _density;
	}
    
	bool IsAlloy() 
	{
		return _isAlloy;
	}

	void Print() const
	{
		std::cout<<_name<<std::endl;

	}
	virtual ~BaseFluid() {};
};