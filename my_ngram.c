#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {

    char c = ' ';                                                
    int counter = 0;                                             

    while(c) {                                                   
        if(c == '"') c++;
        for(int i = 1; i < argc; i++) {                          
            for(int j = 0; (j < argv[i][j]) != '\0'; j++) {      
                if(c == argv[i][j]) counter++;                   
            
        	}
        }
        if(counter != 0) {                                       
            printf("%c:%d\n", c, counter);                       
            counter = 0;                                         
        }
    
        c++;                                                     

    }
    return 0;


}
