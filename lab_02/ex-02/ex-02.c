#include <stdio.h>

int main(void) {
    // n is the target index
    int n;
    long long prev = 0;
    long long cur = 1;
    // i is the current index
    int i = 1;
    printf("Enter N: ");
    while (scanf("%d", &n) != 1 || n < 0) {
        printf("!Enter a valid positive integer!\n");
        printf("Enter N: ");
        while (getchar() != '\n');
    }

    if (n == 0) {
        printf("result=0");
        return 0;
    }
    if (n == 1) {
        printf("result=1");
        return 0;
    }

    while (i < n) {
        int temp = cur;
        cur = temp + prev;
        prev = temp;
        i = i+1;
    }
    // %lld is for long long type
    printf("result=%lld", cur);

    // if i try to find N=100 with int variables,
    // the result exceeds 32 bits/4 bytes size of int and
    // returns a negative slop number. It's the same with
    // unsigned int because they are both 32bits/4bytes.
    // long long datatype is going up to N=46, i am
    // not sure how i can store the 100th number since it's
    // too big.

    // in depth
    // if we modify the program like this:
    // Xi = Xi-1 * Xi-2, with X0 = 1 and X1 = 2
    // it will grow exponentially faster than the
    // regular method
    // TL;DR: i was too lazy to implement it

    return 0;
}


