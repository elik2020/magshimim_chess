#pragma once
#include "PIECE.h"

class empty : public PIECE
{
public:
	empty(char type, std::string curr);
	virtual bool isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8]) override;
};