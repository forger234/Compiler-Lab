#include <stdio.h>
#include <string.h>
#include <ctype.h>
char in[100]; 
int i=0, err=0;
void E(), Ep(), T(), Tp(), F();
int main() {
    printf("Enter expression: ");
    fgets(in, sizeof(in), stdin);
    in[strcspn(in,"\n")] = '\0';
    E();
    if (!err && in[i]=='\0')
        printf("Accepted\n");
    else printf("Rejected\n");
}
void E(){ 
    T();
    Ep();
 }
void Ep(){
     if(in[i]=='+')
     { 
        i++;
         T();
          Ep();
         }
     }
void T(){
     F();
      Tp();
     }
void Tp(){ 
    if(in[i]=='*'){
         i++; 
         F();
          Tp();
         } 
        }
void F(){
    if(in[i]=='('){ 
        i++;
         E(); 
        if(in[i]==')') 
        i++; 
        else err=1; 
    }
    else if(isalpha(in[i])){
        i++;
        while(isalnum(in[i])||in[i]=='_') 
        i++;
    } 
    else 
    err=1;
}