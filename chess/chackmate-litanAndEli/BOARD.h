#pragma once
#include "PIECE.h"
#include <string>

#define BOARD_SIZE 8

class PIECE;

class BOARD
{
public:
	BOARD();
	BOARD(const BOARD& b);
	//~BOARD();
	void printBoard();
	int move(std::string curr, std::string goal,int currTurn);
	int isMoveValid(int fromCol, int fromRow, int toCol, int toRow, int currTurn, PIECE* currBoard[8][8]);
	bool startEmpty(int fromCol, int fromRow, int currTurn, PIECE* currBoard[8][8]);
	bool samePlayer(int toCol, int toRow, int currTurn, PIECE* currBoard[8][8]);
	bool wrongIndex(int toCol, int toRow);
	bool isValidMove(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8]);
	bool isDestEqualSrc(int fromCol, int fromRow, int toCol, int toRow);
	bool isSelfCheck(int fromCol, int fromRow, int toCol, int toRow, int currTurn);
	bool isCheck(int currTurn);
	void getKingPosition(int* kingCol, int* kingRow, int color, PIECE* currBoard[8][8]);
	bool isCheckMate(int currTurn);
	std::string getBoardMessage();
private:
	PIECE* _board[BOARD_SIZE][BOARD_SIZE];
};
