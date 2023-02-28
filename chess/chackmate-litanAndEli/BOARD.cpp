#include "BOARD.h"
#include <iostream>

#include "B.h"
#include "KING.h"
#include "N.h"
#include "P.h"
#include "QUEEN.h"
#include "R.h"
#include "empty.h"

/**
the function initialize the board with the players
input:none
output: none
**/
BOARD::BOARD()
{ 
    P* p1 = new P('P', "a7");
    P* p2 = new P('P', "b7");
    P* p3 = new P('P', "c7");
    P* p4 = new P('P', "d7");
    P* p5 = new P('P', "e7");
    P* p6 = new P('P', "f7");
    P* p7 = new P('P', "g7");
    P* p8 = new P('P', "h7");

    P* p1b = new P('p', "a2");
    P* p2b = new P('p', "b2");
    P* p3b = new P('p', "c2");
    P* p4b = new P('p', "d2");
    P* p5b = new P('p', "e2");
    P* p6b = new P('p', "f2");
    P* p7b = new P('p', "g2");
    P* p8b = new P('p', "h2");


    empty* emp = new empty('#', "e");

    R* r1 = new R('R', "a8");
    N* n1 = new N('N', "b8");
    B* b1 = new B('B', "c8");
    KING* k = new KING('K', "d8");
    QUEEN* q = new QUEEN('Q', "e8");
    B* b2 = new B('B', "f8");
    N* n2 = new N('N', "g8");
    R* r2 = new R('R', "h8");

    R* r1b = new R('r', "a1");
    N* n1b = new N('n', "b1");
    B* b1b = new B('b', "c1");
    KING* kb = new KING('k', "d1");
    QUEEN* qb = new QUEEN('q', "e1");
    B* b2B = new B('b', "f1");
    N* n2B = new N('n', "g1");
    R* r2B = new R('r', "h1");

    _board[1][0] = p1;
    _board[1][1] = p2;
    _board[1][2] = p3;
    _board[1][3] = p4;
    _board[1][4] = p5;
    _board[1][5] = p6;
    _board[1][6] = p7;
    _board[1][7] = p8;

    _board[6][0] = p1b;
    _board[6][1] = p2b;
    _board[6][2] = p3b;
    _board[6][3] = p4b;
    _board[6][4] = p5b;
    _board[6][5] = p6b;
    _board[6][6] = p7b;
    _board[6][7] = p8b;
   
    _board[0][0] = r1;
    _board[0][1] = n1;
    _board[0][2] = b1;
    _board[0][3] = k;
    _board[0][4] = q;
    _board[0][5] = b2;
    _board[0][6] = n2;
    _board[0][7] = r2;

    _board[7][0] = r1b;
    _board[7][1] = n1b;
    _board[7][2] = b1b;
    _board[7][3] = kb;
    _board[7][4] = qb;
    _board[7][5] = b2B;
    _board[7][6] = n2B;
    _board[7][7] = r2B;

    for (int x = 2; x < 6; x++)
    {
        for (int y = 0; y < BOARD_SIZE; y++)
        {
            _board[x][y] = emp;
        }
    }

}


/**
the function initialize the board by the board giving in the parameters
input:the board
output: none
**/

BOARD::BOARD(const BOARD& b)
{
    for (int x = 0; x < BOARD_SIZE; x++)
    {
        for (int y = 0; y < BOARD_SIZE; y++)
        {
            _board[x][y] = b._board[x][y];
        }
    }
}
//BOARD::~BOARD()
//{
//    /*for (int i = 0; i < BOARD_SIZE; i++)
//    {
//        for (int j = 0; j < BOARD_SIZE; j++)
//        {
//            delete _board[i][j];
//        }
//    }
//    delete[] _board;*/
//   
//}



