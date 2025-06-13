
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define H 3
#define W 3
//A two dimensional board where the user can press {W,A,S,D} to move a symbol in the board

//Take input

//Keep track of the symbols location

//We should draw the board with the symbol in correct position

//Use getchar() instead of scanf() for input

void printBoard(char board[H][W]); //function declaration

int main() {


	//The game board is actually a matrix;

	char board[H][W] = { {'$',' ',' '},{' ',' ',' '},{' ',' ',' '} };
	int position[2] = {0,0}; // row and column of the symbol 
	printBoard(board);
	int pressedButton;
	
	while (pressedButton = _getch()) {
		
		switch (pressedButton) {

		case 'w':

			//erase from where it was

			board[position[0]][position[1]] = ' ';

			//then write to where it will go
			//Cartesian coordinate system convention is x position first y position next
			//in matrices it is the row number first column number next in indices
			
			board[position[0]-1][position[1]] = '$';
			position[0]--;
			break;
		
		case 's':

			//erase from where it was

			board[position[0]][position[1]] = ' ';

			//then write to where it will go
			//Cartesian coordinate system convention is x position first y position next
			//in matrices it is the row number first column number next in indices
			board[position[0] + 1][position[1]] = '$';
			position[0]++;
			break;



		case 'a':

			//erase from where it was

			board[position[0]][position[1]] = ' ';

			//then write to where it will go
			//Cartesian coordinate system convention is x position first y position next
			//in matrices it is the row number first column number next in indices
			board[position[0]][position[1]-1] = '$';
			position[1]--;
			break;

		case 'd':

			//erase from where it was

			board[position[0]][position[1]] = ' ';

			//then write to where it will go
			//Cartesian coordinate system convention is x position first y position next
			//in matrices it is the row number first column number next in indices
			board[position[0]][position[1]+1] = '$';
			position[1]++;
			break;




		}
		printBoard(board);
	}
	


}

void printBoard(char board[H][W]) {

	//printf("printBoard function is called.\n");
	system("cls");
	for (int i = 0; i < H; i++) {
		printf("|");
		for (int j = 0; j < W; j++) {

			printf("%c|", board[i][j]);

		}

		printf("\n");

	}
}
//| | | |
//| |$| |
//| | | | 
//If we press W
//| |$| |
//| | | |
//| | | | 
//If we press D
//| | |$|
//| | | |
//| | | | 
// 
//
