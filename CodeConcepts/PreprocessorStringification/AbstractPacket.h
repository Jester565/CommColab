#pragma once

/*
Abstract class that may change constructor method names... Maybe we should use defines.
*/
class AbstractPacket
{
public:
		AbstractPacket(const char* className, int i);

		~AbstractPacket();
};

//Code to call constructor for an ABS_Packet passing in a class type (not a string) and an integer
#define CHAIN_ABSPACKET(className, num) AbstractPacket(#className, num)  //#indicates it will be reading the class name, num just means tranfer its a normal parameter
#define INHERITS_ABSPACKET public AbstractPacket  //Used when inheriting from packet
