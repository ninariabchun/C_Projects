#include "myMastermind.h"
#include <stdio.h>
#include <stdlib.h>


int my_strcmp(char* param_1, char* param_2) {
    
    int i;     

    for(i = 0; param_1[i] == param_2[i]; i++) {

        if(param_1[i] == '\0') 
                return 0;
    }
        return param_1[i] - param_2[i];
}

int my_atoi(char str[]){
    int i = 0;
    int num = 0;

    while (str[i] != '\0') {
        i++;
    }

    i--;
    int tenPow = 1;

    for (int j = i; j >= 0; j--){
        if (str[j] != 34) {
            num = num + tenPow * (str[j] - 48);
            tenPow *= 10;
        }
    }

    return num;
}


char* my_rand() {

    static char digits[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    char* randNum;

    for(int i = 0; i < 4; i++) {
        int index = rand() % (sizeof digits / sizeof digits[1]);
        randNum[i] = digits[index];
        randNum++;
    }

    randNum[4] = '\0';
    randNum = randNum - 4;

    return randNum;
}
