#ifndef CELL_T
#define CELL_T

#include "BoardSize.hpp"
#include <cassert>
#include <cstddef>


// Cell Type
class Cell_t {
	private:
		// value (-1 is not set)
		int val;
		
		// Board 
		static const int CELL_EMPTY = -1;

		// Value Checkers
		inline bool setValueChecker(int n);
		
		// BoardSize
		BoardSize* boardSize = NULL;

	public:
		// Constructor
		Cell_t();

		// Value Getter and Setter
		inline void setValue(int n);
		inline int	getValue();
		inline void clearValue();
		inline void	setBoardSize(BoardSize *boardSize);
};

// Value Checker
inline bool Cell_t::setValueChecker(int n){return (1 <= n && n <= this->boardSize->getMax());}

// Value Setter
inline void Cell_t::setValue(int n){
	// Value Check
	assert(this->setValueChecker(n));

	// Set Value
	this->val = n;
}

// Value Getter
inline int Cell_t::getValue(){
	return this->val;
}

// Value Celar
inline void Cell_t::clearValue(){
	this->val = this->CELL_EMPTY;
}

// Board Size Setter
inline void Cell_t::setBoardSize(BoardSize *boardSize){
	this->boardSize = boardSize;
}

#endif

