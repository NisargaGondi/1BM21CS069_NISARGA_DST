#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX];
char infix[MAX];
char postfix[MAX];
void intopo();
void print();
int top=-1;
int precedence(char);
void push(char);
char pop();
int Isempty();
int main()
{
 printf("enter your expresion\n");
 gets(infix);
 intopo();
 print();
 return 0;
}
void intopo()
{
   int j=0;
    char symbol;char next;
    for( int i=0;i<strlen(infix);i++)
    { 
        symbol=infix[i];
        switch (symbol)
        {
        case '(' :
             push(symbol);
            break;

             case ')':
             while((next=pop())!='(')
             postfix[j++]=next;
             break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
            while(!Isempty()&&precedence(stack[top])>=precedence(symbol))
            postfix[j++]=pop();
            push(symbol);
            break;
        
        default:
        postfix[j++]=symbol;
            break;
        }

    }
    while(!Isempty())
    postfix[j++]=pop();
    postfix[j]='\0';
}

int precedence(char symbol)
{
     if(symbol=='^')
     return 3;
     else if(symbol=='/' || symbol == '*')
     return 2;
     else if (symbol=='+' || symbol == '-')
     return 1;
     else 
     return 0;

}
void push(char c){
    if(top==MAX-1){
        printf("\nSTACK OVERFLOW\n");
        return;
    }
    else{
        top++;
        stack[top]=c;
    }
}
char pop(){
    char c;
    if(top==-1){
        printf("\nSTACK UNDERFLOW\n");
    }
    else{
     c= stack[top];
        top--;
      return c;
    }
}
void print()
{
    printf("%s", postfix);
}
int Isempty()
{
if(top==-1)
return 1;
else return 0;
}
