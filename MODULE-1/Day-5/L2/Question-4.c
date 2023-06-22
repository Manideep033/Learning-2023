/** 4. Write a program to pass a pointer to a structure as a parameter to a function and return back a pointer to structure 
   to the calling function after modifying the members of structure. **/

#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

struct Person* modifyPerson(struct Person *person) {
    // Modifying the members of the structure
    strcpy(person->name, "John Doe");
    person->age = 30;

    return person;
}

int main() {
    struct Person person;

    printf("Enter name: ");
    scanf("%s", person.name);
    printf("Enter age: ");
    scanf("%d", &person.age);

    struct Person *modifiedPerson = modifyPerson(&person);

    printf("\nModified Person Details:\n");
    printf("Name: %s\n", modifiedPerson->name);
    printf("Age: %d\n", modifiedPerson->age);

    return 0;
}