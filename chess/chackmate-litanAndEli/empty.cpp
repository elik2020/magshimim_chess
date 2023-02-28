#include "empty.h"


/**
the function is initializing the game empty player
input:the type, the current location
output: none
**/
empty::empty(char type, std::string curr) : PIECE(type, curr)
{
}


/**
the function checks if the empty player move is legal
input:the from and the goal location on the board
output: return true if legal and false if not
**/

bool empty::isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
	return (abs(toRow - fromRow) == abs(toCol - fromCol));
}
