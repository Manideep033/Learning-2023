/**  ***LEVEL-1***

1. Use structures to find the volume and the total surface area of the box. 
   You need to access the members of the structure with the help of a structure pointer:
    a. With the help of (*) asterisk or indirection operator and (.) dot operator.
    b. With the help of ( -> ) Arrow operator using pointer as well as dot representation. **/

#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

double calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
}

int main() {
    struct Box myBox = { 5.0, 3.0, 4.0 };
    struct Box* boxPtr = &myBox;

    // Accessing members using (*) asterisk and (.) dot operator
    double volume = (*boxPtr).length * (*boxPtr).width * (*boxPtr).height;
    double surfaceArea = 2 * ((*boxPtr).length * (*boxPtr).width + (*boxPtr).length * (*boxPtr).height + (*boxPtr).width * (*boxPtr).height);
    printf("Volume (using (*) and .): %.2f\n", volume);
    printf("Surface Area (using (*) and .): %.2f\n", surfaceArea);

    // Accessing members using (->) arrow operator (both pointer and dot representation)
    volume = boxPtr->length * boxPtr->width * boxPtr->height;
    surfaceArea = 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
    printf("Volume (using ->): %.2f\n", volume);
    printf("Surface Area (using ->): %.2f\n", surfaceArea);

    return 0;
}