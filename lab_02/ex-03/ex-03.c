#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compressing(FILE *fin, FILE *fout);
int decompressing(FILE *fin, FILE *fout);

int compressing(FILE *fin, FILE *fout) {
    int total = 0;
    int rep = 0;
    char prev = '\0';
    char cur;
    while ((cur=getc(fin)) != EOF) {
        if (cur == prev) {
            rep=rep+1;
            if (rep==9) {
                fprintf(fout, "%c!%d", prev, rep);
                total=total+3;
                rep=0;
                prev='\0';
            }
        } else {
            if (rep >= 2) {
                fprintf(fout, "%c!%d", prev, rep);
                total=total+3;
            } else if (rep==1) {
                fprintf(fout, "%c%c", prev, prev);
                total=total+2;
            } else if (prev!='\0') {
                fprintf(fout, "%c", prev);
                total=total+1;
            }
            prev=cur;
            rep=0;
        }
    }
    if (rep >= 2) {
        fprintf(fout, "%c!%d", prev, rep);
        total=total+3;
    } else if (rep==1) {
        fprintf(fout, "%c%c", prev, prev);
        total=total+2;
    }
    return total;
}

int decompressing(FILE *fin, FILE *fout) {
    char line[200];
    while ((fgets(line, 200, fin)) != NULL) {
        int i=1;
        char prev=line[0];
        int encounteredEx=0;
        while (i<=strlen(line)) {
            if (line[i]=='!') {
                encounteredEx=1;
            } else if (encounteredEx) {
                int rep=line[i]-'0';
                for (int x=0; x<rep; x++) {
                    fputc(prev, fout);
                }
                encounteredEx=0;
            } else {
                fputc(prev, fout);
                prev=line[i];
            }
            i=i+1;
        };
    }
    return 1;
}
int main(void) {
    FILE *fin, *fout;
    printf("Press 'c' for compression, 'd' for decompression: ");
    char decision = getchar();
    while (getchar() != '\n');
    if (decision == 'c') {
        if ((fin = fopen("../source.txt", "r")) == NULL) {
            printf("!Error opening compression input file!\n");
            return 0;
        }
        if ((fout = fopen("../output01.txt", "w")) == NULL) {
            printf("!Error opening compression output file!\n");
            return 0;
        }
        int result = compressing(fin, fout);
        printf("Total number of chars written: %d", result);
    } else if (decision == 'd') {
        if ((fin = fopen("../output01.txt", "r")) == NULL) {
            printf("!Error opening compression input file! Compress a file first!\n");
            return 0;
        }
        if ((fout = fopen("../output02.txt", "w")) == NULL) {
            printf("!Error opening compression output file!\n");
            return 0;
        }
        decompressing(fin, fout);
    }
    return  1;
}
