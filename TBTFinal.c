#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct NODE
{
	int info;
	struct NODE *lchild;
	struct NODE *rchild;
	bool rthread;
};

typedef struct NODE* NODEPTR;

NODEPTR allocNode();
void insertLeft(NODEPTR, int);
void insertRight(NODEPTR, int);
NODEPTR buildTree(NODEPTR, int);
void inorder(NODEPTR);
NODEPTR inorder_successor(NODEPTR);


int main(void)
{
	NODEPTR head;
	int ch,item;
	head = allocNode();
	head->rchild = head;
	head->lchild = head;
	head->rthread = false;
	for(;;)
	{
		printf("\n1.Insert\n2.Inorder traversal\n3.Exit\n");
		printf("\nEnter your choice");
		scanf("%d",&ch);
        getchar();
		switch(ch)
		{
			case 1: printf("Enter the item to be inserted \n");
					scanf("%d",&item);
					head = buildTree(head, item);
					break;

			case 2: inorder(head);
                    printf("\n");
                    break;

			case 3: exit(0);

			default: printf("Wrong choice\n");
					 break;
		}
	}
	return 0;
}

NODEPTR allocNode()
{
	NODEPTR newborn;
	newborn = (NODEPTR)malloc(sizeof(struct NODE));
	if(newborn == NULL)
	{
		printf("\nMemory Overflow");
		exit(0);
	}
	return newborn;
}

NODEPTR inorder_successor(NODEPTR ptr)
{
	NODEPTR temp;
	temp = ptr->rchild;
	if(ptr->rthread)
		return temp;
	while(temp->lchild != NULL)
		temp = temp->lchild;
	return temp;
}

void inorder(NODEPTR head)
{
    NODEPTR temp;
	if(head->lchild == head)
	{
		printf("\nTree is empty\n");
		return;
	}
	printf("\nInorder traversal is : \n");
	temp = head;
	for(;;)
	{
		temp = inorder_successor(temp);
		if(temp == head)
			return;
		printf("%d\t", temp->info);
	}
}

void insertLeft(NODEPTR ptr, int item)
{
	NODEPTR temp;
	temp = allocNode();
	temp->info = item;
	ptr->lchild = temp;
	temp->lchild = NULL;
	temp->rchild = ptr;
	temp->rthread = true;
}
void insertRight(NODEPTR ptr, int item)
{
	NODEPTR temp, right;
	temp = allocNode();

	temp->info = item;
	right = ptr->rchild;
	ptr->rchild = temp;
	ptr->rthread = false;

	temp->lchild = NULL;
	temp->rchild = right;
	temp->rthread = true;
}

NODEPTR buildTree(NODEPTR head, int item)
{
	char direction;
	NODEPTR cur;

	if(head->lchild == head)
	{
		insertLeft(head, item);
		return head;
	}

	cur = head->lchild;

    getchar();
	for(;;)
	{
		printf("Insert %d towards left or right of %d", item, cur->info);
		direction = getchar();
		getchar();
		if(direction == 'l')
		{
			if(cur->lchild == NULL)
			{
				insertLeft(cur, item);
				return head;
			}
			else
				cur = cur->lchild;
		}
		else
		{
			if(cur->rthread)
			{
				insertRight(cur, item);
				return head;
			}
			else
				cur = cur->rchild;
		}
	}
}



