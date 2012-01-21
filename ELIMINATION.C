#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

struct node
{
char name[50];
struct node *new1;
};

struct node *first=NULL;
struct node *new1;
struct node *temp;

void insert(char na[],int start) //This function will insert a node into the circular new1 list
{
  new1=(struct node*)malloc(sizeof(struct node));//create memory for new node
  strcpy(new1->name,na);
  new1->new1=new1;             //   create node

  if(start==NULL)
  {     first=new1;  }
  else
  {
     temp=first->new1;
     while(temp->new1!=first)
     { 	temp=temp->new1;     }

     new1->new1=temp->new1;
     temp->new1=new1;
  }
}

void show()  // This function is used to traverse the circular list
{
   int i=2;
   if(first==NULL)
   {
      printf("\nEmpty List");
      return;
   }
   else
   {
      printf("\n %s",first->name);
      temp=first->new1;
      while(temp!=first)
      {
	printf("   %s ",temp->name);
	temp=temp->new1;
	i++;
      }
   }
}

void eliminate(int d)  //Usind This function we delete the node at position 'd'
{
  int i;
  struct node *prev;
  while(first->new1!=first)
  {
      if(d==1)
      {
	printf("\n    => %s  IS ELIMINATED\n",first->name);
	temp=first->new1;
	while(temp!=first)
	{
	   prev=temp;
	   temp=temp->new1;
	}
	prev->new1=temp->new1;
	first=prev->new1;
	show();
      }
      else
      {
	temp=first;
	for(i=1;i<d;i++)
	{
	  prev=temp;
	  temp=temp->new1;
	}
	prev->new1=temp->new1;
	printf("\n    => %s  IS ELIMINATED\n",temp->name);
	first=prev->new1;
	show();
      }
      delay(500);
   }
}

void main()
{
  int i,choice,M,N; //M:number of kids,N:random number,choice:for switch case.
  char na[50];
  clrscr();

  while(choice!=2)
  {
    printf("\n1)START");
    printf("\n2)QUIT");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);

   switch(choice)
   {
    case 1:printf("\nENTER NUMBER OF PLAYERS :");
	   scanf("%d",&M);
	   for(i=1;i<=M;i++)
	   {
		   printf("\nNAME OF PLAYER %d :",i);
		   flushall();
		   gets(na);
		   insert(na,i-1);  //This function inserts the node into linked list
	   }

	    printf("\nENTER RANDOM NUMBER BETWEEN (1 TO %d) :",M-1);
	    scanf("%d",&N);
	    printf("\nREMAINING PLAYERS ARE : ");
	    show();
	    eliminate(N); //This function starts the game of elimination
	    printf("\n\n  CONGRATES %s , YOU WIN THE GAME",first->name);

	    break;
    case 2: exit(0);
	    break;
    default:printf("\NWRONG CHOICE");
   }
  }
  getch();
}
