#include <stdio.h>

void createBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;

    return 0;
}

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int row, col, move;
    char player = 'X';
    int movesLeft = 9;

    createBoard(board);

    while (movesLeft > 0) {
        printf("Player %c's move (1-9): ", player);
        scanf("%d", &move);

        row = (move - 1) / 3;
        col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid. Try again.\n");
            continue;
        }

        board[row][col] = player;
        createBoard(board);

        if (checkWin(board, player)) {
            printf("Player %c wins!\n", player);
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
        movesLeft--;
    }

    if (movesLeft == 0) {
        printf("It's a draw!\n");
    }

    return 0;
}

