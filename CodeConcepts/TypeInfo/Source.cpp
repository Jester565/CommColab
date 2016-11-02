#include <iostream>
#include <typeinfo>

struct Dog {
		virtual void bark()
		{
				std::cout << "ARF" << std::endl;
		}
};

struct Terry : public Dog {
		void bark() override
		{
				std::cout << "Woof" << std::endl;
		}
};

int main()
{
		int num = 2;
		std::cout << "Num type: " << typeid(num).name() << std::endl;
		Dog* sandyPtr = new Terry();
		std::cout << "sandy type: " << typeid(sandyPtr).name() << std::endl;
		std::cout << "sandy dereferenced type: " << typeid(*sandyPtr).name() << std::endl;
		system("pause");
}
