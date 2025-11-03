#include <stdio.h>
#include <ctype.h>
#include <string.h>
char input[100];
int i = 0;
int error_flag = 0;  
void E(), Eprime(),T(),Tprime(),F();
void match(char t)
{
    if (input[i] == t)
        i++;
    else {
        //printf("Syntax Error at position %d\n", i);
        error_flag = 1;
    }
}
void E()
{
    T();
    Eprime();
}
void Eprime()
{
    if (input[i] == '+') {
        match('+');
        T();
        Eprime();
    }
}
void T()
{
    F();
    Tprime();
}
void Tprime()
{
    if (input[i] == '*') {
        match('*');
        F();
        Tprime();
    }
}
void F()
{
    if (input[i] == '(') {
        match('(');
        E();
        match(')');
    }
    else if (isalnum(input[i])) {
        match(input[i]);
    }
    else {
        printf("Syntax Error at position %d\n", i);
        error_flag = 1;
    }
}
int main()
{
    printf("Enter an expression: ");
    scanf("%s", input);
    E();
    if (!error_flag && input[i] == '\0')
        printf("Parsing successful\n");
    else
        printf("PARSING NOT SUCCESSFULL\n");
    return 0;
}
