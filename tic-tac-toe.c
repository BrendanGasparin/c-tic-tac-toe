#include <stdio.h>
#include <stdlib.h>

void print_grid(void);
char *get_move(char *prompt, int characters);

int main(void)
{
    system("clear");
    printf("TIC-TAC-TOE\n");
    printf("Enter 1 or 2 for players.\n");
    printf("-----------\n\n");
    print_grid();
    printf("\n");

    char *no_of_players = get_move("1 or 2 Players: ", 1);

    free(no_of_players);

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

char *get_move(char *prompt, int no_of_chars) {
    int count = 0;
    int c;
    char *input = (char *)malloc((no_of_chars + 1) * sizeof(char));
    if(input == NULL) {
        printf("Memory allocaiton failed.\n");
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
