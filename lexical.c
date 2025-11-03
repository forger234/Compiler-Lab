#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main() 
{
 FILE *input, *output;
 int l=1, t=0, j=0,i,flag;
 char ch,str[20];
 input = fopen("input.txt","r");
 output = fopen("output.txt","w");
 char keyword[30][30] = {"int","main","if","else","do","while"};
 fprintf(output,"Line no. \t Token no. \t\t Token \t\t Lexeme\n\n");
 while(!feof(input)) 
 {
  i=0;
  flag=0;
  ch=fgetc(input);
  if( ch=='+'||  ch== '-' || ch=='*' || ch=='/' )
  {
   fprintf(output,"%7d\t\t %7d\t\t Operator\t %7c\n",l,t,ch);
   t++;
  }
  else if( ch==';' || ch=='{'||  ch=='}' || ch=='(' || ch==')' || ch=='?' || ch=='@'|| ch=='!' || ch=='%' ||   ch=='=')
  {
   fprintf(output,"%7d\t\t %7d\t\t Special symbol\t %7c\n",l,t,ch);
   t++;
  }
  else if(isdigit(ch))
  {
   fprintf(output,"%7d\t\t %7d\t\t Digit\t\t %7c\n",l,t,ch);
   t++;
  }
  else if(isalpha(ch))
{
  i = 0;
  str[i++] = ch;
  while ( (ch = fgetc(input)) != EOF && isalnum(ch) ) {
    if (i < sizeof(str)-1) 
    str[i++] = ch;
  }
  str[i] = '\0';
  if (ch != EOF) 
  ungetc(ch, input);
  flag = 0;
  for(j = 0; j < 6; j++) {
    if(strcmp(str, keyword[j]) == 0) {
      flag = 1; 
      break;
    }
  }
  fprintf(output, "%7d\t\t %7d\t\t %s\t\t %7s\n", l, t, flag ? "Keyword" : "Identifier", str);
  t++;
}
  else if(ch=='\n')
  {
   l++;
  }
 }
 fclose(input);
 fclose(output);
 return 0;
 }
