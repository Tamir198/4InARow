#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


/*************** Board ***************/
#define ROWS 6
#define COLS 7
char board[ROWS][COLS];

//const char p1[] = "Player number 1:";
//const char p2[] = "Player number 2:";
//const char p1Char = 'X';
//const char p2Char = 'O';



#pragma region Declarations



/*********** Declarations ************/

/// This function initializes the game board by assigning each cell
/// with ' ' (resulting with an empty game board).
void initBoard();

/// This function gets a row number and a column number (a cell),
/// and returns the character in that cell (could be 'X', 'O' or ' ').
/// For example:
/// char c = getCell(1, 1);
char getCell(int row, int col);

/// This function gets a row number, a column number and a sign,
/// and assigns the cell with the given sign.
/// For example:
/// setCell(1, 1, 'X');
void setCell(int row, int col, char sign);

/// This function clears the screen.
void clearScreen();

void printBoard();
void startGame();
void scanNumber(char c);
void askPlayer1Input();
void askPlayer2Input();

bool PutCharOnBoard(int col, char c);
bool isColumNumberValid(int col);
bool isColumFull(int col);
bool gameWon();
bool noWinners();

int chooseFreeSquare(int col);
#pragma endregion
/*************** Main ****************/
int main() {
	startGame();
	//manual testing 
	system("pause");

}


/********** Implementations **********/
char getCell(int row, int col) {
	return board[row - 1][col - 1];
}


void setCell(int row, int col, char sign) {
	board[row - 1][col - 1] = sign;
}

void initBoard() {
	int i, j;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			setCell(i + 1, j + 1, ' ');
		}
	}
}

void clearScreen() {
	system("cls");
}

void printBoard() {
	int i, j;
	char charArr[6] = { 'A','B', 'C', 'G', 'E', 'F' };
	printf("	1	2	3	4	5	6	7 \n");
	for (i = 1; i <= ROWS; i++) {
		printf("%c", charArr[i]);
		for (j = 1; j <= COLS; j++) {
			//printf("	y");
			printf("	%c", getCell(i, j));
		}
		printf("\n");
	}
}

void askPlayer1Input() {
	printf("Player 1 \nPlease enter column input(number ranged 1 - 7) : 	 \n ");
	scanNumber('X');

	//todo game win or not condition 
	askPlayer2Input();
}

void askPlayer2Input() {
	printf("Player 2 \nPlease enter column input(number ranged 1 - 7) : 	 \n ");
	scanNumber('O');

	//todo game win or not condition 
	askPlayer1Input();
}

bool PutCharOnBoard(int col, char c) {
	if (isColumNumberValid(col)) {
		int x = chooseFreeSquare(col);
		setCell(x, col, c);
		clearScreen();
		printBoard();
		return true;
	}else {
		printf("Colum number is not valid");
		return false;
	}

}


int chooseFreeSquare(int col) {
	int i;
	//todo fix wrong return value
	for (i = 6; i > 0; i--) {
		if (getCell(i, col) == ' ') {
			//F is 5 and A is 0 on the board
			return i;
		}
	}
	
	printf("Colum is full");
	return 0;
}

bool isColumNumberValid(int col) {
	if (col > 7 || col < 0) {
		printf("Out of 1-7 range \n");
		return false;
	}
	return true;
}


bool isColumFull(int col) {
	//todo fill method
	return false;
}

void scanNumber(char c) {
	int col;
	scanf("%d", &col);
	if (isColumNumberValid(col)) {
		PutCharOnBoard(col, c);
	}
	else {
		scanNumber(c);
	}

}

bool gameWon() {
	//todo fill method
	return true;
}

bool noWinners() {
	//todo fill method
	return false;
}

void startGame() {
	initBoard();
	printBoard();
	askPlayer1Input();
	askPlayer2Input();

}

