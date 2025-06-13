#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;

void draw_board() {
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("-------------\n");
}

int has_won() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;
    return 0;
}

void place_marker(int slot) {
    int row = slot / 3;
    int col;
    if (slot % 3 == 0) {
        row = row - 1;
        col = 2;
    }
    else
        col = (slot % 3) - 1;
    board[row][col] = current_marker;
}

void change_player_and_marker() {
    if (current_player == 1)
        current_player = 2;
    else {
        current_player = 1;
        current_marker = 'X';
    }
    if (current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';
}

void game() {
    printf("Player 1, choose your marker: ");
    char marker_p1;
    scanf("%c", &marker_p1);
    current_player = 1;
    current_marker = marker_p1;
    draw_board();
    int player_won;
    for (int i = 0; i < 9; i++) {
        printf("Player %d, enter your slot: ", current_player);
        int slot;
        scanf("%d", &slot);
        place_marker(slot);
        draw_board();
        player_won = has_won();
        if (player_won)
            break;
        change_player_and_marker();
    }
    if (player_won == 1)
        printf("Player 1 wins!\n");
    else if (player_won == 2)
        printf("Player 2 wins!\n");
    else
        printf("It's a tie!\n");
}

int main() {
    game();
    return 0;
}
