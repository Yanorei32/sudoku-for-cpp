// Include Userlib
#include "BoardSize.hpp"

// include system libs
#include <cassert>

// constructor
BoardSize::BoardSize(int n,int m):N(n),M(m){
	this->NM = this->N * this->M;
	this->GROUP_COUNT = this->NM * 3;
	this->CELL_COUNT = this->N * this->M * this->M * this->N;
	assert(this->boardSizeChecker(this->N,this->M));
}

