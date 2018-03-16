#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
   float coeff;
   float powx;
   float powy;
   int flag;
   struct node *next;
};
typedef struct node *NODEPTR;

NODEPTR read_p(NODEPTR );

void print_p(NODEPTR);
float eval_p(NODEPTR);
NODEPTR add_p(NODEPTR,NODEPTR,NODEPTR);
NODEPTR insert_p(NODEPTR,float,float,float);
int main()
{
    int choice;

    NODEPTR p1=NULL,p2=NULL,p3=NULL;
   
    printf("\nEnter first polynomial type -999 for coeff to terminate\n");
    p1=read_p(p1);

    printf("\nEnter second polynomial type -999 for coeff to terminate\n");
    p2=read_p(p2);

    printf("\nThe First Polynomial:\n");
    print_p(p1);

    printf("\nThe Second Polynomial:\n");
    print_p(p2);
    printf("\n1:EVALUATE_POLYNOMIALS\n2:ADD_POLYNOMIALS\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
	case 1: printf("\nFIRST POLYNOMIAL EVALUATION:\n");
		printf("\nResult = %f\n",eval_p(p1));
		printf("\nSECOND POLYNOMIAL EVALUATION:\n");
		printf("Result = %f\n",eval_p(p2));
		break;

	case 2: p3=add_p(p1,p2,p3);
		printf("\nRESULTANT POLYNOMIAL AFTER ADDITION:\n");
		print_p(p3);
		break;
	default: printf("\nInvalid choice\n");
     }

  }

void print_p(NODEPTR p)
  {
      if(p==NULL)
      {
	  printf("\nPolynomial doesn't exist\n");
	  return;
      }
      while(p->next!=NULL)
      {
	 printf("%6.1fx^%3.1fy^%3.1f +",p->coeff,p->powx,p->powy);
	 p=p->next;
      }
      printf("%6.1fx^%3.1fy^%3.1f",p->coeff,p->powx,p->powy);
   }

NODEPTR read_p(NODEPTR p)
   {
       float cf,px,py;

       printf("Enter coefficient: ");
       scanf("%f",&cf);
       while(cf!=-999)
       {
	    printf("\nEnter power of x: ");
	    scanf("%f",&px);
	    printf("\nEnter power of y: ");
	    scanf("%f",&py);
	    p=insert_p(p,cf,px,py);

	    printf("\nEnter coefficient: ");
	    scanf("%f",&cf);
	}
	 return(p);
    }

NODEPTR insert_p(NODEPTR p,float cf,float px,float py)
{
	 NODEPTR newnode,temp;
	 newnode=(NODEPTR)malloc(sizeof(NODEPTR));
	 newnode->coeff=cf;
	 newnode->powx=px;
	 newnode->powy=py;
	 newnode->flag=0;
	 newnode->next=NULL;
	 if(p==NULL)
	    p=newnode;
	 else
	 {
	     temp=p;
	     while(temp->next!=NULL)
		 temp=temp->next;
	      temp->next=newnode;
	  }
	  return(p);
}


float eval_p(NODEPTR p)
    {
	float x,y,sum=0;
	printf("\nEnter the value of x: ");
	scanf("%f",&x);

	printf("\nEnter the value of y: ");
	scanf("%f",&y);

	while(p!=NULL)
	{
	   sum=sum+p->coeff*pow(x,p->powx)*pow(y,p->powy);
	   p=p->next;
	}
	return(sum);
}

NODEPTR add_p(NODEPTR p1,NODEPTR p2,NODEPTR p3)
{
	float cf;
	NODEPTR temp;
	temp=p2;
	while(p1!=NULL)
	 {

	     while(p2!=NULL)
	     {
		if((p1->powx==p2->powx)&&(p1->powy==p2->powy))
		     break;
		p2=p2->next;
	     }
	     if(p2!=NULL)
	     {
		cf=p1->coeff + p2->coeff;
		p2->flag=1;
		if(cf!=0)
		    p3=insert_p(p3,cf,p1->powx,p1->powy);
	     }
	     else
		p3=insert_p(p3,p1->coeff,p1->powx,p1->powy);

	     p1=p1->next;
	     p2=temp;
	 }
	 p2=temp;
	 while(p2!=NULL)
	 {
	     if(p2->flag==0)
		 p3=insert_p(p3,p2->coeff,p2->powx,p2->powy);
	      p2=p2->next;
	 }
	 return(p3);
}