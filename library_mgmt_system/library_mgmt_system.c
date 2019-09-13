/****Library management system****/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct book
{
	char name[20];
	int id;
	int day;
	int month;
	int year;
	struct book *next;
};
struct student
{
	char name[20];
	char reg[10];
	struct book *next1;
	struct student *next2;
}; 
struct student * createstudentdata();
void display(struct student *);
void bookentry(struct student *);
void morebook(struct book *);
void displaydetailsofstudent(struct student *);
void returningofbook(struct student *);
void displaystudentrecord(struct student *);
void adddatatostudentrecord(struct student *);
int calculateday(int ,int ,int );
int days(int,int,int,int,int,int);
int month(int,int);
int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int calculate(int);
int main()
{
	//Addressing the viewer.
	printf("Hello and welcome to the library management system of VIT");
	printf("\nStarting for the day");
	struct student *node1;
	node1=NULL;
	char ch;
	while(ch!='n')
	{
		printf("\nTo perform the following operations please enter the respective number:-");
		printf("\nPress\n1.To create student record\n2.To enter the details of a book issued to a particular student.\n3.To display the details of issued books of a student.\n4.Return the book to the Incharge.\n5.Display students record.\n6.To add more students to the record.\n");
		int i=-1;
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				node1=createstudentdata();
				break;
			case 2:
				bookentry(node1);
				break;
			case 3:
				displaydetailsofstudent(node1);
				break;
			case 4:
				returningofbook(node1);
				break;
			case 5:
				displaystudentrecord(node1);
				break;
			case 6:
				adddatatostudentrecord(node1);
				break;
			default:
				printf("Enter from the given choices only");
				continue;
		}
		printf("\nPress y to continue or n to stop performing operations");
		ch=getch();
	}
	getch();
	return 0;
}
struct student * createstudentdata()
{
	//Creating the first node.
	struct student *node,*head;
	node=(struct student *)malloc(sizeof(struct student));
	//getting details of name and registration number.
	printf("\nEnter the name of the student:");
	scanf("%s",node->name);
	printf("Enter the reg. no. of the student:");
	scanf("%s",node->reg);
	node->next1=NULL;
	node->next2=NULL;
	head=node;
	char ch;
	while(ch!='n')
	{
		struct student *newnode;
		newnode=(struct student *)malloc(sizeof(struct student));
		printf("\nEnter the name of the student:");
		scanf("%s",newnode->name);
		printf("Enter the reg. no. of the student:");
		scanf("%s",newnode->reg);
		newnode->next2=NULL;
		newnode->next1=NULL;
		node->next2=newnode;
		node=newnode;
		printf("\nPress y to continue and n to stop entering the details of the student");
		ch=getch();
	}
	return head;
}
void displaystudentrecord(struct student *node)
{
	if(node==NULL)
	{
		printf("No Student record to be displayed\n");
	}
	else
	{
		printf("\nNAME\t\t\t\tREGISTRATION NUMBER\n");
		while(node!=NULL)
		{
			printf("%s\t\t\t\t%s\n",node->name,node->reg);
			node=node->next2;
		}
	}
}
void bookentry(struct student *node)
{
	char na[10];
	printf("\nEnter the reg. no. of the student whose books has to be issued");
	scanf("%s",na);
	while(strcmp(node->reg,na)!=0)
	{
		node=node->next2;
	}
	struct book *book1;
	book1=(struct book *)malloc(sizeof(struct book));
	printf("Enter the name of the book");
	scanf("%s",book1->name);
	printf("Enter the unique book id");
	scanf("%d",&book1->id);
	printf("Enter the day, month and year on which the book is issued");
	scanf("%d%d%d",&book1->day,&book1->month,&book1->year);
	book1->next=NULL;
	node->next1=book1;
	int i=-1;
	printf("To enter more books press 1 else press 0:");
	scanf("%d",&i);
	if(i==1)
	{
		morebook(book1);
	}	
	else
	{
		printf("\nOKK!!!You don't want more books...\n");
	}
}
void morebook(struct book *boom)
{
	char ch;
	while(ch!='n')
	{
		struct book *newbook;
		newbook=(struct book *)malloc(sizeof(struct book));
		printf("Enter the name of the book");
		scanf("%s",newbook->name);
		printf("Enter the unique id of the book");
		scanf("%d",&newbook->id);
		printf("Enter the day, month and year on which the book is issued");
		scanf("%d%d%d",&newbook->day,&newbook->month,&newbook->year);
		newbook->next=NULL;
		boom->next=newbook;
		boom=newbook;
		printf("Press n to stop entering the details of the book");
		ch=getch();
	}
}
void displaydetailsofstudent(struct student *node)
{
	
		char ne[10];
		printf("\nEnter the reg. no. of the student whose issued books has to be displayed");
		scanf("%s",ne);
		while(strcmp(node->reg,ne)!=0)
		{
			node=node->next2;
		}
		printf("\nThe name of the student is\t");
		puts(node->name);
		if(node->next1==NULL)
		{
			printf("No book is issued for this person");
		}
		else
		{
			struct book *bookf;
			bookf=(struct book *)malloc(sizeof(struct book));
			bookf=node->next1;
			printf("NAME\t\tBOOK ID\t\tDATE OF ISSUE\n");
			do
			{
				printf("%s\t\t%d\t\t%d/%d/%d\n",bookf->name,bookf->id,bookf->day,bookf->month,bookf->year);
				bookf=bookf->next;
			}while(bookf!=NULL);
		}
}
void returningofbook(struct student *node5)
{
	char ret[10];
	int boom;
	int fine,day;
	printf("Enter the Registration number of the student whose book has to be returned");
	scanf("%s",ret);
	while(strcmp(node5->reg,ret)!=0)
	{
		node5=node5->next2;
	}
	struct book *node,*pre;
	node=node5->next1;
	printf("Enter the unique id of the book:");
	scanf("%d",&boom);
	if(node->id==boom)
	{
		day=calculateday(node->day,node->month,node->year);
		if(day<=14)
		{
			node5->next1=node->next;
		}
		else
		{
			fine=calculate(day);
			printf("\nThe fine to be paid on the book is %d",fine);
			int i=-1;
			//to check if money is given then only the name has to be removed from the database.
			printf("\nPress 1 is money is paid to you or 0 if not paid:");
			scanf("%d",&i);
			if(i==1)
			{
				node5->next1=node->next;
			}
		}
	}
	else
	{
		while(node->id!=boom)
		{
			pre=node;
			node=node->next;
		}
		day=calculateday(node->day,node->month,node->year);
		if(day<=14)
		{
			pre->next=node->next;
			free(node);
		}
		else
		{
			fine=calculate(day);
			printf("\nThe fine to be paid on the book is %d",fine);
			int i=-1;
			//to check if money is given then only the name has to be removed from the database.
			printf("\nPress 1 is money is paid to you or 0 if not paid");
			scanf("%d",&i);
			if(i==1)
			{
				pre->next=node->next;
				free(node);
			}
		}
	}
}
//Code to calculate the number of days and then subsequently calculating the fine amount 
int calculateday(int a1,int b1,int c1)
{
	int a2,b2,c2;
	printf("\nEnter the return date(dd mm yyyy) : ");
	//getting the second date value to calculate the number of days
	scanf("%d%d%d",&a2,&b2,&c2);
	int day;
	day=days(c1,c2,b1,b2,a1,a2);
	return day;
}

