#ifndef BOARD_HPP
#define BOARD_HPP

// Include Userlib
#include "BoardSize.hpp"
#include "Group.hpp"
#include "Cell.hpp"

// Board Class
class Board {
	private:
		// BoardSize
		BoardSize* boardSize;
		
		// Cells (N * M) * (M * N)
		Cell *cells;
		
		// Groups (N * M) * 3 (3x3 Group, 1x9 Groups, 9x1 Groups)
		Group *groups;

		// Init Cells
		void initCells();

		// Delete Cells
		void deleteCells();

		// Init Groups
		void initGroups();

		// Delete Groups
		void deleteGroups();

	public:
		// Public Constructor
		Board(BoardSize* boardSize);
		
		// Public Destructor
		~Board();
		
		// Start Calc
		void calc();
};

#endif
