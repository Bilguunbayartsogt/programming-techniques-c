#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define FIN "../numbers.txt"

int charCheck(char c);
int discardCheck(int cur, int prev, int prevPrev);

int charCheck(char c) {
    if (isdigit(c)) return 1;
    if (c=='-') return 2;
    if (c==' ' || c=='\n') return -1;
    return 0;
}

int discardCheck(int cur, int prev, int prevPrev) {
    if (prevPrev+prev==cur) return 1;
    if (prevPrev-prev==cur) return 1;
    if (prevPrev*prev==cur) return 1;
    if (prevPrev!=0 && prevPrev/prev== cur) return 1;
    return 0;
}

int main(void) {
    FILE *fin;
    if ((fin=fopen(FIN, "r"))==NULL) {
        printf("Error opening the input file");
        return 1;
    }
    int prevPrev=0;
    int prev=0;
    int cur=0;
    char curChar;
    int isNegative=0;
    int discarded=0;
    int isFirstChar=1;
    int isSecondChar=0;
    int max=0;
    int min=0;

    while ((curChar=fgetc(fin))!=EOF) {
        switch (charCheck(curChar)) {
            case 1:
                cur= isNegative? -(cur*10+(curChar-'0')) : cur*10+(curChar-'0');
                break;
            case 2:
                isNegative=1;
                break;
            case -1:
                //printf("cur:%d prev:%d prevPrev:%d\n", cur, prev, prevPrev);
                if (isFirstChar) {
                    max=cur;
                    min=cur;
                    prevPrev=cur;
                    isFirstChar=0;
                    isSecondChar=1;
                } else if (isSecondChar) {
                    prev=cur;
                    isSecondChar=0;
                } else {
                    if (discardCheck(cur, prev, prevPrev)) {
                        prevPrev=prev;
                        prev=cur;
                    } else {
                        discarded++;
                    }
                }
                if (cur>max) max=cur;
                if (cur<min) min=cur;
                cur=0;
                isNegative=0;
                break;
        }
    }
    if (cur>max) max=cur;
    if (cur<min) min=cur;
    if (!discardCheck(cur, prev, prevPrev)) {
        discarded++;
    }
    printf("# of discarded values: %d\nMaximum value: %d\nMinimum value: %d\n", discarded, max, min);
    return 0;
}
