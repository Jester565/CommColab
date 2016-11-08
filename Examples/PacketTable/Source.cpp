#include <iostream>
#define __COMMS_DEBUG_FATAL_EXIT
#include <CommProto/pkg/packethashtable.h>
#include <CommProto/abstractpacket.h>
#include <CommProto/callback.h>
#include <CommProto/comms.h>
#include <unordered_map>
#include <vector>

class Ping : INHERITS_ABSPACKET {
public:
		Ping(const std::string& key)
				: ABSPACKET(key.c_str())
		{

		}

		void Pack(OBJECTSTREAM& outStream) override
		{

		}

		void Unpack(OBJECTSTREAM& inStream) override
		{

		}

		ABSPACKET* Create()
		{
				return new Ping("woof");
		}
};

error_t PingCallback(const comnet::Header& header, const Ping& packet, comnet::Comms& node) {
		std::cout << "Packet recieved!" << std::endl;
		return comnet::CALLBACK_SUCCESS | comnet::CALLBACK_DESTROY_PACKET;
}

std::string genRandomString()
{
		std::string total;
		for (int i = 0; i < 30; i++)
		{
				total += (char)(rand() % 256);
		}
		return total;
}

int main()
{
		std::unordered_map <uint32_t, Ping*> packTracker;
		comnet::pkg::PacketHashTable packTable;
		for (int k = 0; k < 20; k++)
		{
				int packTrackInsertCount = 0;
				int insertCount = 0;
				for (int i = 0; i < 500; i++)
				{
						Ping * packet = new Ping(genRandomString());
						packTable.Insert(packet, new comnet::Callback((comnet::callback_t)PingCallback));
						if (packTracker.find(packet->GetId()) == packTracker.end())
						{
								packTrackInsertCount++;
								packTracker.emplace(std::make_pair(packet->GetId(), packet));
						}
						else
						{
								packTracker.erase(packet->GetId());
								packTracker.emplace(std::make_pair(packet->GetId(), packet));
						}
				}

				std::vector <uint32_t> removeTracker;

				for (auto it = packTracker.begin(); it != packTracker.end(); it++)
				{
						if (std::rand() % 1000 < 2)
						{
								break;
						}
						if (!packTable.Remove(it->first)) {
								std::cout << "Remove failed" << std::endl;
						}
						removeTracker.push_back(it->first);
				}

				std::cout << removeTracker.size() << " elements were removed" << std::endl;

				for (int i = 0; i < removeTracker.size(); i++)
				{
						int numRemoved = packTracker.erase(removeTracker.at(i));
						if (numRemoved != 1)
						{
								std::cout << "NUM REMOVED NOT 1" << std::endl;
						}
				}
				std::cout << std::endl << std::endl;
		}

		system("pause");
}
