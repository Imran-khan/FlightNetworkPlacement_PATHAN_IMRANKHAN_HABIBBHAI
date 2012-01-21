#include<stdio.h>
#include<conio.h>

struct node
{
int info;
struct node *link;
};
struct node *first=NULL;
struct node *new1;
struct node *temp;

void push(int data)  //this function is used  to push data into stack
{
  new1=(struct node*)malloc(sizeof(struct node));//create memory for new node
  new1->info=data;
  new1->link=NULL;         //create node

    if(first==NULL)
    {    first=new1;  }

    else
    {
	temp=first;
	while(temp->link!=NULL)
	{
	  temp=temp->link;
	}
	temp->link=new1;
    }
}

int pop()      //this function is used to pop data from stack
{
  int data;
  struct node *prev;

  if(first==NULL)
  { printf("\nAll the element are popped.");
    return -1;
  }
  else
  {
    temp=first;
    while(temp->link!='\0')
    { prev=temp;
      temp=temp->link;
    }
    if(temp==first)
    {
      data=temp->info;
      first='\0';
    }
    else
    {
      data=temp->info;
      prev->link=temp->link;
    }
    return data;
  }
}

void main()
{
  int i,choice,no,x,last=0;
  int pattern[20],p=0;
  clrscr();

   while(choice!=3)
   {
    printf("\n[1] : PUSH");
    printf("\n[2] : POP");
    printf("\n[3] : EXIT");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:printf("\nEnter Number:");
	     scanf("%d",&no);
	     if(no>9)
	     { printf("\n YOU MUST RE-ENTER NUMBER BETWEEN (0- 9):");}

	     else if(no>=last+2||no<=last)
	     {
	       if(no==0)
	       { push(no);}
	       else
	       {
	       printf("\n LAST PUSHED NUMBER:%d",last);
	       printf("\n PLESE PUSH NUMBER IN PROPER SEQUENCE\n");
	       }
	     }
	     else
	     {
	       last=no;
	       push(no);
	     }
	     break;
       case 2: x=pop();
	     if(x!=-1)
	     {
	      pattern[p++]=x;
	      printf("\nPOP:%d",x);
	     }
	     printf("\nPATTERN:");
	     for(i=0;i<p;i++)
	     {  printf("%d ",pattern[i]); }
	     printf("\n");
	     break;
      case 3: exit(0);
	     break;
     default:printf("\n Enter Proper Choice");
    }
   }
   getch();
}