#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(void) {
    FILE *fin;
    if ((fin=fopen("../expr.txt", "r"))==NULL) {
        printf("!Error opening the input file!\n");
        return 1;
    }
    char line[200];
    int lineNum=0;
    while (fgets(line, 200, fin)) {
        lineNum++;
        int bracket=0;
        char prev = '\0';
        char prevPrev='\0';
        int foundError=0;
        char errorat='\0';
        for (int i=0; i<strlen(line);i++) {
            //printf("%c", line[i]);
            if (line[i]=='(') {
                if (prev==' ') {
                    if (isdigit(prevPrev)) {
                        foundError=1;
                        errorat=line[i];
                        break;
                    }
                } else {
                    if (isdigit(prev)) {
                        foundError=1;
                        errorat=line[i];
                        break;
                    }
                }
                bracket++;
            } else if (line[i]==')') {
                if (bracket==0) {
                    foundError=1;
                    errorat=line[i];
                    break;
                }
                bracket--;
            } else if (line[i]=='+' || line[i]=='-' || line[i]=='*' || line[i]=='/') {
                if (prev==' ') {
                    if (!isdigit(prevPrev) && prevPrev!=')') {
                        foundError=1;
                        errorat=line[i];
                        break;
                    }
                } else {
                    if (!isdigit(prev) && prev!=')') {
                        foundError=1;
                        errorat=line[i];
                        break;
                    }
                }
            } else if (isdigit(line[i])) {
                if (prev==' ') {
                    if (isdigit(prevPrev) || prevPrev==')' || prevPrev=='(') {
                        foundError=1;
                        errorat=line[i];
                        break;
                    }
                }
            }
            prevPrev=prev;
            prev=line[i];
        }
        //printf("last char: %c\n", prevPrev);
        if (foundError) {
            printf("error in expression %d at %c\n", lineNum, errorat);
        } else if (prevPrev == '+' || prevPrev=='-'||prevPrev=='*'||prevPrev=='/') {
            printf("error in expression %d at the end\n", lineNum);
        } else if (bracket!=0) {
            printf("error in expression %d incorrect bracket count\n", lineNum);
        }

    }
    return 0;
}
