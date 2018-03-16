#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int info;
	struct NODE *link;
};

typedef struct NODE * NODEPTR;

NODEPTR allocNode(void);
void ReleaseNode(NODEPTR);
NODEPTR insertFront(NODEPTR, int);
NODEPTR insertAtEnd(NODEPTR, int);
NODEPTR deleteFirst(NODEPTR);
NODEPTR deleteRear(NODEPTR);
void dispList(NODEPTR);
NODEPTR insertAtPos(NODEPTR, int, int);
NODEPTR reverseList(NODEPTR);

int main()
{
    NODEPTR head = NULL;
    int iChoice, iVal, iPos;
    head=allocNode();
    head->info=0;
    head->link=NULL;

	for(;;)
	{
		printf("\nLIST OPERATIONS\n");
		printf("====================");
		printf("\n0.Insert Front\n1.Insert Rear\n2.Delete Front\n3.Delete Rear\n4.Display\n5.Insert at Position\n6.Reverse List\n7.Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 0: printf("\nEnter Element to be inserted\n");
				scanf("%d",&iVal);
                head= insertFront(head,iVal);
				break;

			case 1: printf("\nEnter Element to be inserted\n");
				scanf("%d",&iVal);
				head = insertAtEnd(head,iVal);
				break;

			case 2: head = deleteFirst(head);
				break;

			case 3: head = deleteRear(head);
				break;

			case 4: dispList(head);
				break;

			case 5: printf("\nEnter Element to be inserted\n");
				scanf("%d",&iVal);
				printf("\nEnter position at which element is to be inserted\n");
				scanf("%d",&iPos);
				head = insertAtPos(head,iVal,iPos);
				break;

			case 6: head = reverseList(head);
                break;

			case 7: exit(0);
		}
	}

    return 0;
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
NODEPTR insertFront(NODEPTR head, int value)
{
	NODEPTR temp;

	temp = allocNode();
	temp->info = value;
	temp->link = head->link;
	head->link=temp;
    head->info++;

  	return head;

}

NODEPTR insertAtEnd(NODEPTR head, int value)
{
	NODEPTR temp,cur;

	temp = allocNode();
	temp->info = value;
	temp->link = NULL;
	cur = head;
    while(cur->link != NULL)
    {
            cur = cur->link;
    }
    cur->link = temp;
    head->info++;
    return head;
}
NODEPTR deleteFirst(NODEPTR head)
{
    NODEPTR temp;
	if(head->link == NULL)
	{
		printf("\nList is empty cannot delete\n");
		return head;
	}
	temp = head->link;
	printf("\nElement deleted is %d \n",temp->info);
	head->link=temp->link;
	ReleaseNode(temp);
    head->info--;
	return head;
}

NODEPTR deleteRear(NODEPTR head)
{
    NODEPTR temp;
	if(head->link == NULL)
	{
		printf("\nList is empty cannot delete\n");
		return head;
	}
	temp = head;
	while(temp->link->link!= NULL)
	{
		temp = temp->link;
	}

	printf("\nElement deleted is %d \n",temp->link->info);

	ReleaseNode(temp->link);
	temp->link = NULL;
	head->info--;
	return head;
}

void dispList(NODEPTR head)
{
	NODEPTR curr;
	int i=1;
	if(head->link == NULL)
	{
		printf("\nList is empty\n");
		return;
	}

	printf("\nThe contents of the list are :\n");
	printf("\tAddress\t\tValue\tNextAddress");
	curr = head->link;
    printf("\nHead-Node \t%p\t%3d\t%p",head,head->info,head->link);

	while(curr != NULL)
	{
		printf("\n\tNode %d\t%p\t%3d\t%p",i++,curr,curr->info,curr->link);
		curr = curr->link;
	}
	printf("\n");
}

NODEPTR insertAtPos(NODEPTR first, int value, int pos)
{
	NODEPTR temp,prev,cur;
	int count;
	count = 1;
	prev = first;
	cur = first->link;

	while(cur != NULL && count != pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}

	if(count == pos)
	{
		prev->link = temp;
		temp->link = cur;
		first->info++;
		return first;
	}

	printf("\nInvalid Position!!!\n");
	return first;
}

NODEPTR reverseList(NODEPTR first)
{
   NODEPTR rev = NULL,temp,cur;
    cur=first->link;
	while(cur!=NULL)
	{
		temp = cur;
		cur = cur->link;
		temp->link = rev;
		rev = temp;
	}
	first->link=rev;
	return first;
}

