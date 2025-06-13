#include <stdio.h>

void constructed_board(char board[3][3]) {
    printf("--------Tic Tac Toe Game---------\n");
    printf("-------------       -------------\n");
    printf("| %c | %c | %c |       | 1 | 2 | 3 |\n", board[0][0], board[0][1], board[0][2]);
    printf("-------------       -------------\n");
    printf("| %c | %c | %c |       | 4 | 5 | 6 |\n", board[1][0], board[1][1], board[1][2]);
    printf("-------------       -------------\n");
    printf("| %c | %c | %c |       | 7 | 8 | 9 |\n", board[2][0], board[2][1], board[2][2]);
    printf("-------------       -------------\n");
}   

int win_situation(char board[3][3], char player) {
        if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
            (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||
            (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||
            (board[0][0] == player && board[1][0] == player && board[2][0] == player) ||
            (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||
            (board[0][2] == player && board[1][2] == player && board[2][2] == player))
            return 1;
            
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
            return 1;
    return 0;
}

int main() {
    char player = 'X';
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col, move;
	int remaining_left = 9;
    constructed_board(board);
    printf("------------Good luck------------\n");

    while (remaining_left > 0) {
    	if (player == 'X') {
        printf("     Player %c's move (1-9): ", player);
        scanf("%d", &move);

        row = (move - 1) / 3;
        col = (move - 1) % 3;

        	if (board[row][col] == 'X' || board[row][col] == 'O' || move >= 10 || move <= 0) {
            printf("Invalid choice. Please try again.\n");
            	continue;
        	}
		}
		
		else {
           	do {
                move = rand() % 9 + 1;
                row = (move - 1) / 3;
                col = (move - 1) % 3;
        	} while (board[row][col] == 'X' || board[row][col] == 'O');
        }
        
        board[row][col] = player;
        printf("\n");
        constructed_board(board);

        if (win_situation(board, player)) {
            printf("---------Player %c wins!----------\n", player);
            break;
        }

        	if (player == 'X'){
            player = 'O';
        	}
        	else {
            player = 'X';
        	}
    
        remaining_left--;
    }

    if (remaining_left == 0) {
        printf("----------It's a draw!-----------\n");
    }

    return 0;
}

