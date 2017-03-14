// check
#ifndef SUDOKU_FOR_CPP_GROUP_HPP
#define SUDOKU_FOR_CPP_GROUP_HPP

// include system libs
#include <cstddef>

// classes
class Cell;
class Board;

// group class
class Group {
	public:
		// value setter and getter
		inline void setParentClass(Board *board);

		// constructor
		Group();

	private:
		// type not set
		static const int TYPE_NO_SET = -1;

		// associated cells
		Cell *associatedCells = NULL;

		// board
		Board *parent = NULL;

		// type
		int type;

		// init members
		void initMembers();

};

// set parent class function
inline void Group::setParentClass(Board *board){
	// set parent class
	this->parent = board;

}

#endif


