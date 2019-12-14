#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


/*************** Board ***************/
#define ROWS 6
#define COLS 7
char board[ROWS][COLS];





/*********** Declarations ************/
char getCell(int row, int col);

void initBoard();
void setCell(int row, int col, char sign);
void clearScreen();
void printBoard();
void startGame();

int scanNumber(char c);
int chooseFreeSquare(int col);
int askPlayerInput(char c);
int getLastRow(int col);

bool PutCharOnBoard(int col, char c);
bool isColumNumberValid(int col);
bool isGameWon(int col, int row, char c);
bool isInsideTheArray(int row, int col);
//Checks for win
bool check_win_vertically(int col, int row, char c);
bool check_win_horizontally(int col, int row, char c);
bool check_win_diagnol_top_right_bottom_left(int col, int row, char c);
bool check_win_diagnol_top_left_bottom_right(int col, int row, char c);
bool is_board_full();

int main() {
	startGame();
	system("pause");
}

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
	for (i = 0; i <= ROWS - 1; i++) {
		printf("%c", charArr[i]);
		for (j = 0; j < COLS; j++) {
			printf("	%c", getCell(i + 1, j + 1));
		}
		printf("\n");
	}
}



bool PutCharOnBoard(int col, char c) {
	int x = chooseFreeSquare(col);
	setCell(x, col, c);
	clearScreen();
	printBoard();
	return true;
}


int chooseFreeSquare(int col) {
	int i;
	for (i = ROWS; i > 0; i--) {
		if (getCell(i, col) == ' ') {
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


int scanNumber(char c) {
	int col, row;
	scanf("%d", &col);
	if (isColumNumberValid(col) && chooseFreeSquare(col) > 0) {
		PutCharOnBoard(col, c);
		return col;
	}
	else {
		return scanNumber(c);
	}

}


bool isGameWon(int col, int row, char c) {
	return(check_win_vertically(col, row, c) ||
		check_win_horizontally(col, row, c) ||
		check_win_diagnol_top_right_bottom_left(col, row, c) ||
		check_win_diagnol_top_left_bottom_right(col, row, c));
}



void startGame() {
	char player1 = 'X', player2 = 'O', flag = 'f';
	int lastCol;
	initBoard();
	printBoard();

	while (true) {
		lastCol = askPlayerInput(player1);
		if (isGameWon(lastCol, getLastRow(lastCol), player1)) {
			printf("Player %c won", player1);
			scanf("%c", &flag);
			break;
		}
		if (is_board_full()) {
			printf("Board is full, press any key to start again");
			scanf("%c ", &flag);
			clearScreen();
			initBoard();
			printBoard();
			continue;
		}

		lastCol = askPlayerInput(player2);
		if (isGameWon(lastCol, getLastRow(lastCol), player2)) {
			printf("Player %c won", player2);
			scanf("%c ", &flag);
			break;
		}
		if (is_board_full()) {
			printf("Board is full, press any key to start again");
			scanf("%c ", &flag);
			clearScreen();
			initBoard();
			printBoard();
			continue;
		}
	}
}


bool check_win_vertically(int col, int row, char c) {
	//working (i + 1) and inside the  array
	int i, counter = 1;
	for (i = row + 1; i < row + 4; i++) {
		if (isInsideTheArray(row - 1, col) && c == getCell(i, col)) {
			counter++;
		}
		else {
			return false;
		}
	}
	return true;
}

bool check_win_horizontally(int col, int row, char c) {
	int i, counter = 1;
	// Right to left working and inside the array
	for (i = col - 1; i >= col - 3; i--) {
		if (isInsideTheArray(row - 1, i + 1) && c == getCell(row, i)) {
			counter++;
		}
		else {
			break;
		}
	}

	//left to right working and inside the array
	for (i = col + 1; i <= col + 3; i++) {
		if (isInsideTheArray(row - 1, i - 2) && c == getCell(row, i)) {
			counter++;
		}
		else {
			break;
		}
	}
	return counter > 3;
}
bool check_win_diagnol_top_right_bottom_left(int col, int row, char c) {
	////works and inside the array
	//Looks like working right to left and bottom
	int i, counter = 1;

	for (i = -1; i >= -4; i--) {

		if (isInsideTheArray(row + i, col - i) && c == getCell(row + i, col - i)) {
			counter++;
		}
		else {
			break;
		}
	}

	for (i = 1; i <= 4; i++) {
		if (c == getCell(row + i, col - i)) {
			counter++;
		}
		else {
			break;
		}
	}
	return counter > 3;
}
bool check_win_diagnol_top_left_bottom_right(int col, int row, char c) {
	int i, counter = 1;
	for (i = -1; i >= -4; i--) {
		if (c == getCell(row - i, col - i)) {
			counter++;
		}
		else {
			break;
		}
	}

	for (i = 1; i <= 4; i++) {
		if (c == getCell(row - i, col - i)) {
			counter++;
		}
		else {
			break;
		}
	}
	return counter > 3;
}

bool is_board_full() {
	int i;
	for (i = 1; i <= COLS; i++) {
		if (getCell(1, i) == ' ') {
			return false;
		}
	}
	return true;
}

int askPlayerInput(char c) {
	printf("Player %c \nPlease enter column input(number ranged 1 - 7) :\n ", c);
	return scanNumber(c);
}

int getLastRow(int col) {
	int i, lastFreeRow = ROWS;
	for (i = ROWS; i > 0; i--) {
		if (getCell(i, col) != ' ') {
			lastFreeRow = i;
		}
	}
	return lastFreeRow;
}

bool isInsideTheArray(int row, int col) {
	if (col < 0 || col > COLS - 1 || row < 0 || row > ROWS - 1) {
		return false;
	}
	else {
		return true;
	}
}