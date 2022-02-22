#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void my_square(int x, int y) {

    int i, j;

    for(i = 0; i < y; i++) {
        for(j = 0; j < x; j++) {
            if((i == 0 && (j == 0 || j == x - 1)) || 
               (i == y -1 && (j == x - 1 || j == 0))) {
                printf("o");
            }
            else if ((i == 0) || (i == y - 1)) {
                printf("-");
            }
            else if ((j == 0) || (j == x - 1)) {
                printf("|");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
        
}


int main(int ac, char **av) {

    if(ac < 3) {
        return 0;
    }
    
    int x = atoi(av[1]);
    int y = atoi(av[2]);

    my_square(x, y);
    return 0;

}