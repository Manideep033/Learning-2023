/**  ***LEVEL-2***
 
1. Sort the above "data.csv" based on the "Temperature" field in descending order.

a. Use only file handling concepts **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapLines(FILE *file, long pos1, long pos2, int lineSize) {
    char *line1 = malloc(lineSize);
    char *line2 = malloc(lineSize);
    
    fseek(file, pos1, SEEK_SET);
    fread(line1, 1, lineSize, file);
    
    fseek(file, pos2, SEEK_SET);
    fread(line2, 1, lineSize, file);
    
    fseek(file, pos1, SEEK_SET);
    fwrite(line2, 1, lineSize, file);
    
    fseek(file, pos2, SEEK_SET);
    fwrite(line1, 1, lineSize, file);
    
    free(line1);
    free(line2);
}

int main() {
    FILE *file = fopen("data.csv", "r+");
    if (file == NULL) {
        printf("Failed to open data.csv file.\n");
        return 1;
    }
    
    // Determine the size of each line
    fseek(file, 0, SEEK_END);
    int lineSize = ftell(file) / 3;
    
    // Bubble sort based on "Temperature" field in descending order
    for (int i = 0; i < 2; i++) {
        fseek(file, 0, SEEK_SET);
        
        for (int j = 0; j < 2 - i; j++) {
            long pos1 = j * lineSize;
            long pos2 = (j + 1) * lineSize;
            
            fseek(file, pos1 + 18, SEEK_SET); // Move to "Temperature" field
            float temp1, temp2;
            fscanf(file, "%f", &temp1);
            
            fseek(file, pos2 + 18, SEEK_SET);
            fscanf(file, "%f", &temp2);
            
            if (temp1 < temp2) {
                swapLines(file, pos1, pos2, lineSize);
            }
        }
    }
    
    fclose(file);
    
    printf("Data.csv sorted based on Temperature in descending order.\n");
    
    return 0;
}
