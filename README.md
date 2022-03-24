# Small Project in C

## My Square

| My_Square        |                             |
|:-----------------|---------------------------- |
| Submit Directory | ex00                        |
| Submit file      | my_square.c                 |

Create a program which displays a beautiful square.

my_square(5,3) should display:

```$>./a.out 5 3
o---o
|   |
o---o
$>
```
my_square(5, 1) should display:

```$>./a.out 5 1
o---o
$>
```
my_square(1, 1) should display:

```$>./a.out 1 1
o
$>
```

## My Cat

| My_Cat           |                             |
|:-----------------|---------------------------- |
| Submit Directory | ex00                        |
| Submit file      | my_cat.c                    |


Create a program called my_cat which does the same thing as the system's cat command used in the command-line.

Your program should read the content of each files which are received as an argument to your software.

Unlike the real Cat command, you don't have to handle any options. :-)

## My Ngram

| My_Ngram         |                             |
|:-----------------|---------------------------- |
| Submit Directory | ex00                        |
| Submit file      | my_ngram.c                  |

SPECIFICATIONS
Write a program my_ngram; It will count the number of occurrences per character.

NAME
my_ngram

SYNOPSIS
my_ngram text [text2, text3]

DESCRIPTION
In computational linguistics and probability, an n-gram is a contiguous sequence of n items from a given sample of text or speech. The items can be phonemes, syllables, letters, words or base pairs according to the application. The n-grams typically are collected from a text or speech corpus. When the items are words, n-grams may also be called shingles.

Google Inc. has used this technique to improve the completion of its Search Engine. The program was developed by Jon Orwant and Will Brockman and released in mid-December 2010.

My Ngram will take 1 or multiple strings as arguments.

It will display, one per line, each character and the numbers of times it appears.

Order will be alphanumerical.

Example 00

```$>./my_ngram "abcdef"
a:1
b:1
c:1
d:1
e:1
f:1
$>
```
Example 01

```$>./my_ngram "        "
 :8
$>
8 spaces :-)
```

Example 02

```$>./my_ngram "aaabb" "abc"
a:4
b:3
c:1
$>
```

## My Mastermind

| My_Mastermind    |                             |
|:-----------------|---------------------------- |
| Submit file      | .h, .c, makefile            |

SPECIFICATIONS

Write a program called mastermind; it will be an implementation of the famous game.

NAME
my_mastermind

SYNOPSIS
my_mastermind [-ct]

DESCRIPTION
Mastermind is a game composed of 8 pieces of different colors. A secret code is then composed of 4 distinct pieces.
The player has 10 attempts to find the secret code. After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.
Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.
If the player finds the code, he wins, and the game stops. A misplaced piece is a piece that is present in the secret code butthat is not in a good position.
You must read the player's input from the standard input.

Your program will also receive the following parameters:

-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.

-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.

-p [PIECES]: specifies and changes pieces; by default '0' '1' '2' '3' '4' '5' '6' '7'

Example 00

```PROMPT>./my_mastermind -c "0123"
Will you find the secret code?
---
Round 0
>1456
Well placed pieces: 0
Misplaced pieces: 1
---
Round 1
>tata
Wrong input!
>4132
Well placed pieces: 1
Misplaced pieces: 2
---
Round 2
>0123
Congratz! You did it!
```

## My Printf

| My_Printf        |                             |
|:-----------------|---------------------------- |
| Submit file      | .c                          |

NAME
int my_printf(char * restrict format, ...);

Prolog

The very first thing we do when learning a programming language is to write "Hello World !" on the screen. Well guess what ? This custom comes from a notebook called ... Programming in C: A Tutorial !
Unfortunately for you, this project will bring you back in the 1970s, before the existence of this book, and you will have to write your own function to greet the world.

Fortunately for you, you will strengthen your programming skills and learn new programming concepts: variadic functions and variable argument lists. Recoding printf is also a good exercise to learn to have a well structured code organisation. Modularity is the key here since printf has a lot of different options that you will have to recode yourself. Adding a new option feature should be easy and smooth if the code is well designed !

DESCRIPTION

The my_printf() function produce output according to a format as described below. The my_printf() functions write output to stdout, the standard output stream;

This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.

The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the % character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the %, the following appear in sequence:

doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).

c The int argument is converted to an unsigned char, and the resulting character is written.

s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.

p The void * pointer argument is printed in hexadecimal.

Requirements

The code must be compiled with the flags -Wall -Wextra -Werror.

Hint(s)

• man printf
• man 3 stdarg
• Watch out for memory leaks !
• You can test your code against memory errors by compiling with the debugging flags -g3 -fsanitize=address
• Global variables are strictly FORBIDDEN
• Static variables are strictly FORBIDDEN

Authorized function(s)

• write(2)
• malloc
• free
• va_start, va_arg, va_copy, va_end (see man 3 stdarg)

(Obvious) Unauthorized functions

printf and co. (fprintf, sprintf, snprintf, asprintf, dprintf, vprintf, vfprintf, vsprintf, vsnprintf, vasprintf, vdprintf)
