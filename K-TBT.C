5#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct tree
{
   int info;
   struct tree *lptr,*rptr;
   int lthread;
   int rthread;
};
typedef struct tree *NODE;
NODE head;
void main()
{
     void CREATE(int);
     void INORDER(void);
     int choice,data;
     head=(NODE)malloc(sizeof(NODE));
     head->lptr=head->rptr=head;
     clrscr();

     while(1)
     {
	 printf("\n1:INSERT\n2:INORDER_TRAVERSE\n3:EXIT\n");
	 printf("Enter your choice: ");
	 scanf("%d",&choice);
	 switch(choice)
	 {
	    case 1: printf("\nEnter the data: ");
		    scanf("%d",&data);
		    CREATE(data);
		    break;
	    case 2: INORDER();
		    break;
	    case 3: exit(0);
	    default: printf("\nInvalid choice\n");
	 }
      }
   }

   void CREATE(int data)
   {
       NODE newnode,prev,cur,temp;
       newnode=(NODE*)malloc(sizeof(NODE));
       newnode->info=data;
       newnode->lptr=newnode->rptr=NULL;
       newnode->lthread=newnode->rthread=1;

       if(head->lptr==head)
       {
	   head->lptr=newnode;
	   newnode->lptr=newnode->rptr=head;
	   return;
       }
       cur=head->lptr;
       while(1)
       {
	   prev=cur;
	   if(data < cur->info)
	  {
	     cur=cur->lptr;
	     if(prev->lthread==1)
		break;
	  }
	 else if(data > cur->info)
	 {
	    cur=cur->rptr;
	    if(prev->rthread==1)
	       break;
	 }
	 else
	 {
	    printf("\nDATA ALREADY EXISTS !!!\n");
	    return;
	 }
      }
      if(data < prev->info)
      {
	 prev->lptr=newnode;
	 prev->lthread=0;
	 newnode->lptr=cur;
	 newnode->rptr=prev;
      }
      else
      {
	 prev->rptr=newnode;
	 prev->rthread=0;
	 newnode->lptr=prev;
	 newnode->rptr=cur;
      }
      printf("\n%d is inserted into In-threaded Binary tree\n",data);
   }



    void INORDER(void)
    {
       NODE p,q,r;
       q=head;
       p=head->lptr;
       if(head->lptr==head)
       {
	  printf("\nEMPTY TREE !!!\n");
	  return;
       }
       printf("\nINORDER TRAVERSAL OF IN-THREADED BINARY TREE:\n");
       do
       {
	   r=q;
	   while(p!=r)
	   {
	       q=p;
	       p=p->lptr;
	    }

	    if(q!=head)
	    {
	       printf("%d ",q->info);
	       p=q->rptr;
	       while(q->rthread==1 && p!=head)
	       {
		   printf("%d ",p->info);
		   q=p;
		   p=p->rptr;
	       }
	    }
	}while(p!=head);
    }


