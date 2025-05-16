#include <ctype.h>
#include <stdio.h>
#include <string.h>
int encoding(FILE *fin, FILE *fout);
int decoding(FILE *fin, FILE *fout);

// todo decoding
int encoding(FILE *fin, FILE *fout) {
    char line[200];
    int k=0;
    char prev='\0';
    while (fgets(line, 200, fin)) {
        //printf("%s", line);
        for (int i=0; i<strlen(line); i++) {
            if (isdigit(line[i])) {
                int sum=(line[i]-'0')+k;
                fputc(((sum%10)+'0'), fout);
                k=(k==9)?0:k+1;
            } else if (isalpha(line[i])) {
                if (isalpha(prev)) {
                    // i wrote some gibberish shit here but it works
                    int h=islower(prev)?prev-'a':prev-'A';
                    int pos=line[i]+h;
                    if ((islower(line[i]) && pos>'z') || (!islower(line[i]) && (pos>'Z'))) {
                        pos=pos-26;
                        fputc(pos, fout);
                    } else {
                        fputc(pos, fout);
                    }
                } else {
                    fputc(line[i], fout);
                }
            } else {
                fputc(line[i], fout);
            }
            prev=line[i];
        }
    }
    return 0;
}
int decoding(FILE *fin, FILE *fout) {
    // todo: decoding
    return 0;
}

int main(void) {
    printf("Enter 'e' for encoding, 'd' for decoding: ");
    char letter = getchar();
    while (getchar()!='\n');

    FILE *fin, *fout;
    // open files
    if (letter=='e') {
        if ((fin=fopen("../input.txt", "r"))==NULL) {
            printf("!Error opening the input file!\n");
            return 1;
        }
        if ((fout=fopen("../output01.txt", "w"))==NULL) {
            printf("!Error opening the output file!\n");
            return 2;
        }
        encoding(fin, fout);
    } else if (letter=='d') {
        if ((fin=fopen("../output01.txt", "r"))==NULL) {
            printf("!Error opening the input file!\n");
            return 1;
        }
        if ((fout=fopen("../output02.txt", "w"))==NULL) {
            printf("!Error opening the output file!\n");
            return 2;
        }
        decoding(fin, fout);
    } else {
        printf("!Told you to enter either 'e' or 'd' dumb ass!\n");
        return 3;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
