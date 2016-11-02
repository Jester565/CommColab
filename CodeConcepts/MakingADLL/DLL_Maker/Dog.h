#pragma once
#include <string>
#include "api.h"

//Dog class that has all of its symbols exported into the DLL because DOG_EXPORT is there
class DOG_EXPORT Dog
{
public:
		Dog(const std::string& name);

		void bark();

		std::string getName()
		{
				return name;
		}

		~Dog();

private:
		std::string name;
};

