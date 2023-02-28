#pragma once
#include "PIECE.h"

class KING : public PIECE
{
public:
	KING(char type, std::string curr);
	virtual bool isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8]) override;
};
