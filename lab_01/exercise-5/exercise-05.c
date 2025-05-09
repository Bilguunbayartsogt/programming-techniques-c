#include <stdbool.h>
#include <stdio.h>

//exercise 5

int main(void) {
    float op1;
    float op2;
    float result;
    printf("Enter operator: ");
    char operator = getchar();
    while (getchar() != '\n');

    //this will still break if you enter a string
    //like this, number followed by a string: 123abc
    printf("Enter operand 1: ");
    while (scanf("%f", &op1) != 1) {
        printf("!Enter a valid number!\n");
        printf("Enter operand 1: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    printf("Enter operand 2: ");
    while (scanf("%f", &op2) != 1) {
        printf("!Enter a valid number!\n");
        printf("Enter operand 2: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    if (op2 == 0 && operator == '/') {
        printf("invalid operation! don't divide by 0 pls :)");
        return 0;
    }
    switch (operator) {
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        case '/':
            result = op1 / op2;
            break;
        default:
            printf("invalid operator!");
            return 1;
    }
    printf("%c %f", operator, result);
    return 0;
}

