#include "BoardSize.hpp"
#include "Board.hpp"
#include "Group.hpp"
#include "Cell.hpp"

Board::Board(BoardSize* boardSize) : boardSize(boardSize) {
	// Init Cells
	this->initCells();
}

Board::~Board() {
	// Delete Cells
	this->deleteCells();
}

// Init Cells Function
void Board::initCells(){
	// Get Cell Count
	int cellCount = (*(this->boardSize)).getCellCount();

	// New
	this->pCells = new Cell_t[cellCount];

	// Set boardSize Pointer
	for(int i = 0;i < cellCount;i++)
		pCells[i].setBoardSize(this->boardSize);
}

// Delete Cells Function
void Board::deleteCells(){
	// Delete Cells
	delete[] this->pCells;
}
