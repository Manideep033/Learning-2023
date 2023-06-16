//  ****LEVEL-1****

/** 1.Patern Generator:
    Write a program to print the given pattern below using 3 functions (1st to accept n and to print from 1 to n, 2nd to accept n and print spaces in between, 3rd to accept the n and print from n to 1)
    1234554321
    1234    4321
    123        321
    12            21
    1                1

    Concepts to be used.
    - Loops **/

#include <stdio.h>

void printPattern(int n);

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    printPattern(n);
    
    return 0;
}

void printPattern(int n) {
    int i, j;

    for (i = n; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        for (j = 1; j <= 2 * (n - i); j++) {
            printf(" ");
        }

        for (j = i; j >= 1; j--) {
            printf("%d", j);
        }
        
        printf("\n");
    }
}