#include <stdio.h>
#include <ctype.h>
#include <string.h>
char operand_stack[50][50];
int operand_top = -1;
int t = 1;
void push_operand(char *str) {
    strcpy(operand_stack[++operand_top], str);
}

char* pop_operand() {
    return operand_stack[operand_top--];
}
char op_stack[50];
int op_top = -1;

void push_operator(char c) {
    op_stack[++op_top] = c;
}

char pop_operator() {
    return op_stack[op_top--];
}

char peek_operator() {
    return op_stack[op_top];
}
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0; 
    }
}
void generate_code() {
    char op1[20], op2[20], res[20];
    char op;
    strcpy(op2, pop_operand());
    strcpy(op1, pop_operand());
    op = pop_operator();
    sprintf(res, "t%d", t++);
    printf("%-3c %-4s %-4s %-4s\n", op, op1, op2, res);
    push_operand(res);
}
int main() {
    char infix[50];
    char sym_str[2] = {'\0', '\0'}; 
    int i = 0;
    printf("\nEnter infix expression: ");
    scanf("%s", infix);
    printf("Three Address Code:\n");
    printf("-------------------\n");
    printf("Op  Arg1 Arg2 Result\n");
    printf("-------------------\n");

    while (infix[i] != '\0') {
        char sym = infix[i++];

        if (isalnum(sym)) {
            
            sym_str[0] = sym;
            push_operand(sym_str);
        } else if (sym == '(') {
            
            push_operator('(');
        } else if (sym == ')') {
            
            while (op_top != -1 && peek_operator() != '(') {
                generate_code();
            }
            pop_operator(); 
        } else {
            
            while (op_top != -1 && peek_operator() != '(' && 
                   precedence(peek_operator()) >= precedence(sym)) {
                generate_code();
            }
            
            push_operator(sym);
        }
    }
    while (op_top != -1) {
        generate_code();
    }


    return 0;
}