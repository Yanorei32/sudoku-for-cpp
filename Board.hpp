// check
#ifndef SUDOKU_FOR_CPP_BOARD_HPP
#define SUDOKU_FOR_CPP_BOARD_HPP

// include system libs
#include <cstdio>

class BoardSize;
class Group;
class Cell;

// board class
class Board {
	// friend classes
	friend class Cell;
	friend class Group;

	public:
		// constructor
		Board(char *fileName);

		// destructor
		~Board();

		// start calc
		void calc();

		// write to console
		void writeToConsole();

		// get status
		bool isReady();

	private:
		// define
		static const int STATUS_NOT_READY	= 0;
		static const int STATUS_READY		= 1;
		
		// status
		int status;
		
		// blank cell count
		int blankCellCount;

		// boardSize
		BoardSize *boardSize;

		// cells (N * M) * (M * N)
		Cell *cells;
		
		// groups (N * M) * 3 (3x3grp,1x9grp,9x1grp)
		Group *groups;

		// init cells
		void initCells();
		
		// delete cells
		void deleteCells();
		
		// init groups
		void initGroups();

		// delete groups
		void deleteGroups();

		// init BoardSize
		void initBoardSize(int x, int y);

		// delete boardsize
		void deleteBoardSize();

		// file reader
		int fileReader(char *fileName);

		// read file
		void readCellsByFile(FILE **fp);
		void readHeaderByFile(FILE **fp);

		// set status
		void changeToReady();

		// blank cell count init
		void blankCellCountInit();

		// blank cell val change
		inline void blankCellCountInc();
		inline void blankCellCountDec();

		// get cell by position
		Cell *getCellByPos(int x,int y);
		
		// cell value to char
		char cellValueToChar(int n);
};

// is ready func
inline bool Board::isReady(){
	return (this->status == this->STATUS_READY);
}

// change to ready func
inline void Board::changeToReady(){
	this->status = this->STATUS_READY;
}

// blank cell count increment
inline void Board::blankCellCountInc(){
	this->blankCellCount++;
}

// blank cell count decrement
inline void Board::blankCellCountDec(){
	this->blankCellCount--;
}

#endif

