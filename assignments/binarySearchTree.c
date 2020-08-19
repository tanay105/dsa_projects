#include<stdio.h>
#include<curses.h>
typedef struct tree
{
	int info;
	int used;
}n[100];
void create();
void display();
void insert();
int main()
{
	create();
	insert();
	display();
	getch();
	return 0;
}
void create()
{
	int i;
	printf("Enter the root node value of the tree");
	scanf("%d",&n[0].info);
	n[0].used=1;
	for(i=1;i<100;i++)
	{
		n[i].used=0;
		n[i].info=0;
	}
}
void insert()
{
	int x;
	char n;
	while(n!='n')
	{
	printf("\nEnter the value to be inserted");
	scanf("%d",&x);
	int p=0;
	while(p<100 && n[p].used==1)
	{
		if(x<n[p].info)
		{
			p=2*p+1;
		}
		else
		{
			p=2*p+2;
		}
	}
	n[p].info=x;
	n[p].used=1;
	printf("\npress n to stop inserting values else press anything");
	n=getch();
	}
}
void display()
{
	int i;
	for(i=0;i<20;i++)
	{
		
		printf("\n%d",n[i].info);
	}
}
