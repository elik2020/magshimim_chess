#include "KING.h"
#include <cmath> 


/**
the function is initializing the game king player
input:the type, the current location
output: none
**/
KING::KING(char type, std::string curr) : PIECE(type, curr)
{
}

/**
the function checks if the king player move is legal
input:the from and the goal location on the board
output: return true if legal and false if not
**/

bool KING::isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
	return(abs(fromRow - toRow) <= 1 && abs(fromCol - toCol) <= 1);
}
