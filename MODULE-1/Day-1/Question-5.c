/** 5. Write a function to accept an integer (32 bits) and operation type to do the following and return the result to main function.
    - Set 1st bit, if operation type is 1
    - Clear 31st bit, if operation type is 2
    - Toggle 16th bit, if operation type is 3
   You can consider the below function prototype,
    - bit_operations(int num, int oper_type);  **/

#include <stdio.h>

int bit_operations(int num, int oper_type) {
    int result = num;

    if (oper_type == 1) {
        result |= 1; // Set 1st bit
    } else if (oper_type == 2) {
        result &= ~(1 << 31); // Clear 31st bit
    } else if (oper_type == 3) {
        result ^= (1 << 16); // Toggle 16th bit
    } else {
        printf("Invalid operation type.\n");
        return num; // Return original number if operation type is invalid
    }

    return result;
}

int main() {
    int num, oper_type;
    printf("Enter an integer (32 bits): ");
    scanf("%d", &num);
    
    printf("Enter operation type (1, 2, or 3): ");
    scanf("%d", &oper_type);
    
    int result = bit_operations(num, oper_type);
    printf("Result: %d\n", result);
    
    return 0;
}