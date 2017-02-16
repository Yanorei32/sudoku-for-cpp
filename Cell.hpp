#ifndef CELL_HPP
#define CELL_HPP

// Include Systemlib
#include <cassert>
#include <cstddef>

// Include Userlib
#include "BoardSize.hpp"
#include "Group.hpp"

class Group;

// Cell Class
class Cell {
	private:
		// DEFINE
		static const int CELL_EMPTY = -1;

		// value (-1 is not set)
		int val;
		
		// Value Checkers
		inline bool setValueChecker(int n);
		
		// BoardSize
		BoardSize *boardSize = NULL;

		// Associated Groups
		Group *associatedGroups[3];

#ifdef DEBUG
		// Cell Position
		int x,y;
#endif

	public:
		// Constructor
		Cell();

		// Value Getter and Setter
		inline void setValue(int n);
		inline int	getValue();
		inline void clearValue();
		inline void	setBoardSize(BoardSize *boardSize);
		void initMemthods();

#ifdef DEBUG
		inline void setCellPosition(int index);
#endif

};

// Value Checker
inline bool Cell::setValueChecker(int n){return (1 <= n && n <= this->boardSize->getMax());}

// Value Setter
inline void Cell::setValue(int n){
	// Value Check
	assert(this->setValueChecker(n));

	// Set Value
	this->val = n;
}

// Value Getter
inline int Cell::getValue(){
	return this->val;
}

// Value Celar
inline void Cell::clearValue(){
	this->val = this->CELL_EMPTY;
}

// Board Size Setter
inline void Cell::setBoardSize(BoardSize *boardSize){
	this->boardSize = boardSize;
}

#endif