/**
the function moves a player in the board(and check if the move can be done)
input:the from and the goal location on the board, the current turn (black or white)
output: return  the move status (number from 1-8)
**/
int BOARD::move(std::string curr, std::string goal, int currTurn)
{
    
    
    empty* emp = new empty('#', "fo");

    int fromCol = (curr[0] - 'a');
    int fromRow = ('8' - curr[1]);

    int toCol = (goal[0] - 'a');
    int toRow = ('8' - goal[1]);

    int moveStatus = isMoveValid(fromCol, fromRow, toCol, toRow, currTurn,_board);
    if (moveStatus == 0) {
        if (isSelfCheck(fromCol, fromRow, toCol, toRow, currTurn)) moveStatus = 4;
    }
    
    //std::cout << "\n";
    //std::cout << "from new: " << fromRow <<","<< fromCol << " to new: " << toRow << ","<< toCol;
    //std::cout << "\n";

    //std::cout << "we here at lest " << moveStatus;
    //std::cout << "\n";
    if (moveStatus == 0)
    {
        //std::cout << fromRow << " " << fromCol << " " << toRow << " " << toCol;
        _board[toRow][toCol] = _board[fromRow][fromCol];
        _board[fromCol][fromRow]->setCurrPosition(goal);
        _board[fromRow][fromCol] = emp;
    }

    if (isCheck(currTurn) && moveStatus == 0)
    {
        std::cout << "\n";
        std::cout << "check hi hi ha";
        std::cout << "\n";
        if (isCheckMate(currTurn))
        {
            moveStatus = 8;
        }
        else
        {
            moveStatus = 1;
        }
        
    }
    //std::cout << "and what we got " << moveStatus;
    return moveStatus;
}


/**
the function checks if the move is valid(legal)
input:the from and the goal location on the board, the current turn, the board
output: return (number between 2-7)
**/

int BOARD::isMoveValid(int fromCol, int fromRow, int toCol,int toRow,int currTurn, PIECE* currBoard[8][8])
{
    
    if (startEmpty(fromCol, fromRow, currTurn, currBoard)) return 2;
    if (samePlayer(toCol, toRow, currTurn, currBoard)) return 3;
    if (wrongIndex(toCol, toRow)) return 5;
    if (!isValidMove(fromCol, fromRow, toCol, toRow, currBoard)) return 6;
    
    if (isDestEqualSrc(fromCol, fromRow, toCol, toRow)) return 7;

    return 0;
}

/**
the function checks if the player entered a wrong index
input:the from and the goal location on the board
output: return true if legal and false if not
**/
bool BOARD::wrongIndex(int toCol, int toRow)
{
    return (toCol < 0 || toCol > 7 || toRow < 0 || toRow > 7); //array starts from 0
}

/**
the function checks if the player did a self check 
input:the from and the goal location on the board
output: return true if he did and false if he did not
**/
bool BOARD::isSelfCheck(int fromCol, int fromRow, int toCol, int toRow,int currTurn)
{
    BOARD* compyBoard = new BOARD(*this);
    empty* emp = new empty('#', "f");
    int kingCol = 0;
    int kingRow = 0;


    compyBoard->_board[toRow][toCol] = compyBoard->_board[fromRow][fromCol];
    compyBoard->_board[fromRow][fromCol] = emp;

   getKingPosition(&kingCol, &kingRow, currTurn, compyBoard->_board);


    /*std::cout << "\n";
    std::cout << "curr board:\n";
    this->printBoard();
    std::cout << "\n";
    std::cout << "\n";*/

    




    compyBoard->_board[toRow][toCol] = compyBoard->_board[fromRow][fromCol];
    compyBoard->_board[fromRow][fromCol] = emp;

    /*std::cout << "\n";
    std::cout << "copy bord:\n";
    compyBoard->printBoard();
    std::cout << "\n";
    std::cout << "\n";*/


   getKingPosition(&kingCol, &kingRow, currTurn, compyBoard->_board);
   /*std::cout << "\n";
   std::cout << "king: " << currTurn << kingRow << " " << kingCol << " ";
   std::cout << "\n";*/
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // inner loop for column
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (compyBoard->_board[i][j]->getType() != '#')
            {
                if (compyBoard->_board[i][j]->getColor() != currTurn) {
                    if (isMoveValid(j, i, kingCol, kingRow, compyBoard->_board[i][j]->getColor(), compyBoard->_board) == 0) {
                        return true;
                    }
                }
            }

        }
    }

    return false;

}


/**
the function checks if the player did a check
input:the current location on the board
output: return true if he did and false if he did not
**/

