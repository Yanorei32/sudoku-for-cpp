// Include Systemlib
#include <iostream>
#include <cstdlib>

// Include Userlib
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
		for(int i= 0;i < 9;i++){
			cout << i/3 << endl;
		}
		// Board Read File
	//	board.readFile(argv[1]);

		// Calc Start
		board.calc();

	}else{
		cout << "Usage : " << argv[0] << " file" << endl;
	}

	// End Program
	exit(EXIT_SUCCESS);
}
