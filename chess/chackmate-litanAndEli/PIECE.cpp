#include "PIECE.h"

/**
the function is initializing the piece
input:the piece type and location
output:none
**/
PIECE::PIECE(char type, std::string curr)
{
	this->_type = type;
	if (type == '#')
		this->_color = EMPTY_COLOR;
	else if (isupper(type)) 
		this->_color = WHITE;
	else 
		this->_color = BLACK;
	
	this->_curr = curr;
}


/**
the function return the piece color
input:none
output:the piece color
**/

int PIECE::getColor()
{
	return this->_color;
}

/**
the function return the piece type
input:none
output:the piece type
**/
char PIECE::getType()
{
	return this->_type;
}

/**
the function return the piece position
input:none
output:the piece position
**/
std::string PIECE::getCurrPosition()
{
	return this->_curr;
}

/**
the function set the piece position
input: the position to set
output:none
**/
void PIECE::setCurrPosition(std::string pos)
{
	_curr = pos;
}

/**
the function set the piece color
input: the color to set
output:none
**/
void PIECE::setColor(int color)
{
	_color = color;
}

/**
the function set the piece type
input: the type to set
output:none
**/
void PIECE::setType(char type)
{
	_type = type;
}


/**
the function check diagonal(if there is another piece between)
input: the from col and row, the goal col and row and the board
output:true if is and false if not
**/



bool PIECE::checkDiagonal(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
	int i = fromRow;
	int j = fromCol;
	if (fromRow > toRow) {
		if (toCol > fromCol) {
			for (int x = 0; x < 8;x++) {
				i--;
				j++;
				if (i == toRow && j == toCol) {
					break;
				}
				if (currBoard[i][j]->getType() != '#')
				{
					return false;
				}
			}
		}
		else
		{
			for (int x = 0; x < 8; x++) {
				i--;
				j--;
				if (i == toRow && j == toCol) {
					break;
				}
				if (currBoard[i][j]->getType() != '#')
				{
					return false;
				}
			}
		}
	}
	else if (toCol > fromCol)
	{
		for (int x = 0; x < 8; x++) {
			i++;
			j++;
			if (i == toRow && j == toCol) {
				break;
			}
			if (currBoard[i][j]->getType() != '#')
			{
				return false;
			}
		}
	}
	else
	{
		for (int x = 0; x < 8; x++) {
			i++;
			j--;
			if (i == toRow && j == toCol) {
				break;
			}
			if (currBoard[i][j]->getType() != '#')
			{
				return false;
			}
		}
	}
	return true;
}



/**
the function check Vertical(if there is another piece between)
input: the from col and row, the goal col and row and the board
output:true if is and false if not
**/


bool PIECE::checkVertical(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
	int i = fromRow;
	int j = fromCol;

	if (toCol == fromCol) {
		if (toRow > fromRow)
		{
			for (int x = 0; x < 8; x++) {
				i++;
				if (i == toRow) {
					break;
				}
				if (currBoard[i][j]->getType() != '#')
				{
					return false;
				}
			}
		}
		else
		{
			for (int x = 0; x < 8; x++) {
				i--;
				if (i == toRow) {
					break;
				}
				if (currBoard[i][j]->getType() != '#')
				{
					return false;
				}
			}
		}
	}
	else{
		if (toCol > fromCol)
		{
			for (int x = 0; x < 8; x++) {
				j++;
				if (j == toCol) {
					break;
				}
				if (currBoard[i][j]->getType() != '#')
				{
					return false;
				}
			}
		}
		else
		{
			for (int x = 0; x < 8; x++) {
				j--;
				if (j == toCol) {
					break;
				}
				if (currBoard[i][j]->getType() != '#')
				{
					return false;
				}
			}
		}
	}
	return true;
}