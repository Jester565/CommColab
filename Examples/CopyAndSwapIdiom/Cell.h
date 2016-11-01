#include <iostream>
#include <ostream>
#include <string>

class Cell {
public:
		/*
		Normal constructor, takes the name as a paramter
		*/
		Cell(const std::string& cellName);

		/*
		Copy constructor, only called when copying an l-value
		*/
		Cell(const Cell& other);

		/*
		Move constructor, only called when copying an r-value
		*/
		Cell(Cell&& other);

		/*
		Assignment operator, other is passed by value so it may be treated as an r-value (this will call the move constructor instead of copy)
		*/
		Cell& operator=(Cell other);

		/*
		Prints the cell name as a string.  Adds NULLPTR to the stream if name is nullptr.
		*/
		friend std::ostream& operator << (std::ostream& os, const Cell& cell);

		/*
		Desturctor deletes name
		*/
		~Cell();

private:
		/*
		Constructor called by move constructor and sets name to nullptr
		*/
		Cell();

		/*
		Swaps the attributes of first and second, used by move constructor and assignment operator
		*/
		friend void swap(Cell& first, Cell& second);

		/*
		The name of the cell, can be nullptr
		*/
		std::string* name;
};