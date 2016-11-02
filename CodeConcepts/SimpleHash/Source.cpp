#include <iostream>

int main()
{
		std::hash<uint32_t> hasher{};	//construct the hash object, tell it the key values will be uint32_t
		size_t hashVal = hasher(2);	//pass in the key and the hash value will be returned
}
