#include "P.h"
#include <iostream>



/**
the function is initializing the game P/p player
input:the type, the current location
output: none
**/

P::P(char type, std::string curr) : PIECE(type, curr)
{

}


/**
the function checks if the P player move is legal
input:the from and the goal location on the board
output: return true if legal and false if not
**/

bool P::isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
	
	if (this->getColor() == BLACK)
	{
		
		if (fromRow == 6) {
			return (((((fromRow - 2) == toRow) && (fromCol == toCol)) && currBoard[toRow][toCol]->getType() == '#') || ((((fromRow - 1) == toRow) && (fromCol == toCol)) && currBoard[toRow][toCol]->getType() == '#'))
				|| canEat(fromCol, fromRow, toCol, toRow, currBoard);
		}
		else
		{
			return ((((fromRow - 1) == toRow) && (fromCol == toCol))) || canEat(fromCol, fromRow, toCol, toRow, currBoard);
		}
		
	}
	else
	{
		if (fromRow == 1)
		{
			return (((((fromRow + 2) == toRow) && (fromCol == toCol)) && currBoard[toRow][toCol]->getType() == '#') || ((((fromRow + 1) == toRow) && (fromCol == toCol)) && currBoard[toRow][toCol]->getType() == '#'))
				|| canEat(fromCol, fromRow, toCol, toRow, currBoard);
		}
		else
		{
			return ((((fromRow + 1) == toRow) && (fromCol == toCol)) && currBoard[toRow][toCol]->getType() == '#') || canEat(fromCol, fromRow, toCol, toRow, currBoard);
		}
		
	}
	
}

bool P::canEat(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
	if (currBoard[fromRow][fromCol]->getColor() == BLACK)
	{
		return (currBoard[toRow][toCol]->getType() != '#' &&
			currBoard[toRow][toCol]->getColor() != currBoard[fromRow][fromCol]->getColor() &&
			(((fromRow - 1 == toRow) && (fromCol + 1 == toCol)) || ((fromRow - 1 == toRow) && (fromCol - 1 == toCol))));
	}
	else
	{
		return (currBoard[toRow][toCol]->getType() != '#' &&
			currBoard[toRow][toCol]->getColor() != currBoard[fromRow][fromCol]->getColor() &&
			(((fromRow + 1 == toRow) && (fromCol + 1 == toCol)) || ((fromRow + 1 == toRow) && (fromCol - 1 == toCol))));
	}
	

}
