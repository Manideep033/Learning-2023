/** 2. Prints Bits:
    Scan a 32bit integer and prints its bits.

    Concepts to be used.
    - Loops
    - Bitwise Operators  **/

#include <stdio.h>

void printBits(int num);

int main() {
    int num;
    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);

    printBits(num);

    return 0;
}

void printBits(int num) {
    int i;
    unsigned int mask = 1 << 31; // Start with the leftmost bit (MSB)

    for (i = 0; i < 32; i++) {
        // Check if the current bit is set (1) or unset (0)
        int bit = (num & mask) != 0;
        printf("%d", bit);

        mask >>= 1;
    }

    printf("\n");
}