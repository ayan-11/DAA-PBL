#include <stdio.h>

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void print_board() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void get_move(int *row, int *col) {
    printf("Enter row and column: ");
    scanf("%d %d", row, col);
}

int check_win() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return -1; 
}

int main() {
    int row, col, player = 1, winner = 0;
    while (!winner) {
        printf("Player %d's turn:\n", player);
        print_board();
        get_move(&row, &col);
        if (board[row-1][col-1] == ' ') {
            board[row-1][col-1] = (player == 1) ? 'X' : 'O';
            winner = check_win();
            player = (player == 1) ? 2 : 1;
        } else {
            printf("That spot is already taken!\n");
        }
    }
    print_board();
    if (winner == -1) {
        printf("Tie game!\n");
    } else {
        printf("Player %d wins!\n", winner);
    }
    return 0;
}