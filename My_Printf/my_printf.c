#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//find the length of an input string
int my_strlen(char* str) {
    
    int i = 0;

    while(*str != '\0') {
        i++;
        str++;
    }

    return i;
}

//print characters
int put_char(char c) {
    write(1, &c, 1);
    return 1;
}

//print string

int put_str(char *str) {
    
    int len = my_strlen(str);
    write(1, str, len);
    return len;
}

//print unsigned octal

int print_octal(int n) {
    
    unsigned int num = (unsigned int)n;

    char* a = (char*)malloc(100 * sizeof(char));
    int i     = 0;
    int count = 0;

    if(num == 0) {
        *a = 48;
        write(1, a, 1);
        count++;
    } else {
        while (num != 0) {
            *a = 48 + (num % 8);
            a++;
            i++;
            num = num / 8;
        }

        for(int k = 0; k < 1; k++) {
            a--;
            write(1, a, 1);
            count++;
        }
    }
    free(a);
    return count;
}

//print unsigned decimal

int print_unsigned_decimal(int n) {

    unsigned int num = (unsigned int)n;

    char* a = (char*)malloc(100 * sizeof(char));
    int i     = 0;
    int count = 0;

    if(num == 0) {
        *a = 48;
        write(1, a, 1);
        count++;

    } else {
        while(num != 0) {
            *a = 48 + (num % 10);
            a++;
            i++;
            num = num / 10;
        }
        for(int k = 0; k < 1; k++) {
            a--;
            write(1, a, 1);
            count++;
        }
    }
    free(a);
    return count;
}

//print decimal

int print_decimal(int num) {
    
    char* a = (char*)malloc(100 * sizeof(char));

    int i     = 0;
    int count = 0;

    if(num < 0) {
        char sign = '-';
        write(1, &sign, 1);
        num = num * (-1);
        count++;
    }
    if(num == 0) {
        *a = 48;
        write(1, a, 1);
        count++;

    } else {
        while (num != 0) {
            *a = 48 + (num % 10);
            a++;
            i++;
            num = num / 10;
        }
        for(int k = 0; k < 1; k++) {
            a--;
            write(1, a, 1);
            count++;
        }
    }

    free(a);
    return count;
}

//print hexadecimal

int print_hex(int n) {

    unsigned int num = (unsigned int)n;

    char* a = (char*)malloc(100 * sizeof(char));
    int i     = 0;
    int count = 0;

    const char HEX_DIGITS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    if(num == 0) {
        *a = 48;
        write(1, a, 1);
        count++;
    }else {
        while(num != 0) {
            *a = HEX_DIGITS[num % 16];
            a++;
            i++;
            num = num / 16;
        }
        for(int k = 0; k < i; k++) {
            a--;
            write(1, a, 1);
            count++;
        }
    }

    free(a);
    return count;
}

//print pointers

int print_pointer(void * point) {
    
    unsigned long num = (unsigned long)point;

    char* a = (char*)malloc(100 * sizeof(char));
    int i     = 0;
    int count = 0;

    const char HEX_DIGITS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    put_char('0');
    put_char('x');

    if(num == 0){
        *a = 48;
        write(1, a, 1);
        count++;

    } else {
        while(num != 0) {
            *a = HEX_DIGITS[num % 16];
            a++;
            i++;
            num = num / 16;
        }

        for(int k = 0; k < i; k++) {
            a--;
            write(1, a, 1);
            count++;
        }
    }
    free(a);
    return count + 2;
}


//my_printf

int my_printf(char * restrict format, ...) {

    int num_char_printed = 0;
    int curr_pos = 0;

    va_list args;
    
    va_start(args, format);

    while(format[curr_pos]) {
        if(format[curr_pos] == '%') {
            curr_pos++;
            switch (format[curr_pos]) {
                case 'd' :
                    num_char_printed += print_decimal(va_arg(args, int));
                    break;
                case 'o' :
                    num_char_printed += print_octal(va_arg(args, int));
                    break;
                case 'u' :
                    num_char_printed += print_unsigned_decimal(va_arg(args, int));
                    break;
                case 'x' :
                    num_char_printed += print_hex(va_arg(args, int));
                    break;
                case 'c' :
                    num_char_printed += put_char(va_arg(args, int));
                    break;
                case 's' :
                    num_char_printed += put_str(va_arg(args, char*));
                    break;
                case 'p' :
                    num_char_printed += print_pointer(va_arg(args, char*));
                    break;
                default :
                    put_str("Wrong input!");
            }
            curr_pos++;
            continue;
        }

        put_char(format[curr_pos]);
        num_char_printed++;
        curr_pos++;
    }

    va_end(args);
    return num_char_printed;
}


int main(void){

            
    my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
    /*my_printf("Total symbols printed: %d\n", a);
    a = printf("Hello, I am printf: %o %u %d %c %s %p\n", -15, 20, 456, 56, "12351 35123", &k);
    printf("Total symbols printed: %d\n", a);*/

      
    return 0;
}