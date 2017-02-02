#ifndef BOARD 
#define BOARD

#include "BoardSize.hpp"
#include "Group.hpp"
#include "Cell.hpp"

class Board {
	private:
		// BoardSize
		BoardSize* boardSize;
		
		// Cells (N * M) * (M * N)
		Cell_t *pCells;
		
		// Groups (N * M) * 3 (3x3 Group, 1x9 Groups, 9x1 Groups)
		Group_t *pGroups;

	public:
		// Public Constructor
		Board(BoardSize* boardSize);

};

#endif
