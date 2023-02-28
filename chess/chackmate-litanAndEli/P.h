#pragma once
#include "PIECE.h"

class P : public PIECE
{
public:
	P(char type, std::string curr);
	virtual bool isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8]) override;
	bool canEat(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8]);

};