#include "B.h"
#include <cmath> 


/**
the function is initializing the game B/b player
input:the type, the current location
output: none
**/
B::B(char type, std::string curr) : PIECE(type, curr)
{
}



/**
the function checks if the B  player move is legal
input:the from and the goal location on the board
output: return true if legal and false if not
**/

bool B::isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
	
	if (abs(toRow - fromRow) == abs(toCol - fromCol))
	{
		return checkDiagonal(fromCol,fromRow,toCol,toRow,currBoard);
	}
	else
	{
		return false;
	}
	
}
