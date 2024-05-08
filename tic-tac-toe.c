#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE  3

int board[BOARD_SIZE][BOARD_SIZE];

char *get_move(char *prompt, int characters);
int get_no_of_players(char *prompt);
void print_board(void);
void print_header(void);
void single_player_game(void);

int main(void)
{
    int players;

    // initialise board
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = ' ';

    print_header();
    printf("Enter 1 or 2 for players.\n\n");
    print_board();

    // Get number of players
    players = get_no_of_players("1 or 2 Players (q to exit): ");

    // If 1 player then warn the user and exit
    if (players == 1) {
        print_header();
        printf("CPU player not implemented. Try a 2 player game.\n\n");
        print_board();
        printf("CPU player not implemented. Try a 2 player game.\nExiting Tic-Tac-Toe.\n");
        exit(0);
    }

    // Start game loop
    if (players == 2)
        single_player_game();

    return 0;
}

char *get_move(char *prompt, int no_of_chars) {
    int count = 0;
    int c;
    char *input = (char *)malloc((no_of_chars + 1) * sizeof(char));
    if(input == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", prompt);

    while ((c = getchar()) != EOF && c != '\n' && count < no_of_chars) {
        input[count] = c;
        count++;
    }
    input[count] == '\0';

    return input;
}

int get_no_of_players(char *prompt) {
    char* no_of_players;
    int players = -1;
    while (players <= 0)
    {
        no_of_players = get_move(prompt, 1);

        if (no_of_players[0] == '1')
            players = 1;
        else if (no_of_players[0] == '2')
            players = 2;
        else if (tolower(no_of_players[0]) == 'q')
        {
            free(no_of_players);
            printf("Exiting program.\n");
            exit(0);
        }
    }

    free(no_of_players);

    return players;
}
void print_board(void) {
    // PRINT BOARD
    printf("     a   b   c\n");
    printf("   +---+---+---+\n");
    printf(" 1 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("   +---+---+---+\n");
    printf(" 2 | %c | %c | %c |\n", board[1][0], board[0][1], board[0][2]);
    printf("   +---+---+---+\n");
    printf(" 3 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("   +---+---+---+\n\n");
}

void print_header(void) {
    system("clear");
    printf("TIC-TAC-TOE\n");
    printf("-----------\n");
}

void single_player_game(void) {
    unsigned short current_player;
    bool game_over = false;

    // RANDOMLY SELECT A STARTING PLAYER
    // Seed the random number generator using the current time
    srand(time(NULL));
    // Generate a random number between 0 and RAND_MAX
    int random_number = rand();
    // 50-50 chance for each player
    if (random_number % 2 == 0)
        current_player = 1;
    else
        current_player = 2;
}