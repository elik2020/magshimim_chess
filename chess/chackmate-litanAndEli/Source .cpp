/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "BOARD.h"
#include "GAME.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::string;


/**
the function is starting the game and printing the board
input:none
output: none
**/

void console()
{
	BOARD game;
	std::cout << "hi user! we are starting the game. here is the board:\n";
	game.printBoard();
}

/**
the function is the main game
input:none
output: none
**/

void main()
{
	console();
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	GAME* g = new GAME(new BOARD());
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	g->getBoardString(msgToGraphics);
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		

		
		int status = g->handleMove(msgFromGraphics);
		msgToGraphics[0] = (char)(status + '0');
		msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}