// include system libs
#include <iostream>
#include <cstdlib>

// include user libs
#include "Board.hpp"

// using common functions
using std::cout;
using std::endl;
using std::exit;

// main function
int main(int argc,char *argv[]){
	// check argc value
	if(argc == 2){
		// create board 
		Board board(argv[1]);

		// calc start
		board.calc();

		// write to console 
		board.writeToConsole();
		
	}else{
		// print usage
		cout << "usage : sudoku-for-cpp file" << endl;

	}

	// end program
	exit(EXIT_SUCCESS);

}

