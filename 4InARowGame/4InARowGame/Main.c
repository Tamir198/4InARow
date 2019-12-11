#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


/*************** Board ***************/
#define ROWS 6
#define COLS 7
char board[ROWS][COLS];

const char firstPlayerChar = 'X';
const char secondPlayerChar = 'O';
const char enter = '\n';
const char charArr[6] = { 'A','B', 'C', 'G', 'E', 'F' };

//Erros
const char outOfRange[] = "Out of 1-7 range \n";
const char columIsFull[] = "Colum is full, chose another \n";
const char enterColNumber[47] = "Please enter column input (number ranged 1-7): ";
//Players
const char p1[] = "Player number 1:";
const char p2[] = "Player number 2:";
const char p1Char = 'X';
const char p2Char = 'O';



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
void askPlayer1Input();
void askPlayer2Input();
void PutCharOnBoard(int col, char c);

bool isColumNumberValid(int col);
bool isColumFull(int col);

void scanNumber(char c);
int chooseFreeSquare(int col);
bool gameWon();
bool noWinners();

#pragma endregion
/*************** Main ****************/
int main() {
	initBoard();
	printBoard();
	askPlayer1Input();
	askPlayer2Input();

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
	printf("	1	2	3	4	5	6	7 %c", enter);
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
	printf("%s \n%s	 %c ", p1, enterColNumber, enter);
	scanNumber(p1Char);
}

void askPlayer2Input() {
	printf("%s \n%s	 %c ", p2, enterColNumber, enter);
	scanNumber(p2Char);
}

void PutCharOnBoard(int col, char c) {
	//todo change setcell to add to the next cell if cell is taken
	int x = chooseFreeSquare(col);
	/*int x = 5;*/
	setCell(x, col, c);
	clearScreen();
	printBoard();
	//Printing is working and adding the value to the cell also 
	//todo print this on the place in the board
}


int chooseFreeSquare(int col) {
	int i;
	//todo fix wrong return value
	for (i = 6; i > 0; i--) {
		//printf("this is test %d", getCell(col, i));
		if (getCell(i, col) == ' ') {
			//F is 5 and A is 0 on the board
			return i;
		}
	}
}

bool isColumNumberValid(int col) {
	if (col > 7 && col < 0) {
		printf("%s", outOfRange);
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
		printf(outOfRange);
		scanNumber(c);
	}

}

bool gameWon() {
	//todo fill method
	return false;
}

bool noWinners() {
	//todo fill method
	return false;
}

