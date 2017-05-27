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
	
	// blank cell count init
	this->blankCellCountInit();

	// read file
	this->fileReader(fileName);

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

// get cell by pos
Cell *Board::getCellByPos(int x,int y){
	// Check Value
	if(0 <= x && 0 <= y && x < this->boardSize->getNM() && y < this->boardSize->getNM()){
		// return cell
		return &cells[x * this->boardSize->getNM() + y];

	}else{
		// error ( out of index )
		cout << "out of index" << endl;

		// return null
		return (Cell *) NULL;

	}

}


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

// file reader
int Board::fileReader(char *fileName){
	// file pointer
	FILE *fp;

	// scanFormatString
	char scanFormatString[16];
	
	// buffer
	char buf[BoardSize::MAX_NM + 1];
	cout << this->boardSize->getNM() << endl;

	// cache value
	int cache;

	// file open
	if( (fp = fopen(fileName,"r")) == NULL ){
		// error ( file open fail )
		cout << "file open fail" << endl;

		// return error code
		return -1;

	}

	// create format string
	sprintf(scanFormatString,"%%%ds%%*[^\n]",this->boardSize->getNM());

	// skip comment line
	fscanf(fp,"%*[^\n]");

	// each line loop
	for(int i = 0;i < this->boardSize->getNM();i++){
		// read line and error check
		if(fscanf(fp,scanFormatString,buf) == EOF){
			// error ( lack of data )
			cout << "lack of data (type 0)" << endl;

			// return error code
			return -1;

		}

		// each char
		for(int j = 0;j < this->boardSize->getNM();j++){
			// check value
			if(buf[j] == '\0'){
				// null
				cout << "lack of data (type 1)" << endl;

				// return error code
				return -1;

			}else if(buf[j] == '.'){
				// zero
				this->getCellByPos(i,j)->setValue(Cell::CELL_EMPTY);

			}else{
				// other value
				if('1' <= buf[j] && buf[j] <= '9')
					cache = buf[j] - '0';
				else if('a' <= buf[j] && buf[j] <= 'z')
					cache = buf[j] - 'a' + 10;
				else if('A' <= buf[j] && buf[j] <= 'Z')
					cache = buf[j] - 'A' + 10;
				else {
					// error ( out of range charactor )
					cout << "out of range charactor" << endl;
					
					// return error code
					return -1;

				}

				// valid
				if(1 <= cache && cache <= this->boardSize->getNM()){
					// set value
					this->getCellByPos(i,j)->setValue(cache);
					
					// blank cell count dec
					this->blankCellCountDec();

				}else{
					// error ( out of range number )
					cout << "out of range number" << endl;

					// return error code
					return -1;

				}

			}
		}

	}
	
	// return success code
	return 0;

}

// read header
void Board::readHeaderByFile(FILE **fp){
	cout << "Read Header" << endl;
	
}

// read cells
void Board::readCellsByFile(FILE **fp){
	cout << "Read Cells" << endl;

}


//--------------------------------------
// Write
//--------------------------------------

// Write to console
void Board::writeToConsole(){
	// loop
	for(int i = 0;i < this->boardSize->getNM();i++){
		for(int j = 0;j < this->boardSize->getNM();j++){
			cout << this->cellValueToChar(this->getCellByPos(i,j)->getValue());
		}
		cout << endl;
	}

}

char Board::cellValueToChar(int n){
	// cell value to char
	if(n == Cell::CELL_EMPTY)
		return ' ';
	else if(1 <= n && n <= 9)
		return '0' + n;
	else if(10 <= n && n <= ('z'-'a') + 1)
		return 'a' + ( n - 10 );
	else {
		cout << "out of range number" << endl;
		return '?';
	}
}

//--------------------------------------
// Calc
//--------------------------------------

void Board::calc(){
	// dummy
	cout << "This is Dummy Function (calc)" << endl;

}


//--------------------------------------
// Blank Cell Count
//--------------------------------------

void Board::blankCellCountInit(){
	this->blankCellCount = this->boardSize->getCellCount();
}


//--------------------------------------
// Group Cell Association
//--------------------------------------

void Board::groupCellAssociation(){
	
}


