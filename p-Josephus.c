#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXLEN 30

struct NODE{
    char name[MAXLEN];
    struct NODE *link;
};

typedef struct NODE* NODEPTR;

NODEPTR allocNode();
void releaseNode(NODEPTR);
NODEPTR insRear(NODEPTR , char []);

int main()
{
    NODEPTR last = NULL, cur,prev;
	int i, iNum, iSpNum;
	char soldierName[MAXLEN];
	printf("\nEnter the number of soldiers : ");
	scanf("%d",&iNum);
	for(i=0;i<iNum;i++)
	{
		printf("\nEnter the name of soldier %d : ",i+1);
		scanf("%s",soldierName);
		last = insRear(last, soldierName);
	}
    printf("\nEnter a value larger than 1 for the counter\n");
    scanf("%d",&iSpNum);
	printf("\nCounter value is : %d\n",iSpNum);
	cur = last->link;
	while(last->link != last)
	{
		for(i=0;i<iSpNum;i++)
		{
			prev =cur;
			cur = cur->link;
		}
		printf("\nEliminated Soldier is : %s\n", cur->name);
		getchar();
		if(last == cur)
            last = prev;
		prev->link = cur->link;
		releaseNode(cur);
       cur=prev->link;
	}
	printf("\nSoldier chosen to bring in reinforcements is : %s\n",last->name);
	return 0;
}

NODEPTR insRear(NODEPTR last, char name[])
{
    NODEPTR temp, first;
    temp = allocNode();
	strcpy(temp->name,name);

    if(last == NULL)
    {
        last = temp;
        temp->link = last;
        return last;
    }
    first = last->link;
    last->link = temp;
    temp->link = first;
    return temp;
}

NODEPTR allocNode()
{
    NODEPTR newborn;
    newborn = (NODEPTR) malloc(sizeof(struct NODE));
    if(newborn == NULL)
    {
        printf("\nInsufficient Memory\n");
        exit(0);
    }
    return newborn;
}

void releaseNode(NODEPTR p)
{
    free(p);
}
