#ifndef GAMEBOARD_H
#define GAMEBOARD_H

enum PlayerTurn {FIRST_PLAYER=1,SECOND_PLAYER=2};
enum GameStatus { DRAW, WIN, IN_PROGRESS};
class GameBoard
{
private:	
	char data[3][3];
	GameStatus gameStatus = IN_PROGRESS;
	int validMovesCount = 0;
	void getPosition(char pos, int& r, int& c);
	int remainingMoves();
	GameStatus gameStat();
public:
	GameBoard();
	void displayBoard();
	void markBoard(char pos, char playerSymbol);
	void getplayersSymbol();
	bool isMarked(char pos);
	bool isValidPosition(char pos);
	bool isAlreadyMarked(char pos);
	int getValidMovesCount();
	GameStatus getGameStatus();
	
};


#endif
