# two-way-hexadecimal-to-binary-converter
Hexadecimal number to binary number and binary number to hexadecimal number converter.

Brady Lange

03/7/2018

Op Sys Programming

Assignment 2

## `src/hex_bin.c`
This program converts a hexidecimal number to a binary number and binary number to a 
hexidecimal number. When converting binary numbers to hexidecimal numbers 
the program handles when the input is not a factor of 4 numbers in length.
The program identifies if the input is hexidecimal number by checking 
if it has "0x" in the first two spots. Likewise it checks if its a binary number
by making sure each digit is a "0" or "1" and the first two spots don't start
with "0" or "x".

Input: `a.out 1000`

Output: `0x8`

## Issues:
- `hex_bin.c`: Logic error