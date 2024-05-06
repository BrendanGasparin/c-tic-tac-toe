#include <stdio.h>
#include <stdlib.h>

void print_grid(void);

int main(void)
{
    system("clear");
    printf("Commencing C game...\n");

    print_grid();

    return 0;
}

void print_grid(void) {
    // PRINT BLANK GRID
    printf("+---+---+---+\n");
    printf("|   |   |   |\n");
    printf("+---+---+---+\n");
    printf("|   |   |   |\n");
    printf("+---+---+---+\n");
    printf("|   |   |   |\n");
    printf("+---+---+---+\n");
}
