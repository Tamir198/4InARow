#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


/*************** Board ***************/
#define ROWS 6
#define COLS 7
char board[ROWS][COLS];

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

bool PutCharOnBoard(int col, int row, char c);
bool isColumNumberValid(int col);
bool isColumFull(int col);
bool isGameWon(int col, int row, char c);
bool isTie();
int chooseFreeSquare(int col);
#pragma endregion
int n = 4;
char c = 'X';
//Checks for win
bool check_win_vertically(int col, int row, char c);
bool check_win_horizontally(int col, int row, char c);
bool check_win_diagnol_top_right_bottom_left(int col, int row, char c);
bool check_win_diagnol_top_left_bottom_right(int col, int row, char c);
bool is_board_full(int col, int row, char c);





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
	for (i = 0; i <= ROWS-1; i++) {
		printf("%c", charArr[i]);
		for (j = 0; j < COLS; j++) {
			//printf("	y");
			printf("	%c", getCell(i+1, j+1));
		}
		printf("\n");
	}
}

void askPlayer1Input() {
	printf("Player 1 \nPlease enter column input(number ranged 1 - 7) : 	 \n ");
	scanNumber('X');
}

void askPlayer2Input() {
	printf("Player 2 \nPlease enter column input(number ranged 1 - 7) : 	 \n ");
	scanNumber('O');
}

bool PutCharOnBoard(int col, int row, char c) {
	if (isColumNumberValid(col)) {
		int x = chooseFreeSquare(col);
		setCell(x, col, c);
		clearScreen();
		printBoard();
		isGameWon(col, row, c);
		return true;

	}
	else {
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
	int col, row;
	scanf("%d", &col);
	if (isColumNumberValid(col)) {
		row = chooseFreeSquare(col);
		PutCharOnBoard(col, row, c);
		isGameWon(col, row, c);
	}
	else {
		scanNumber(c);
	}

}

bool isGameWon(int col, int row, char c) {
	return (
		check_win_vertically(col, row, c) ||
		check_win_horizontally(col, row, c) ||
		check_win_diagnol_top_right_bottom_left(col, row, c) ||
		check_win_diagnol_top_left_bottom_right(col, row, c));
}



void startGame() {
	initBoard();
	printBoard();

	askPlayer1Input();
	askPlayer2Input();

	//while (!isGameWon(5,'O')) {
	while (true) {

		if (isTie()) {
			//printf("Tie ");
			askPlayer1Input();
			askPlayer2Input();
		}

	}
}


//Todo fill methods

bool isTie() {
	//todo fill method
	if (true) {
		return true;
	}
	return false;
}

bool check_win_vertically(int col, int row, char c) {

	int i, counter = 1;
	for(i = row+1; i <= row +3; i++){
		if (c == getCell(i, col)) {
			counter++;
		}else {
			return false;
		}
	}
	return true;
}

bool check_win_horizontally(int col, int row, char c) {
	int i, counter = 1;
	for (i = col - 1; i >= col - 3; i--) {
		if (c == getCell(row, i)) {
			counter++;
		}
		else {
			break;
		}
	}

	for (i = col + 1; i <= col + 3; i++) {
		if (c == getCell(row, i)) {
			counter++;
		}
		else {
			break;
		}
	}
	return (counter == 4);
}
bool check_win_diagnol_top_right_bottom_left(int col, int row, char c) {
	int i, counter = 1;
	for (i = - 1 ; i >= - 4 ; i--) {
		if (c == getCell(row + i, col + i)) {
			counter++;
		}
		else {
			break;
		}
	}

	for (i = 1; i <= 4; i++) {
		if (c == getCell(row + i, col + i)) {
			counter++;
		}
		else {
			break;
		}
	}
	printf("top_right_bottom_left  %d \n" , counter);
	return (counter == 4);
}
bool check_win_diagnol_top_left_bottom_right(int col, int row, char c) {
	int i, counter = 1;
	for (i = -1; i >= -4; i--) {
		if (c == getCell(row + i, col - i)) {
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

	printf("top_left_bottom_right  %d \n", counter);
	return (counter == 4);
}

bool is_board_full(int col, int row, char c) {
	if (true) {
		return true;
	}
	return false;
}

