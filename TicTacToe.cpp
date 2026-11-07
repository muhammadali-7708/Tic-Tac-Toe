#include <iostream>
#include "GameBoard.h"
#include "TicTacToe.h"
GameBoard board;
using namespace std;

bool TicTacToe::isValidSymbol(char symbol)
{
	if (symbol >= '1' && symbol <= '9')
	{
		return false;
	}
	return true;
}
void TicTacToe::playGame()
{
	char player1Symbol, player2Symbol, symbol, pos;
	
	PlayerTurn playerTurn;
	GameStatus gamestat = IN_PROGRESS;

	do
	{
		cout << "Enter player 1 Symbol: ";
		cin >> player1Symbol;
	} while (!isValidSymbol(player1Symbol));
	
	symbol = player1Symbol;
	do
	{
		cout << "Enter player 2 Symbol: ";
		cin >> player2Symbol;
	} while ((!isValidSymbol(player2Symbol)) || (player2Symbol == player1Symbol));

	cout << '\n';
	board.displayBoard();
	playerTurn = FIRST_PLAYER;

	while (gamestat == IN_PROGRESS)             
	{
		do
		{
			cout << "Player " << playerTurn << " turn: Enter cell #: ";
			cin >> pos;
		} while (!(board.isValidPosition(pos)));

		board.markBoard(pos, symbol);
		
		gamestat = board.getGameStatus();

		if (gamestat == WIN)
		{
			cout << "\nGame WON by Player : " << playerTurn;
		}
		else if (gamestat == DRAW)
		{
			cout << "\nGame Draw";
		}
		else
		{
			board.displayBoard();
		}
		playerTurn = (playerTurn == FIRST_PLAYER ? SECOND_PLAYER : FIRST_PLAYER);
		symbol = (symbol == player1Symbol ? player2Symbol : player1Symbol);	
	}
	
}
