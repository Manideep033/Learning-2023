/** 2. Write a function to return the grade of the given student using switch case statements
90 to 100 -> 'A'
75 to 89 -> 'B'
60 to 74 -> 'C'
50 to 59 -> 'D'
36 to 49 -> 'E'
0 to 35 -> 'F'

In main check the return value and print the below
65 -> "Grade A"
66 -> "Grade B"
67 -> "Grade C"
68 -> "Grade D"
69 -> "Grade E"
70 -> "Grade F" **/

#include <stdio.h>

char getGrade(int score) {
    char grade;
    switch (score) {
        case 90 ... 100:
            grade = 'A';
            break;
        case 75 ... 89:
            grade = 'B';
            break;
        case 60 ... 74:
            grade = 'C';
            break;
        case 50 ... 59:
            grade = 'D';
            break;
        case 36 ... 49:
            grade = 'E';
            break;
        case 0 ... 35:
            grade = 'F';
            break;
        default:
            grade = 'X'; // Invalid score
    }
    return grade;
}

int main() {
    int score;
    scanf("%d",&score);
    char grade = getGrade(score);
    printf("Grade %c\n", grade);
    return 0;
}