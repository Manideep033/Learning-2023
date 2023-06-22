/** 2. Case Handler:
    Write a C program to copy a file by considering the user option to handle the text case
-u, to change file content to Upper Case
-l, to change file content to Lower Case
-s, to change file content to Sentence Case
if no options are passed then it should be a normal copy

Example, say we have a file f1 with the following content
f1:
-----------------------
This is the file data
testing Case copy
application
-----------------------

./cp -s f1 f2
f2:
-----------------------
This Is The Tile Data
Testing Case Copy
Application
-----------------------

./cp -l f1 f3
f3:
-----------------------
this is the tile data
testing case copy
application
-----------------------

./cp -u f1 f4
f4:
-----------------------
THIS IS THE FILE DATA
TESTING CASE COPY
APPLICATION
-----------------------

./cp f1 f5
Should perform a normal copy **/

#include <stdio.h>
#include <ctype.h>

void changeToUpperCase(FILE *input, FILE *output) {
    int c;
    while ((c = fgetc(input)) != EOF) {
        fputc(toupper(c), output);
    }
}

void changeToLowerCase(FILE *input, FILE *output) {
    int c;
    while ((c = fgetc(input)) != EOF) {
        fputc(tolower(c), output);
    }
}

void changeToSentenceCase(FILE *input, FILE *output) {
    int c;
    int isFirstCharacter = 1;
    while ((c = fgetc(input)) != EOF) {
        if (isFirstCharacter) {
            fputc(toupper(c), output);
            isFirstCharacter = 0;
        } else {
            fputc(tolower(c), output);
        }
        if (c == '.' || c == '?' || c == '!') {
            isFirstCharacter = 1;
        }
    }
}

int main() {
    FILE *input, *output;
    char inputFile[100], outputFile[100], option;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFile);

    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    printf("Enter the option for text case: ");
    scanf(" %c", &option);

    input = fopen(inputFile, "r");
    output = fopen(outputFile, "w");

    if (input == NULL || output == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    switch (option) {
        case 'u':
            changeToUpperCase(input, output);
            printf("File copied and text converted to Upper Case.\n");
            break;
        case 'l':
            changeToLowerCase(input, output);
            printf("File copied and text converted to Lower Case.\n");
            break;
        case 's':
            changeToSentenceCase(input, output);
            printf("File copied and text converted to Sentence Case.\n");
            break;
        default:
            printf("Invalid option.\n");
            return 1;
    }

    fclose(input);
    fclose(output);

    return 0;
}