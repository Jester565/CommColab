#include <iostream>
#include <typeinfo>

//When there is only one argument passed into adder, this is called
template <typename T>
T adder(T obj)
{
		return obj;
}

//typename...Args is called the template parameter pack
template <typename T, typename... Args>	//typename T removes 1 parameter from the parameter pack each time
T adder(T first, Args... args)		//Args... args is called the function parameter pack
{
		return first + adder(args...);		//The args... unpacks the parameters, the elipses are necessary for unpacking
}

//Called when there is only one element left in the pack, will print an error because pairs should be compared
template <typename U, typename T>
bool comparer(U printer, T solo)
{
		std::cerr << "An element did not have a pair in comparer" << std::endl;
		return false;
}

//Called when there are two elements left in the pack
template <typename U, typename T>
bool comparer(U printer, T first, T second)
{
		printer.print();
		return first == second;
}

//Called when there are more than two elements in the pack.  True when all pairs equal eachother.
template <typename U, typename T, typename... Args>
bool comparer(U printer, T first, T second, Args... args)
{
		printer.print();
		return (first == second) && comparer(printer, args...);
}

struct Printer
{
		void print()
		{
				std::cout << "Printing" << std::endl;
		}
};

int main()
{
		int num = adder(4, 1, 6, 10, 12);
		std::cout << "Sum: " << num << std::endl;
		bool pairsEqual = comparer(Printer(), 2, 2, 1, 1, 4, 4, 5);	//Odd number of elements when there should be pairs
		std::cout << std::boolalpha << pairsEqual << std::endl;
		system("pause");
}
