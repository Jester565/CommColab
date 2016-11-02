#include "Dog.h"
#include <iostream>

Dog::Dog(const std::string& name)
		:name(name)
{
}

void Dog::bark()
{
		std::cout << "Arf" << std::endl;
}

Dog::~Dog()
{
}
