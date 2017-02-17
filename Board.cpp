// Include Systemlib
#include <iostream>

// Include Userlib
#include "BoardSize.hpp"
#include "Board.hpp"
#include "Group.hpp"
#include "Cell.hpp"

// Usings
using std::cout;
using std::endl;

// Constructor
Board::Board(BoardSize* boardSize) : boardSize(boardSize) {
	// Init Cells
	this->initCells();

	// Init Groups
	this->initGroups();

}

// Destructor
Board::~Board() {
	// Delete Cells
	this->deleteCells();
}

// Init Cells Function
void Board::initCells(){
	// Get Cell Count
	int cellCount = (*(this->boardSize)).getCellCount();

	// New
	this->cells = new Cell[cellCount];

	// Set boardSize Pointer
	for(int i = 0;i < cellCount;i++)
		this->cells[i].setBoardSize(this->boardSize);
}

// Delete Cells Function
void Board::deleteCells(){
	// Delete Cells
	delete[] this->cells;
}

// Init Groups Function
void Board::initGroups(){
	// Get Group Count
	int groupCount = (*(this->boardSize)).getGroupCount();

	// New
	this->groups = new Group[groupCount];

	// Set boardSize Pointer
	for(int i = 0;i < groupCount;i++){
		this->groups[i].setBoardSize(this->boardSize);
	}
}

// Calculation Function
void Board::calc(){
	// Debug Message
	cout << "Test" << endl;
}

// Debug Functions
#ifdef DEBUG

// Get Cell By Position Function (Debug Function)
Cell *Board::getCellByPos(int x,int y){
	cout << y-1*this->boardSize->getNM()+(x-1) << endl;
	return &cells[(y-1)*(this->boardSize->getNM())+(x-1)];
}

#endif