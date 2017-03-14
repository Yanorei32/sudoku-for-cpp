// include user libs
#include "Cell.hpp"
#include "Board.hpp"
#include "BoardSize.hpp"

// public constructor
Cell::Cell(){
	// init member values
	this->initMembers();

}

// value checker
bool Cell::setValueChecker(int n){
	// 1 <= n <= boardSize::MAX || n == CELL_EMPTY
	return ((1 <= n && n <= this->parent->boardSize->getMax()) || n == this->CELL_EMPTY);

}

