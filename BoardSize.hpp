#ifndef BOARD_SIZE_HPP
#define BOARD_SIZE_HPP

// Include Systemlib
#include <cassert>

// BoardSize Class
class BoardSize {
	private:
		// Board Size Checker
		inline bool boardSizeChecker(int n,int m);

		// Board Size (N: Horizonal,M: Vertical)
		const int N,M;

		// NM Val
		int NM;

		// Cell Count
		int CELL_COUNT;

		// Group Count
		int GROUP_COUNT;
		
	public:
		// Constructor
		BoardSize(int n,int m);

		// Getter
		inline int getN();
		inline int getM();
		inline int getNM();
		inline int getMax();
		inline int getGroupCount();
		inline int getCellCount();
};

// BoardSize Checker
inline bool BoardSize::boardSizeChecker(int n,int m){return (2 <= n && 2 <= m);}

// BoardSize Getter
inline int	BoardSize::getN(){return this->N;}
inline int	BoardSize::getM(){return this->M;}
inline int	BoardSize::getNM(){return this->NM;}
inline int	BoardSize::getMax(){return this->NM;}
inline int	BoardSize::getGroupCount(){return this->GROUP_COUNT;}
inline int	BoardSize::getCellCount(){return this->CELL_COUNT;}

#endif

