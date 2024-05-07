#include <stdio.h>
#include <stdlib.h>

void print_grid(void);

int main(void)
{
    system("clear");
    printf("TIC-TAC-TOE\n");
    printf("-----------\n\n");
    print_grid();
    printf("\n");

    char *no_of_players = get_input("1 or 2 Players: ", 1);

    return 0;
}

void print_grid(void) {
    // PRINT BLANK GRID
    printf("     a   b   c\n");
    printf("   +---+---+---+\n");
    printf(" 1 |   |   |   |\n");
    printf("   +---+---+---+\n");
    printf(" 2 |   |   |   |\n");
    printf("   +---+---+---+\n");
    printf(" 3 |   |   |   |\n");
    printf("   +---+---+---+\n");
}

char * get_input(char *prompt, int no_of_chars) {
    int count = 0;
    char *input = malloc(no_of_chars * sizeof(char));

    while ()) {
        input[count] == c.getChar();
        count++;
    }
}
