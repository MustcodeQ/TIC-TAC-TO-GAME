#include <stdio.h>
#include <stdbool.h>

// Function to display the Tic-Tac-Toe board
void display_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if the game board is full
bool board_full(char board[3][3]) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ')
                return false; // There is an empty cell
        }
    }
    return true; // All cells are filled
}

// Function to check if a player has won
bool check_win(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true; // Winning row or column
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true; // Winning diagonal
    }
    return false; // No win
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    bool player1_turn = true;
    int row, col;

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1 (X) - Player 2 (O)\n");

    // Game loop
    while (true) {
        // Display current board
        display_board(board);

        // Determine current player and mark character
        char current_player_mark = (player1_turn) ? 'X' : 'O';
        int player_number = (player1_turn) ? 1 : 2;

        // Player input
        printf("Player %d, enter your move (row [1-3] column [1-3]): ", player_number);
        scanf("%d %d", &row, &col);

        // Adjust to zero-based indexing
        row--;
        col--;

        // Check if the chosen cell is valid and empty
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = current_player_mark;

            // Check for win
            if (check_win(board, current_player_mark)) {
                display_board(board);
                printf("Congratulations! Player %d ( %c ) wins!\n", player_number, current_player_mark);
                break;
            }

            // Check for draw
            if (board_full(board)) {
                display_board(board);
                printf("It's a draw!\n");
                break;
            }

            // Switch to the other player's turn
            player1_turn = !player1_turn;
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }

    return 0;
}

