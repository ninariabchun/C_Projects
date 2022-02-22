#include <stdio.h>                                                          
#include <stdlib.h>


int my_square(int argc, char* argv[]) {
    
    FILE *fptr;
    int i;
    char s;


    for(i = 1; i < argc; i++) {
        if((fptr = fopen(argv[i], "r")) == NULL) {
            printf("Error");
            exit(1);
        }

        while((s = getc(fptr)) != EOF)
            printf("%c", s);
            fclose(fptr);
    
    }

}