int days(int y1,int y2,int m1,int m2,int d1,int d2)
{
  int count=0,i;
  for(i=y1;i<y2;i++)
    {
    if(i%4==0)
    count+=366;
    else
    count+=365;
    }
  count-=month(m1,y1);
  count-=d1;
  count+=month(m2,y2);
  count+=d2;
  if(count<0)
  count=count*-1;
  printf("The no. of days b/w the 2 dates = %d days",count);
  return count;
}
int month(int a,int yy)
{
  int x=0,c;
  for(c=0;c<a-1;c++)
    {
   if(c==1)
      {
      if(yy%4==0)
      x+=29;
      else
      x+=28;
      }
    else
    x+=mon[c];
    }
  return(x);
}
//calculating the fine value from the number of days passed
int calculate(int f)
{
	int n, sum=0;
	n=f-14;
	if(n>0 && n<=7)
	{
		sum=n;
	}
	else if(n>7 && n<=14)
	{
		n=n%7;
		sum=7+(n*2);
	}
	else if(n>14 && n<=21)
	{
		n=n%14;
		sum=21+(n*3);
	}
	else if(n>21 && n<=40)
	{
		sum=100;
	}
	else if(n>40 && n<=75)
	{
		sum=200;
	}
	else if(n>75)
	{
		sum=500;
	}
	return sum;
}
void adddatatostudentrecord(struct student *node)
{
	if(node==NULL)
	{
		printf("No Student record initially!!!...\nFirst create record then use add option\n");
	}
	else
	{
		while(node->next2!=NULL)
		{
			node=node->next2;
		}
		char ch;
		while(ch!='n')
		{
			struct student *newnode;
			newnode=(struct student *)malloc(sizeof(struct student));
			printf("\nEnter the name of the student:");
			scanf("%s",newnode->name);
			printf("Enter the reg. no. of the student:");
			scanf("%s",newnode->reg);
			newnode->next2=NULL;
			newnode->next1=NULL;
			node->next2=newnode;
			node=newnode;
			printf("\nPress y to continue and n to stop entering the details of the student");
			ch=getch();
		}
	}
}


