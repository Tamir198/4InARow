#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

/*************** Board ***************/
#define ROWS 6
#define COLS 7
char board[ROWS][COLS];

const char firstPlayerChar = 'X';
const char secondPlayerChar = 'O';
const char enter = '\n';
const char charArr[6] = { 'A','B', 'C', 'G', 'E', 'F' };


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


/*************** Main ****************/
int main(){
	initBoard();
	printBoard();
	askPlayer1Input();
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
	
	printf("	1	2	3	4	5	6	7 %c", enter);
	for (i = 0; i < ROWS; i++) {
		printf("%c", charArr[i]);
		for (j = 0; j < COLS; j++) {
			printf("	y");
			setCell(i + 1, j + 1, 'x');
		}
		printf("\n");
	}
}

void askPlayer1Input() {
	int selection;
	char str[] = "Please enter column input (a number between 1-7):";
	printf("Player number 1:");
	printf("%s %c", str, enter);
	scanf("%d",&selection);
	printf("\n %d ",selection);

	askPlayer2Input();

}

void askPlayer2Input() {
	int selection;
	char str[] = "Please enter column input (a number between 1-7):";
	printf("Player number 2:");
	printf("%s %c", str, enter);
	scanf("%d", &selection);
	printf("\n %d ", selection);

}
