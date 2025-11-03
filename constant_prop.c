#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100 
#define LEN 50 
typedef struct {
    char var;
    int value;
    int isConst; 
} Symbol;
Symbol table[26]; 
int isNumber(char *s) 
 {
     for (int i = 0; s[i]; i++) 
       {
           if (!isdigit(s[i]))
            return 0;
       }    
    return 1;
}
int evaluate(int x, int y, char op) 
 {
      switch (op) 
       {
          case '+': return x + y;
             case '-': return x - y;
                case '*': return x * y;
                  case '/': return y != 0 ? x / y : 0; 
       }
    return 0;
}
int main() 
 {
     char code[MAX][LEN];
     int n;
     printf("Enter number of statements: ");
     scanf("%d", &n);
      getchar(); 
      printf("Enter code (e.g., a = 4, b = a + 2):\n");
      for (int i = 0; i < n; i++) 
       {
           fgets(code[i], LEN, stdin);
           code[i][strcspn(code[i], "\n")] = '\0'; 
       }
    for (int i = 0; i < 26; i++) 
       {
           table[i].var = 'a' + i;
           table[i].isConst = 0;
       }
    printf("\nOptimized Code:\n");
    for (int i = 0; i < n; i++) 
      {
          char lhs, rhs1[10], rhs2[10], op;
          int matched = 0;
          if (sscanf(code[i], " %c = %s %c %s", &lhs, rhs1, &op, rhs2) == 4) 
           {
               int val1, val2;
               int const1 = 0, const2 = 0;
               if (isNumber(rhs1)) 
                {
                    val1 = atoi(rhs1);
                    const1 = 1;
                } 
             else if (table[rhs1[0] - 'a'].isConst) 
                {
                    val1 = table[rhs1[0] - 'a'].value;
                    const1 = 1;
                }  
             if (isNumber(rhs2)) 
              {
                  val2 = atoi(rhs2);
                  const2 = 1;
              } 
              else if (table[rhs2[0] - 'a'].isConst) 
               {
                val2 = table[rhs2[0] - 'a'].value;
                const2 = 1;
               }
             if (const1 && const2) 
               {
                   int result = evaluate(val1, val2, op);
                   printf("%c = %d\n", lhs, result);
                   table[lhs - 'a'].isConst = 1;
                   table[lhs - 'a'].value = result;
               } 
               else 
                {
                    printf("%s\n", code[i]);
                    table[lhs - 'a'].isConst = 0; 
                }
            matched = 1;
        }
        if (!matched && sscanf(code[i], " %c = %s", &lhs, rhs1) == 2) 
          {
              if (isNumber(rhs1)) 
               {
                   int value = atoi(rhs1);
                   printf("%c = %d\n", lhs, value);
                   table[lhs - 'a'].isConst = 1;
                      table[lhs - 'a'].value = value;
               } 
               else if (table[rhs1[0] - 'a'].isConst) 
               {
                  int value = table[rhs1[0] - 'a'].value;
                  printf("%c = %d\n", lhs, value);
                  table[lhs - 'a'].isConst = 1;
                  table[lhs - 'a'].value = value;
                } 
            else 
            {  
            printf("%s\n",code[i]);
             table[lhs - 'a'].isConst = 0;
            }
          }
    }
    return 0;
}
