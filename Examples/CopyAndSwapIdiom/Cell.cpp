#include "Cell.h"

Cell::Cell(const std::string & cellName)
{
		name = new std::string(cellName);
}

Cell::Cell(const Cell & other)
{
		std::cout << "Copy Constructor Called" << std::endl;
		if (other.name != nullptr)
		{
				name = new std::string(*other.name);
		}
}

Cell::Cell(Cell&& other)
		:Cell()
{
		std::cout << "Move constructor called" << std::endl;
		swap(*this, other);	//swap because other is temporary so we want our old data to go into it so it can be deleted
}

Cell & Cell::operator=(Cell other)
{
		std::cout << "Assignment operator called" << std::endl;
		swap(*this, other);	//other is passed by value and will be deleted at the end of the method, so we can fill it with all of the old attriubtes
		return *this;
}

Cell::~Cell()
{
		delete name;
	 name = nullptr;
}

Cell::Cell()
		:name(nullptr)
{

}

std::ostream & operator<<(std::ostream & os, const Cell & cell)
{
		if (cell.name != nullptr)
		{
				os << *cell.name;
		}
		else
		{
				os << "NULLPTR";
		}
		return os;
}

void swap(Cell & first, Cell & second)
{
		std::swap(first.name, second.name);	//Swaps the name attributes (so just swaps the pointer values)
}
