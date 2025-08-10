#include <ctype.h>
#include <stdio.h>
#include <string.h>

int stringToInt(char str[], int len);
void subSequences(int v[], int n, int len);


int stringToInt(char str[], int len) {
    int number = 0;
    int power;
    int i;
    int negative = 0;
    if (str[0]=='-') {
        negative=1;
        i = 1;
        power = len-2;
    } else {
        i = 0;
        power = len-1;
    }
    for ( ; i<len ; i++) {
        int pos=1;
        for (int j=0; j<power; j++) {
            pos=pos*10;
        }
        number = number + (str[i] - '0') * pos;
        power-=1;
    }
    return (negative==1) ? number*(-1) : number;
}

void subSequences(int v[], int n, int len) {
    int i;
    int found = 0;
    printf("Valid sub-arrays:\n");
    for (i=0; i<len; i++) {
        int cur = v[i];
        int subLen = 0;
        if (cur!=0) {
            subLen+=1;
            if (n==1) {
                printf("[cur]\n");
            } else {
                int invalid = 0;
                for (int j=i+1; j<len-1; j++) {
                    if (subLen>=n || invalid == 1) {
                        break;
                    }
                    if (v[j]==0) {
                        invalid=1;
                    } else {
                        subLen+=1;
                    }
                }
                if (invalid == 0 && subLen >= n) {
                    if (found==0) found=1;
                    printf("[");
                    for (int k=i; k<i+subLen; k++) {
                        printf("%d", v[k]);
                        if (k!=i+subLen-1) printf(", ");
                    }
                    printf("]\n");
                }
            }
        }
    }
    if (found == 0) {
        printf("None Found\n");
    }
}

int main(void) {
    int v[31];
    int i;
    int n;
    int exit = 0;
    for (i=0; i<31; i++) {
        if (exit == 1) {
            break;
        }
        char check[10];
        int validated = 0;
        while (validated == 0 && exit == 0) {
            int invalid = 0;
            int negative = 0;
            printf("Enter a positive integer up to 99999 or exit with 'x': ");
            scanf("%8s", check);
            while (getchar() != '\n');
            int len = strlen(check);
            if (len > 5) {
                invalid=1;
            } else if (len==1 && check[0]=='x') {
                exit = 1;
            } else if (len>1 && check[0]=='-') {
                negative=1;
            } else {
                for (int j=0; j<len; j++) {
                    if (isdigit(check[j])==0) {
                        invalid=1;
                        break;
                    }
                }
            }
            if (invalid == 1) {
                printf("Enter a valid integer you f#cking donkey!\n");
            } else if (exit == 1) {
                printf("Exiting\n");
            } else {
                validated=1;
                v[i] = stringToInt(check, len);
                printf("Accepted! %dth element: %d\n", i+1, v[i]);
            }
        }
    }
    printf("array constructed: [");
    for (int k=0; k<i-1; k++) {
        printf("%d", v[k]);
        if (k!=i-2) printf(", ");
    }
    printf("]\n");

    printf("Enter the maximum size (1-30) of sub-arrays: ");
    while (scanf("%d", &n)!=1) {
        while (getchar()!='\n');
        printf("Enter a valid integer between 1 and 30 you bloody bastard!!!\n");
        printf("Enter the maximum size (1-30) of sub-arrays: ");
    }
    subSequences(v, n, i);
    printf("Finished!\n");
}

