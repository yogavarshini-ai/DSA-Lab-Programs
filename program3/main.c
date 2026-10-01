#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20
struct stack
{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,float item)
{
    s->data[++(s->top)]=item;
}
char pop(STACK *s)
{
    return(s->data[(s->top)--]);

    }
float compute(float oper1,char symbol,float oper2)
{
    switch(symbol)
    {
        case '+':return oper1+oper2;
         case '-':return oper1-oper2;
          case '*':return oper1*oper2;
           case '/':return oper1/oper2;
           case '^': return pow(oper1,oper2);
           }
}
float evalpostfix(STACK *s,char postfix[20])
{
    int i;
    char symbol;
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdidgit(symbol))
            push(s,symbol-'0');
        else
        {
            oper2=pop(s);
            oper1=pop(s);
            res=compute(oper1,symbol,oper2);
            push(s,res);
        }
    }
    return pop(s);
}
int main()
{
    char postfix[20];
    STACK s;
    s.top=-1;
    float ans;
    printf("\nread ppostfix expression\n")
    scanf("%s",postfix);
    ans=evalpostfix(&s,postfix);
    printf("\nthe final result");
    return 0;
}
