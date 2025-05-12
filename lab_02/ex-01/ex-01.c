#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter number A: ");
    while (scanf("%d", &a) != 1 || a < 1) {
        printf("!Enter a valid POSITIVE INTEGER!\n");
        printf("Enter number A: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    printf("Enter number B: ");
    while (scanf("%d", &b) != 1 || b < 1) {
        printf("!Enter a valid POSITIVE INTEGER!\n");
        printf("Enter number B: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    if (b > a) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (a % b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    printf("GCF = %d", b);
    return 0;
}
