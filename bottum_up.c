#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char in[50], st[50]; 
int ip=0, sp=0, n;

void reduce() {
    int f=1;
    while (f) {
        f=0;
        char t;
        if (st[sp-1]=='a'||st[sp-1]=='b'||st[sp-1]=='c') {
            t=st[sp-1];
            st[sp-1]='E';
            printf("\n$%s\t\t%s$\t\tE->%c",st,in+ip,t);
             f=1;
        }
        if (sp>=3 && st[sp-3]=='E' && strchr("+-*/",st[sp-2]) && st[sp-1]=='E') {
            char op=st[sp-2];
            st[sp-3]='E'; 
            st[sp-2]=st[sp-1]='\0'; 
            sp-=2;
            printf("\n$%s\t\t%s$\t\tE->E%cE",st,in+ip,op); 
            f=1;
        }
    }
}

int main() {
    printf("\nBOTTOM UP PARSER\n\nGrammar:\nE->E+E\nE->E*E\nE->E/E\nE->a|b|c\n");
    printf("\nEnter input: ");
    scanf("%s",in);
    n=strlen(in); 
    in[n]='\0';

    printf("\nStack\t\tInput\t\tAction\n$\t\t%s$\t\t--",in);

    while (1) {
        if (!(isalpha(in[ip])||strchr("*/+$",in[ip]))) {
            printf("\n$%s\t\t%s$\t\tREJECT",st,in+ip); 
            return 0;
        }

        st[sp++]=in[ip]; 
        st[sp]='\0';
        printf("\n$%s\t\t%s$\t\tshift %c",st,in+ ++ip,st[sp-1]);

        reduce();

        if (!strcmp(st,"E")&&in[ip]=='\0') {
            printf("\n$%s\t\t%s$\t\tACCEPT",st,in+ip);
             break;
        }
        if (ip>=n && strcmp(st,"E")) {
            printf("\n$%s\t\t%s$\t\tREJECT",st,in+ip); 
            break;
        }
    }
}
