#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
typedef struct
{
    char items[20];
    int top;
}STACK;
void main()
{
    void PUSH(STACK *,char);
    char POP(STACK *);
    int preced(char);
    char infix[20],postfix[20],symbol,ch;
    STACK s;
    int i,j=0;

    printf("\nEnter a valid infix expression");
    scanf("%s",infix);
    s.top=-1;
    PUSH(&s,'#');

    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];

        if(isalnum(symbol))
           postfix[j++] = symbol;
        else
        {
           switch(symbol)
          {
               case '(': PUSH(&s,symbol);
                         break;

               case ')':  while((ch=POP(&s))!='(')
                               postfix[j++]=ch;
                          break;
               default:  while(preced(symbol)<=preced(s.items[s.top]))
                         {
                               if((symbol==s.items[s.top]) && (preced(symbol)==3))
                                  break;
                               postfix[j++]=POP(&s);
                         }

                         PUSH(&s,symbol);

           }
        }
     }
    while(s.top>0)
       postfix[j++]=POP(&s);
    postfix[j]='\0';

    printf("\nEquivalent postfix expression: %s",postfix);
}

void PUSH(STACK *s,char ch)
{
     s->top++;
     s->items[s->top]=ch;
}


char POP(STACK *s)
{
    char ch;
    ch = s->items[s->top];

    s->top--;
    return(ch);
}


int preced(char ch)
{
    switch(ch)
    {
        case '#':
        case '(': return(0);

        case '+':
        case '-': return(1);

        case '*':
        case '/':
        case '%': return(2);

        case '$':
        case '^': return(3);
    }
}
