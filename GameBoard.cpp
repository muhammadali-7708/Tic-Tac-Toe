#include <iostream>
#include "GameBoard.h"
using namespace std;

void GameBoard::getPosition(char pos, int& r, int& c)
{
	if (pos >= '1' && pos <= '9')
	{
		r = (pos - 49) / 3;
		c = (pos - 49) % 3;
	}
}

int GameBoard::remainingMoves()
{
	int movesCount = 0;
	for (int i = 0; i < 9; i++)
	{
		if ((data[0][i] >= '1') && (data[0][i] <= '9'))
		{
			movesCount++;
		}
	}
	return movesCount;
}

GameStatus GameBoard::gameStat()
{
	if (remainingMoves() == 0)
	{
		return DRAW;
	}
	else if (getValidMovesCount() != 0)
	{
		//Searching Rows
		if ((data[0][0] == data[0][1]) && (data[0][0] == data[0][2]))
		{
			return WIN;
		}
		if ((data[1][0] == data[1][1]) && (data[1][0] == data[1][2]))
		{
			return WIN;
		}
		if ((data[2][0] == data[2][1]) && (data[2][0] == data[2][2]))
		{
			return WIN;
		}

		//Searching Columns
		if ((data[0][0] == data[1][0]) && (data[0][0] == data[2][0]))
		{
			return WIN;
		}
		if ((data[0][1] == data[1][1]) && (data[0][1] == data[2][1]))
		{
			return WIN;
		}
		if ((data[0][2] == data[1][2]) && (data[0][2] == data[2][2]))
		{
			return WIN;
		}

		//Searching Diagonals
		if ((data[0][0] == data[1][1]) && (data[0][0] == data[2][2]))
		{
			return WIN;
		}
		if ((data[0][2] == data[1][1]) && (data[0][2] == data[2][0]))
		{
			return WIN;
		}
	}
	return IN_PROGRESS;
}



GameBoard::GameBoard()
{
	int charNum = 49;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] = charNum;
			charNum++;
		}
	}
}

void GameBoard::displayBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << " " << data[i][j] << " ";
			if (j < 2)
			{
				cout << "|";
			}
		}
		cout << '\n';
		if (i < 2)
		{
			cout << "---|---|---\n";
		}
	}
}

bool GameBoard::isValidPosition(char pos)
{
	int r, c;
	getPosition(pos, r, c);
	return ((data[r][c] >= '1') && (data[r][c] <= '9') ? true : false);
}

bool GameBoard::isAlreadyMarked(char pos)
{
	int r, c;
	getPosition(pos, r, c);
	if ((data[r][c] >= '1') && (data[r][c] <= '9'))
	{
		return true;
	}
	return false;
}

void GameBoard::markBoard(char pos, char playerSymbol)
{
	int r, c;
	getPosition(pos, r, c);
	if (isValidPosition(pos))
	{
		data[r][c] = playerSymbol;
	}
}


int GameBoard::getValidMovesCount()
{
	return remainingMoves();
}

GameStatus GameBoard::getGameStatus()
{	
	return gameStat();
}