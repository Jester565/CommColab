#include "AbstractPacket.h"
#include <iostream>

AbstractPacket::AbstractPacket(const char* className, int i)
{
		std::cout << className << std::endl;
		std::cout << i << std::endl;
}


AbstractPacket::~AbstractPacket()
{
}
