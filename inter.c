#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50
typedef struct {
    char op[3];
    char arg1[10];
    char arg2[10];
    char result[10];
} Quadruple;

Quadruple quads[MAX];
int quadCount = 0;
int tempCount = 0;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void genTemp(char *temp) {
    sprintf(temp, "t%d", tempCount++);
}

void genQuad(char *op, char *arg1, char *arg2, char *res) {
    strcpy(quads[quadCount].op, op);
    strcpy(quads[quadCount].arg1, arg1);
    strcpy(quads[quadCount].arg2, arg2);
    strcpy(quads[quadCount].result, res);
    quadCount++;
}

void printQuads() {
    printf("\nQuadruples:\n");
    for (int i = 0; i < quadCount; i++) {
        printf("%d: (%s, %s, %s, %s)\n", i+1, quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].result);
    }
}

int main() {
    char expr[50];
    char opStack[MAX][3]; 
    char valStack[MAX][10]; 
    int topOp = -1, topVal = -1;

    printf("Enter expression: ");
    scanf("%s", expr);

    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        char ch = expr[i];
        if (isalnum(ch)) {
            
            char temp[10] = {ch, '\0'};
            strcpy(valStack[++topVal], temp);
        } else if (strchr("+-*/", ch)) {
            
            while (topOp != -1 && precedence(opStack[topOp][0]) >= precedence(ch)) {
                char op[3];
                strcpy(op, opStack[topOp--]);
                char arg2[10], arg1[10], res[10];
                strcpy(arg2, valStack[topVal--]);
                strcpy(arg1, valStack[topVal--]);
                genTemp(res);
                genQuad(op, arg1, arg2, res);
                strcpy(valStack[++topVal], res);
            }
           
            char tempOp[3] = {ch, '\0'};
            strcpy(opStack[++topOp], tempOp);
        }
    }
    while (topOp != -1) {
        char op[3];
        strcpy(op, opStack[topOp--]);
        char arg2[10], arg1[10], res[10];
        strcpy(arg2, valStack[topVal--]);
        strcpy(arg1, valStack[topVal--]);
        genTemp(res);
        genQuad(op, arg1, arg2, res);
        strcpy(valStack[++topVal], res);
    }
    printf("Result in: %s\n", valStack[topVal]);
    printQuads();
    return 0;
}
