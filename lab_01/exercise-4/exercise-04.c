#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PI 3.14

//exercise 4

double square(char method, int value);
double circle(char method, int value);

double square(char method, int value) {
    if (method == 'D') {
        return (value/2.0)*value;
    }
    if (method == 'S') {
        return value*value;
    }
    return -1;
}

double circle(char method, int value) {
    if (method == 'D') {
        return value/4.0 * PI * value;
    }
    if (method == 'R') {
        return PI * value * value;
    }
    return -1;
}

int main(void) {
    char shape;
    char method;
    char valueInput[10];
    int value;
    double result;
    printf("Enter shape: ");
    shape = getc(stdin);
    getchar();
    printf("Enter method: ");
    method = getc(stdin);
    getchar();
    printf("Enter value: ");
    fgets(valueInput, sizeof(valueInput), stdin);
    value = strtol(valueInput, NULL, 10);

    if (shape == 'I') {
        result = circle(method, value);
    } else if (shape == 'Q') {
        result = square(method, value);
    } else {
        printf("Wrong shape!");
        return 1;
    }

    if (result == -1) {
        printf("Wrong method!");
        return 1;
    }
    printf("The area of the %s with %s %d is %f", (shape == 'Q')?"Square":"Circle", (shape == 'Q')?(method == 'D'?"Diagonal":"Side"):(method == 'D'?"Diameter":"Radius"), value, result);
    return 0;
}

