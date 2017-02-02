#include <cassert>

#ifndef BOARD_SIZE
#define BOARD_SIZE

// BoardSize Class
class BoardSize {
	public:
		// Constructor
		BoardSize(int n,int m);

		// Getter
		inline int getN();
		inline int getM();
		inline int getMax();
	private:
		// Board Size Checker
		inline bool boardSizeChecker(int n,int m);

		// Board Size
		const int N,M;

		// N,M MaxVal
		int MAX;
};

// BoardSize Checker
inline bool BoardSize::boardSizeChecker(int n,int m){return (2 <= n && 2 <= m);}

// BoardSize Getter
inline int	BoardSize::getN(){return this->N;}
inline int	BoardSize::getM(){return this->M;}
inline int	BoardSize::getMax(){return this->MAX;}


#endif

