#include "R.h"
#include <iostream>

/**
the function is initializing the game R/r player
input:the type, the current location
output: none
**/

R::R(char type, std::string curr) : PIECE(type, curr)
{
}


/**
the function checks if the R player move is legal
input:the from and the goal location on the board
output: return true if legal and false if not
**/

bool R::isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
	if (fromCol == toCol || fromRow == toRow)
	{
		/*std::cout << "\n";
		std::cout << "we checkt one right";
		std::cout << "\n";*/
		return checkVertical(fromCol, fromRow, toCol, toRow, currBoard);
	}
	else {
		return false;
	}
}
