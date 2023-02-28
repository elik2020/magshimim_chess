#include "N.h"


/**
the function is initializing the game N/n player
input:the type, the current location
output: none
**/
N::N(char type, std::string curr) : PIECE(type, curr)
{
	
}


/**
the function checks if the N player move is legal
input:the from and the goal location on the board
output: return true if legal and false if not
**/

bool N::isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
	return(abs(fromRow - toRow) == 2 && abs(fromCol - toCol) == 1) || (abs(fromRow - toRow) == 1 && abs(fromCol - toCol) == 2);
}
