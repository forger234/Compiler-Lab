#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    FILE *fp1, *fp2;
    char op[3], arg1[10], arg2[10], result[10];

    fp1 = fopen("input.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    fp2 = fopen("output.txt", "w");
    if (fp2 == NULL) {
        printf("Error opening output file.\n");
        fclose(fp1);
        return 1;
    }
    while (fscanf(fp1, "%s %s %s %s", op, arg1, arg2, result) == 4) {
        fprintf(fp2, "MOV R0, %s\n", arg1);
        if (strcmp(op, "+") == 0) {
            fprintf(fp2, "ADD R0, %s\n", arg2);
        } else if (strcmp(op, "-") == 0) {
            fprintf(fp2, "SUB R0, %s\n", arg2);
        } else if (strcmp(op, "*") == 0) {
            fprintf(fp2, "MUL R0, %s\n", arg2);
        } else if (strcmp(op, "/") == 0) {
            fprintf(fp2, "DIV R0, %s\n", arg2);
        } else if (strcmp(op, "=") == 0) {
            fprintf(fp2, "");
        } else {
            fprintf(fp2, "; Unknown operation: %s\n", op);
        }
        fprintf(fp2, "MOV %s, R0\n", result);
    }
    fclose(fp1);
    fclose(fp2);
    printf("Assembly code written to output.txt\n");
    return 0;
}