#include "BoardSize.hpp"

// Constructor
BoardSize::BoardSize(int n,int m):N(n),M(m){
	assert(this->boardSizeChecker(this->N,this->M));
	this->MAX = this->N * this->M;
}

