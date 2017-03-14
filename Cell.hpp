// check
#ifndef SUDOKU_FOR_CPP_CELL_HPP
#define SUDOKU_FOR_CPP_CELL_HPP

// include system libs
#include <cassert>
#include <cstddef>
#include <iostream>

// using common functions
using std::cout;
using std::endl;

// classes
class Group;
class Board;

// cell class
class Cell {
	public:
		// define
		static const int CELL_EMPTY = -1;

		// constructor
		Cell();

		// value setter and getter
		inline void	setParentClass(Board *board);
		inline void	setValue(int n);
		inline void	clearValue();
		inline int	getValue();
		inline bool	isEmpty();


#ifdef DEBUG
		// set debug method
		inline void	setCellPosition(int index);
#endif

	private:
		// cell value ( default : empty )
		int val;

		// value checker
		bool setValueChecker(int n);

		// parent class
		Board *parent = NULL;

		// associated groups
		Group *associatedGroups[3];

		// init members
		inline void initMembers();

#ifdef DEBUG
		// cell position
		int x,y;
#endif

};

// parent setter
void Cell::setParentClass(Board *parent){
#ifdef DEBUG
	// over write WARN ( if debug mode )
	if(this->parent != NULL) cout << "WARN: over write parent value" << endl;

#endif

	// set parent class
	this->parent = parent;

}

// value getter
int Cell::getValue(){
	// return value
	return this->val;

}

// value setter
void Cell::setValue(int n){
	// value check
	assert(this->setValueChecker(n));

	// set value
	this->val = n;

}

// value clear
void Cell::clearValue(){
	// clear value
	this->val = this->CELL_EMPTY;

}

// is empty
bool Cell::isEmpty(){
	// return value
	return (this->val == this->CELL_EMPTY);
	
}

void Cell::initMembers(){
	// init value ( set to empty )
	this->val = this->CELL_EMPTY;
}

#endif

