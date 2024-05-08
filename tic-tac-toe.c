#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE  3

int board[BOARD_SIZE][BOARD_SIZE];

char *get_move(char *prompt, int characters);
int get_no_of_players(char *prompt);
void print_board(void);
void print_grid(void);
void print_header(void);

int main(void)
{
    // initialise board
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = ' ';

    print_header();
    printf("Enter 1 or 2 for players.\n\n");
    print_board();
    printf("\n");

    char* no_of_players;
    int players = -1;

    players = get_no_of_players("1 or 2 Players (q to exit): ");
    free(no_of_players);

    // TODO: The game stuff
    

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
            printf("Exiting program.\n");
            exit(0);
        }
    }

    return players;
}
void print_board(void) {
    // PRINT GRID
    printf("     a   b   c\n");
    printf("   +---+---+---+\n");
    printf(" 1 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("   +---+---+---+\n");
    printf(" 2 | %c | %c | %c |\n", board[1][0], board[0][1], board[0][2]);
    printf("   +---+---+---+\n");
    printf(" 3 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("   +---+---+---+\n");
}

void print_header(void) {
    system("clear");
    printf("TIC-TAC-TOE\n");
    printf("-----------\n");
}
