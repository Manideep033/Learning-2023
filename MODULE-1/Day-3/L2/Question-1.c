/** 1. Bit Operations:
    https://1.bp.blogspot.com/-Tfj_D_f_AF0/VZO5QIIGAUI/AAAAAAAAAmI/5Rw6uIU3EiI/s1600/DS1307%2BTime%2BKeeper%2BRegister.PNG

DS1307 has its time registers in BCD format as shown in the image found in the above link, so 
a. Write a function to Set, clear and toggle bit of an 8-bit number

Concepts to be used.
- Operators **/

#include <stdio.h>

// Function to set a specific bit of an 8-bit number
unsigned char setBit(unsigned char num, int bitPosition) {
    return num | (1 << bitPosition);
}

// Function to clear a specific bit of an 8-bit number
unsigned char clearBit(unsigned char num, int bitPosition) {
    return num & ~(1 << bitPosition);
}

// Function to toggle a specific bit of an 8-bit number
unsigned char toggleBit(unsigned char num, int bitPosition) {
    return num ^ (1 << bitPosition);
}

int main() {
    unsigned char num = 0b01010101; // Example 8-bit number

    printf("Original number: 0x%02X\n", num);

    // Set bit 3
    num = setBit(num, 3);
    printf("After setting bit 3: 0x%02X\n", num);

    // Clear bit 6
    num = clearBit(num, 6);
    printf("After clearing bit 6: 0x%02X\n", num);

    // Toggle bit 1
    num = toggleBit(num, 1);
    printf("After toggling bit 1: 0x%02X\n", num);

   return 0;
}