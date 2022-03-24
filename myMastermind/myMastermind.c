#include "myMastermind.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    int code = 0;
    int inputAttempts = 0;
    int attempts = 10;
    int wpp;
    int mpp;

    //check input from user


    for(int i = 0; i < argc; i++) {
    if(my_strcmp("-c", argv[i])==0) {
        
        code = i + 1;
    }
    if(my_strcmp("-t", argv[i])==0) {
        inputAttempts = i + 1;
        attempts = my_atoi(argv[inputAttempts]);
        
    }
    }

    char num[4];                                    //store the input digits from user

    if(code == 0) {
        srand(time(NULL));

        int i = 0;
        char randDigit;

        while (i < 4) {
            randDigit = (rand() % 8) + 48;
            int equal = 0;

            for(int j = 0; j < i; j++) {
                if(num[j] == randDigit) {               //digits must be unique
                    equal = 1;
                    break;
                }
            }

            if(equal == 1)
                continue;
            else {
                num[i] = randDigit;
                i++;
            }
        }
    }

    else {                                              //copy the input
        for(int i = 0; i < 4; i++) {
            if(argv[code][i] != 34) {
                num[i] = argv[code][i];
            }
        }
    }

    //gameplay start

    printf("Will you find the secret code?\n");
    char inputNum[5];

    for(int i = 0; i < attempts; i++) {
        mpp = 0;
        wpp = 0;

        printf("-----Round %d-----\n", i);

    //check input (4 unique digits from 0 to 7)

    int correctInput;
    do{
        scanf("%s", inputNum);
        correctInput = 1;

        for(int i = 0; i < 4; i++) {
            if(strlen(inputNum) > 4){
            correctInput = 0;
            break;
            }
        }

        for(int j = 0; j < 4; j++) {
            if((inputNum[j] < 48) || (inputNum[j] > 55)) {
                correctInput = 0;
                break;
            }

            for(int k = 0; k < j; k++) {
                if(inputNum[j] == inputNum[k]) {
                    correctInput = 0;
                    break;
                }
            }
        }

        if(correctInput == 0) {
            printf("Wrong input. Please enter a number consisting of 4 unique digits from 0 to 7\n");
        }
    } while(correctInput != 1);


    //check if user guessed the number

    int correct = 1;
    for (int i = 0; i < 4; i++) {
        if(inputNum[i] != num[i]) {
            correct = 0;
            break;
        }
    }

    if(correct == 1) {
        printf("Congratz! You did it!\n");
        break;
    }

    for(int in = 0; in < 4; in++) {
        for(int n = 0; n < 4; n++) {
            if((in == n) && (num[n] == inputNum[in])) {
                wpp++;
            }
            else if (num[n] == inputNum[in]){
                mpp++;
            }
        }

    }

    printf("Well placed pieces: %d\nMisplaced pieces: %d\n", wpp, mpp);

    if(i == (attempts - 1)) {
        printf("Game Over. the secret number was: %c%c%c%c\n", num[0], num[1], num[2], num[3]);
    }
}
}