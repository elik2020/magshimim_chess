#include "QUEEN.h"


/**
the function is initializing the game queen player
input:the type, the current location
output: none
**/
QUEEN::QUEEN(char type, std::string curr) : PIECE(type, curr)
{
}


/**
the function checks if the queen player move is legal
input:the from and the goal location on the board
output: return true if legal and false if not
**/

bool  QUEEN::isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{

	if (fromCol == toCol || fromRow == toRow)
	{
		return checkVertical(fromCol, fromRow, toCol, toRow, currBoard);
	}
	else if(abs(toRow - fromRow) == abs(toCol - fromCol))
	{
		return checkDiagonal(fromCol, fromRow, toCol, toRow, currBoard);
	}
	else
	{
		return false;
	}
}
