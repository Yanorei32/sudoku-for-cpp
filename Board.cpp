// include system libs
#include <iostream>
#include <cstdio>

// include user libs
#include "Board.hpp"
#include "Cell.hpp"
#include "Group.hpp"
#include "BoardSize.hpp"


// using common functions
using std::cout;
using std::endl;


//--------------------------------------
// Constructor / Destructor
//--------------------------------------

// constructor
Board::Board(char *fileName){
	// init boardSize
	this->initBoardSize(3,3);

	// init cells
	this->initCells();
	
	// init groups
	this->initGroups();
	
	// read file
	//this->readCellsByFile(fp);

}

// destructor
Board::~Board(){
	// delete boardSize
	this->deleteBoardSize();

	// delete cells
	this->deleteCells();

	// delete groups
	this->deleteGroups();

}


//--------------------------------------
// Cells
//--------------------------------------

// init cells
void Board::initCells(){
	// get cell count by boardSize
	int cellCount = this->boardSize->getCellCount();

	// new
	this->cells = new Cell[cellCount];

	// set boardsize pointer
	for(int i = 0;i < cellCount;i++){
		this->cells[i].setParentClass(this);
	}

}

// delete cells
void Board::deleteCells(){
	// delete cells
	delete[] this->cells;

}

#ifdef DEBUG

// get cell by pos (debug)
Cell *Board::getCellByPos(int x,int y){
	// dummy
	cout << "This function is dummy (getCellByPos)" << endl;

	// return null pointer
	return (Cell*)NULL;

}


#endif


//--------------------------------------
// Groups
//--------------------------------------

// init
void Board::initGroups(){
	// get group count
	int groupCount = this->boardSize->getGroupCount();

	// new
	this->groups = new Group[groupCount];

	// set boardsize pointer
	for(int i = 0;i < groupCount;i++){
		this->groups[i].setParentClass(this);
	}
}

// delete
void Board::deleteGroups(){
	// delete groups
	delete[] this->groups;

}


//--------------------------------------
// BoardSize
//--------------------------------------

// init
void Board::initBoardSize(int x, int y){
	// create board size
	this->boardSize = new BoardSize(x,y);

}

// delete
void Board::deleteBoardSize(){
	// delete boardSize
	delete this->boardSize;

}


//--------------------------------------
// Read
//--------------------------------------

// read header
void Board::readHeaderByFile(FILE *fp){
	cout << "Read Header" << endl;

}

// read cells
void Board::readCellsByFile(FILE *fp){
	cout << "Read Cells" << endl;

}


//--------------------------------------
// Write
//--------------------------------------

// Write to console
void Board::writeToConsole(){
	cout << "Cell write to console" << endl;

}


//--------------------------------------
// Calc
//--------------------------------------

void Board::calc(){
	// dummy
	cout << "This is Dummy Function (calc)" << endl;

}


