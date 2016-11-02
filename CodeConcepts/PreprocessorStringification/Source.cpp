#include <iostream>
#include "AbstractPacket.h"

//Packet : public AbstractPacket
class Packet : INHERITS_ABSPACKET
{
public:
		Packet(int num)
				:CHAIN_ABSPACKET(Packet, num)  //Calls the constructor for AbsPacket passing in parameters, but the Packet type is converted to a string
		{
				
		}
};

int main()
{
		//Create new instance of Packet, passing in 5 as the number.
		AbstractPacket* absPacket = new Packet(5);
		system("pause");
}
