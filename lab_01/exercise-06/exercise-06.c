#include <stdio.h>

int calculator(char operator, float op1, float op2, float *result) {
    if (op2 == 0 && operator == '/') {
        printf("!invalid operation! don't divide by 0 pls :)\n");
        return 1;
    }
    switch (operator) {
        case '+':
            *result = op1 + op2;
        break;
        case '-':
            *result = op1 - op2;
        break;
        case '*':
            *result = op1 * op2;
        break;
        case '/':
            *result = op1 / op2;
        break;
        default:
            printf("!invalid operator!\n");
            return 2;
    }
    return 0;
}

int main(void) {
    char operator;
    float op1;
    float op2;
    FILE *fp_read, *fp_write;
    if ((fp_read = fopen("../Operations.txt", "r")) == NULL) {
        printf("!Error opening file!\n");
        return 1;
    }
    if ((fp_write = fopen("../Results.txt", "w")) == NULL) {
        printf("!Error creating file!\n");
        return 2;
    }
    while (fscanf(fp_read, " %c %f %f", &operator, &op1, &op2) == 3) {
        float result;
        if (calculator(operator, op1, op2, &result) == 0) {
            float truncatedResult = (int)(result*100)/100.0f;
            fprintf(fp_write, "%c %.2f \n", operator, truncatedResult);
        }
    }
    fclose(fp_read);
    fclose(fp_write);
    return 0;
}
