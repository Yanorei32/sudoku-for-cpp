// libs
#include <iostream>
#include <cstdlib>
#include "BoardSize.hpp"
#include "Board.hpp"

// using common function 
using std::cout;
using std::endl;
using std::exit;

// main function
int main(int argc,char *argv[]){
	if(argc == 2){
		// Create BoardSize
		BoardSize boardSize(3,3);

		// Call Board
		Board board(&boardSize);
		
		// Board Read File
	//	board.readFile(argv[1]);

		// Calc Start
	//	board.start();

	}else{
		cout << "Usage : " << argv[0] << " file" << endl;
	}

	// End Program
	exit(EXIT_SUCCESS);
}
