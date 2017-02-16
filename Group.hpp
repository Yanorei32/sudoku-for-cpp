#ifndef GROUP_HPP
#define GROUP_HPP

// Include Systemlib
#include <iostream>

// Include Userlib
#include "BoardSize.hpp"
#include "Cell.hpp"

// Usings
using std::cout;
using std::endl;

class Cell;

// Group Class
class Group {
	private:
		// Private Define
		static const int GROUP_TYPE_BRANK = -1;

		// Cell
		Cell *relateCells;

		// BoardSize
		BoardSize *boardSize = NULL;
		
		// Type
		int groupType = GROUP_TYPE_BRANK;
		
	public:
		// DEFINE
		static const int HR_GROUP	= 0;
		static const int VT_GROUP	= 1;
		static const int NM_GROUP	= 2;

		// Value Getter and Setter
		inline void	setBoardSize(BoardSize *boardSize);

		// Set Group Type
		inline void setGroupType(int groupType);
};

// Board Size Setter
inline void Group::setBoardSize(BoardSize *boardSize){
	// Warn
	if(this->boardSize != NULL)
		cout << "WARN: OverWrite boardSize Pointer" << endl;
	// Write
	this->boardSize = boardSize;
}

// Set Group Type 
inline void Group::setGroupType(int groupType){
	// Warn
	if(this->groupType != GROUP_TYPE_BRANK)
		cout << "WARN: OverWrite Group Type" << endl;
	// Write
	this->groupType = groupType;
}


#endif
