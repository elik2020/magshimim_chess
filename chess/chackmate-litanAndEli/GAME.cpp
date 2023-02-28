#include "GAME.h"
#include <iostream>


/**
the function is initializing the game fields
input:the game board
output: none
**/

GAME::GAME(BOARD* gameBoard)
{
	_currentTurn = 0;
	_gameBoard = gameBoard;
}


/**
the function is checking if the move is valid. if it is, its switching turns.
input:the move the player wants to make
output: none
**/

int GAME::handleMove(std::string move)
{
	int status;
	char from[3] = {0};
	char to[3] = {0};

	//std::cout << "move : " << move;

	from[0] = move[0];
	from[1] = move[1];

	to[0] = move[2];
	to[1] = move[3];

	//std::cout << "from : "<< from << " to: "<< to ;

	status = _gameBoard->move(from, to,_currentTurn);

	if (status == 0 || status == 1 || status == 8) switchTurns();

	return status;
}


/**
the function is switching turns.
input:none
output: none
**/

void GAME::switchTurns()
{
	_currentTurn = (_currentTurn == BLACK ? WHITE : BLACK);
}


/**
the function is initializing the new board to send to the fronted
output: none
**/

void GAME::getBoardString(char* hold)
{
	char boardString[66] = { 0 };
	std::string partMessage = _gameBoard->getBoardMessage();

	for (int i = 0; i < 64; i++)
	{
		hold[i] = partMessage[i];
	}

	hold[64] = (_currentTurn == BLACK ? 49 : 48);
	hold[65] = 0;

}