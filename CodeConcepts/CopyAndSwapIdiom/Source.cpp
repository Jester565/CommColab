#include <iostream>
#include "Cell.h"

int main()
{
		//Initialize the animal and plant cell
		Cell animal("Dog");
		Cell plant("Flower");
		std::cout << std::endl << "= Cell(\"Frog\")" << std::endl;
		std::cout << "Animal name before assignment: " << animal << std::endl;
		//Although the move constructor should technically be called, the compiler optimizes it so the object is directly created in the assignment operator (skipping the move constructor)
		animal = Cell("Frog");
		std::cout << "Animal name after assignment: " << animal << std::endl;
		
		std::cout << std::endl << "= plant" << std::endl;
		std::cout << "Animal name before assignment: " << animal << std::endl;
		std::cout << "Plant name before assignment: " << plant << std::endl;
		//Calls the copy constructor because plant is an l-value
		animal = plant;
		std::cout << "Animal name after assignment: " << animal << std::endl;
		std::cout << "Plant name after assignement: " << plant << std::endl;
		
		std::cout << std::endl << "= std::move(plant)" << std::endl;
		plant = Cell("Tree");
		std::cout << "Animal name before assignment: " << animal << std::endl;
		std::cout << "Plant name before assignment: " << plant << std::endl;
		//plant is an l-value but std::move() makes it an r-value and the move constructor is called.  This causes plant to be set to the default values of Cell.
		animal = std::move(plant);
		std::cout << "Animal name after assignment: " << animal << std::endl;
		std::cout << "Plant name after assignement: " << plant << std::endl;
		system("pause");
}