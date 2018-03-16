#include<stdio.h>
#include<string.h>
# define MAX 2
char x[10];
typedef struct stack
{
  char data [MAX][10];
  int top;
}stack;
int empty (stack *p)
{
 if (p->top  == -1)
 return (1);
 else
        return (0);
}
int full(stack *p)
{
 if (p->top == MAX-1)
       return (1);
 else
      return (0);
}
void push(stack *p, char *x)
{
   if(!full (p))
 {
    p -> top = p -> top + 1;
    strcpy(p->data[p->top],x);
 }
   else
 printf ("n stack is full");
}
char* pop (stack *p)
{

   if (!empty(p))
   {
   strcpy(x,p->data[p->top]);
   p->top = p->top - 1;
   return(x);
   }
   else
   {
   printf ("stack is empty:");
   return NULL;
   }
}
void display(stack s)
{
    printf("\n the contents of stack are:\n");
    int i=0;
    for(i=s.top;i>=0;i--)
    printf("%s\n",s.data[i]);
}

char* peek (stack s)
{

   if (!empty(&s))
   {
   strcpy(x,s.data[s.top]);
   return (x);
   }
   else
   {
   printf ("stack is empty:");
   return NULL;
   }
}
int main ()
{  stack s;
 char ch[10],*c;
 s.top = -1;

 while (1)
 {

  if(!full(&s))
     {   printf ("Enter  string to be pushed:");
         scanf("%s",ch);
         push(&s, ch);
     }
  else
    {
        printf ("\n stack is fullů");
        break;
    }
 }
display(s);
c=peek(s);
 printf("\nstacktop=%s\n",c);
 printf ("poped String \n");
 while (!empty(&s))
  {
    c = pop(&s);
    printf("%s\n",c);
  }
  return 0;
}