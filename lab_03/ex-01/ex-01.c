#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define INPUT "../input.txt"
#define OUTPUT "../output.txt"

int main(void) {

    //open the input and output files
    FILE *fin, *fout;
    if ((fin=fopen(INPUT, "r"))==NULL) {
        printf("!Error opening the input file!\n");
        return 1;
    }
    if ((fout=fopen(OUTPUT, "w"))==NULL) {
        printf("!Error opening the output file!\n");
        return 2;
    }

    //read lines
    char line[25];
    int count=0;
    int originalChar = 0;
    char prev = '\0';
    while (fgets(line, 25, fin)!=NULL) {
        //printf("%s\n", line);
        for (int i=0;i<strlen(line);i++) {
            if (isdigit(line[i])) {
                fputc('*', fout);
                count++;
                prev=line[i];
                originalChar++;
            } else if (ispunct(line[i])) {
                fputc(line[i], fout);
                count++;
                prev=line[i];
                originalChar++;
            } else if (line[i]=='\n') {
                for (int j=0;j<(25-count);j++) {
                    fputc(' ', fout);
                }
                count=25;
            } else if (isalpha(line[i])) {
                if (ispunct(line[i-1])) {
                    fputc(' ', fout);
                    count++;
                }
                if (prev=='!' || prev=='.' || prev=='?') {
                    fputc(toupper(line[i]), fout);
                } else {
                    fputc(line[i], fout);
                }
                count++;
                originalChar++;
                prev=line[i];
            } else {
                fputc(line[i], fout);
                count++;
                originalChar++;
            }
            if (count==25) {
                fprintf(fout, "| c:%d\n", originalChar);
                count=0;
                originalChar=0;
            }
        }
    }
    //this is for the last line read that the loop exited with NULL because
    //we reached the end of the file EOF here.
    for (int j=0;j<(25-count);j++) {
        fputc(' ', fout);
    }
    fprintf(fout, "| c:%d\n", originalChar);

    return 0;
}
