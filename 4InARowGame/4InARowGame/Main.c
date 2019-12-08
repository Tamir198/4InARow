#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

/*************** Board ***************/
#define ROWS 6
#define COLS 7
char board[ROWS][COLS];



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


/*************** Main ****************/
int main(){
	initBoard();
	printBoard();
	system("pause");
}


/********** Implementations **********/
char getCell(int row, int col){
	return board[row - 1][col - 1];
}


void setCell(int row, int col, char sign){
	board[row - 1][col - 1] = sign;
}

void initBoard(){
	int i, j;
	for (i = 0; i < ROWS; i++){
		for (j = 0; j < COLS; j++){
			setCell(i + 1, j + 1, ' ');
		}

	}
}

void clearScreen(){
	system("cls");
}

void printBoard() {
	int i,j;
	char charArr[6] = { 'A','B', 'C', 'G', 'E', 'F'};

	printf("	1	2	3	4	5	6	7\n");

	for (i = 0; i < ROWS; i++) {
		printf("%c	", charArr[i]);
		for (j = 0; j < COLS; j++) {
			printf("y	");
		}
		printf("\n");
	}
}