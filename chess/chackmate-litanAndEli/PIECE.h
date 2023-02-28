#pragma once
#include "BOARD.h"
#include <string>
class BOARD;

enum { WHITE, BLACK, EMPTY_COLOR};

class PIECE
{
public:
	PIECE(char type, std::string curr);
	//virtual ~PIECE();
	int getColor();
	char getType();
	//virtual char getSorB(char type); //by the type and color
	void setColor(int color);
	void setType(char type);
	std::string getCurrPosition();
	void setCurrPosition(std::string pos);
	//virtual void move(std::string curr, std::string goal,BOARD b);
	virtual bool isLeagle(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8]) = 0;
	bool checkDiagonal(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8]);
	bool checkVertical(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8]);
private:
	int _color;
	char _type;
	std::string _curr;
};
