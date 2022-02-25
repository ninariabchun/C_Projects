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

| My_Square        |                             |
|:-----------------|---------------------------- |
| Submit Directory | ex00                        |
| Submit file      | my_cat.c                    |


Create a program called my_cat which does the same thing as the system's cat command used in the command-line.

Your program should read the content of each files which are received as an argument to your software.

Unlike the real Cat command, you don't have to handle any options. :-)

## My Ngram

| My_Square        |                             |
|:-----------------|---------------------------- |
| Submit Directory | ex00                        |
| Submit file      | my_cat.c                    |

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