bool BOARD::isCheck(int currTurn)
{
    int kingCol = 0;
    int kingRow = 0;




    getKingPosition(&kingCol, &kingRow, currTurn == WHITE ? BLACK : WHITE, _board);
    
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // inner loop for column
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (_board[i][j]->getType() != '#')
            {
                if (_board[i][j]->getColor() == currTurn) {
                    if (isMoveValid(j, i, kingCol, kingRow, currTurn, _board) == 0) {
                        std::cout << "\n";
                        std::cout << "king: t" << currTurn<< " r:" << kingRow << " c:" << kingCol << " ";
                        std::cout << "\n";
                        std::cout << _board[i][j]->getCurrPosition();
                        return true;
                    }
                }
            }

        }
    }
    return false;
}

/**
the function return(by value) the king's position by his color and column and row
input:the king col and row, the color, and the board
output:none
**/
void BOARD::getKingPosition(int* kingCol,int* kingRow,int color, PIECE* currBoard[8][8]) {
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // inner loop for column
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (currBoard[i][j]->getType() != '#')
            {
                if ((currBoard[i][j]->getType() == 'k' && color == BLACK) || (currBoard[i][j]->getType() == 'K' && color == WHITE))
                {
                    *kingRow = i;
                    *kingCol = j;

                }
            }

        }
    }
}


/**
the function checks if the board on the start is empty by the player
input:the from col and row, the current turn and the board
output:if board was empty or not
**/
    

bool BOARD::startEmpty(int fromCol,int fromRow, int currTurn, PIECE* currBoard[8][8])
{
    //std::cout << _board[fromRow][fromCol]->getType() << "\n";
    /*std::cout << "\n";
    std::cout << fromRow << " " << fromCol << " " << currTurn << " ";
    std::cout << _board[fromRow][fromCol]->getType();
    std::cout << "\n";*/

    if (currBoard[fromRow][fromCol]->getColor() != currTurn || currBoard[fromRow][fromCol]->getType() == '#')
        return true;
    else 
        return false;
    
}


/**
the function return if the move wad valid or not
input:the from col and row and dest col and row and the board
output:true if valid, false if not
**/

bool BOARD::isValidMove(int fromCol, int fromRow, int toCol, int toRow, PIECE* currBoard[8][8])
{
    return currBoard[fromRow][fromCol]->isLeagle(fromCol, fromRow, toCol, toRow, currBoard);
}

/**
the function return if the player tried to move to the same location
input:the from col and row and dest col and row 
output:true if equal, false if not
**/
bool BOARD::isDestEqualSrc(int fromCol, int fromRow, int toCol, int toRow)
{
    return (fromCol == toCol && fromRow == toRow);

}


/**
the function return if in the dest location there is a player of his color
input:the from col and row and dest col and row and the board
output:true if same, false if not
**/

bool BOARD::samePlayer(int toCol, int toRow, int currTurn, PIECE* currBoard[8][8])
{
    //std::cout << _board[toRow][toCol]->getType() << "\n";


    if (currBoard[toRow][toCol]->getColor() == currTurn)
        return true;
   
    else 
        return false;
    
}


/**
the function return if the chack is math
input:the current trun
output:true if was, false if not
**/

bool BOARD::isCheckMate(int currTurn)
{
    int color = (currTurn == WHITE ? BLACK : WHITE);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (_board[i][j]->getColor() == color && _board[i][j]->getType() != '#')
            {
                for (int x = 0; x < BOARD_SIZE; x++)
                {
                    for (int y = 0; y < BOARD_SIZE; y++)
                    {
                        if (isMoveValid(j, i, y, x, color,_board) == 0)
                        {
                            if (!isSelfCheck(j, i, y, x, color))
                            {
                                return false;
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return true;
}



/**
the function Print the state of the current chess board 
input:none
output:none
**/
void BOARD::printBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // inner loop for column
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::cout << _board[i][j]->getType() << " ";
        }
        std::cout << "\n"; // new line
    }
}


/**
the function return the board string
input:none
output:the board string
**/



std::string BOARD::getBoardMessage()
{
    std::string message = "";

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // inner loop for column
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            message += _board[i][j]->getType();
        }
       
    }

    return message;
}
