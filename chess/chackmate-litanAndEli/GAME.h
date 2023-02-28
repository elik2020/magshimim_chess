#pragma once
#include "BOARD.h"



class GAME
{
public:
	GAME(BOARD* gameBoard);
	int handleMove(std::string move);
	void getBoardString(char* hold);
	void switchTurns();
	

private:
	int _currentTurn;
	BOARD* _gameBoard;
};
