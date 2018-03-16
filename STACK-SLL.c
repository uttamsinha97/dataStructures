#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct NODE
{
	int info;
	struct NODE *link;
};
typedef struct NODE* NODEPTR;

void disp(NODEPTR first)
{
	NODEPTR curr;
	int i=1;
	if(first == NULL)
	{
		printf("\nList is empty\n");
		return;
	}

	printf("\nThe contents of the list are :\n");
	printf("\tAddress\t\tValue\tNextAddress");
	curr = first;
	while(curr != NULL)
	{
		printf("\nNode %d\t%p\t%3d\t%p",i++,curr,curr->info,curr->link);
		curr = curr->link;
	}
	printf("\n");
}

NODEPTR allocNode(void)
{
	NODEPTR newborn;
	newborn = (NODEPTR)malloc(sizeof(struct NODE));

	if(newborn == NULL)
	{
		printf("\nInsufficient Memory");
		exit(0);
	}
	return newborn;
}

void ReleaseNode(NODEPTR x)
{
	free(x);
}
NODEPTR pop(NODEPTR first)
{
    NODEPTR temp;
	if(first == NULL)
	{
		printf("\nList is empty cannot delete\n");
		return first;
	}
	temp = first;
	first = first->link;

	printf("\nElement popped is %d \n",temp->info);
	ReleaseNode(temp);

	return first;
}

NODEPTR push(NODEPTR first, int value)
{
	NODEPTR temp;

	temp = allocNode();
	temp->info = value;
	temp->link = first;
  	return temp;

}
bool isEmpty(NODEPTR first)
{
    if(first==NULL)
    return 1;
    else return 0;
}

int main()
{
    NODEPTR top = NULL;
    int iChoice, iVal, iPos;

	for(;;)
	{
		printf("\nSTACK OPERATIONS\n");
		printf("====================");
		printf("\n1.PUSH\n2.POP\n.3.Display\n");
		printf("\nEnter your choice\n");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1: printf("\nEnter Element to be pushed\n");
				scanf("%d",&iVal);
				top = push(top,iVal);
				break;

			case 2: if(isEmpty(top))
			         printf("\nStack underflow cannot delete\n");
                        else
                        {
				        top = pop(top);
                        }
				          break;


			case 3: if(isEmpty(top))
			         printf("\nStack underflow cannot display\n");
                        else
                        {
                        disp(top);
                        }
                    break;

			case 4: exit(0);

		}
	}
}
