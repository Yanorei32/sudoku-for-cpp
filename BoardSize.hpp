// check
#ifndef SUDOKU_FOR_CPP_BOARD_SIZE_HPP
#define SUDOKU_FOR_CPP_BOARD_SIZE_HPP

// board size class
class BoardSize {
	private:
		// board size checker
		inline bool boardSizeChecker(int n,int m);

		// board size (N: horizonal,M: vertical)
		const int N,M;

		// dynamically generated constant value
		int NM,CELL_COUNT,GROUP_COUNT;

	public:
		// constructor
		BoardSize(int n,int m);

		// getters
		inline int getN();
		inline int getM();
		inline int getNM();
		inline int getMax();
		inline int getGroupCount();
		inline int getCellCount();
};

// board size checker
inline bool BoardSize::boardSizeChecker(int n,int m){return (2 <= n && 2<=m);}

// data getters
inline int BoardSize::getN(){return this->N;}
inline int BoardSize::getM(){return this->M;}
inline int BoardSize::getNM(){return this->NM;}
inline int BoardSize::getMax(){return this->NM;}
inline int BoardSize::getGroupCount(){return this->GROUP_COUNT;}
inline int BoardSize::getCellCount(){return this->CELL_COUNT;}

#endif

