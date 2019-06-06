#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int nosr1=0;
int nosr2=0;
int p=0;
int q=0;
struct TRAIN{
int trainno,nos1,nos2,d,m,y,fare1,fare2;
char tname[20],bpt[20],dpt[20];
}T;


void traindata()
{
printf("Enter train N0.");
scanf("%d",&T.trainno);
printf("Enter train name");
scanf("%s",&T.tname);
printf("Enter boarding point");
scanf("%s",&T.bpt);
printf("Enter destination point");
scanf("%s",&T.dpt);
printf("Enter Date of travelling");
scanf("%d%d%d",&T.d,&T.m,&T.y);
printf("Enter number of seats in class 1");
scanf("%d",&T.nos1);
printf("Enter number of seats in class 2");
scanf("%d",&T.nos2);
printf("Enter fare of class 1");
scanf("%d",&T.fare1);
printf("Enter fare of class 2");
scanf("%d",&T.fare2);
}

void displaytrain()
{
printf("Train N0.%d\n",T.trainno);
printf("Train name.%s\n",T.tname);

printf("Boarding point.%s\ n",T.bpt);

printf("Destination point.%s\n",T.dpt);
printf("Date of travelling %d/%d/%d\n",T.d,T.m,T.y);

printf("Number of seats in class 1.%d\n",T.nos1);

printf("Number of seats in class 2.%d\n",T.nos2);

printf("Fare of class 1%d\n",T.fare1);

printf("Fare of class 2%d",T.fare2);

}

    struct reserve
{
int pnrno,age;
char psname[20];
}r1[10],r2[10];

void pnr1(int nsr1){

static int i;
for(i=0;i<nsr1;i++)
r1[i].pnrno=2*(i+1);
}
void pnr2(int nsr2){

static int i;
for(i=0;i<nsr2;i++)
r2[i].pnrno=2*(i)+1;
void rupdate()
{

    T.nos1-=nosr1;
    T.nos2-=nosr2;
}
void reservation()
{
int i,category,Tno,d,m,y;
char cl[20];int ch;
int amount;
do
{
printf("Enter train no");
scanf("%d",&Tno);
if(Tno==T.trainno)
printf("enter class");
scanf("%s",&cl);

if((strcmp(cl,"class1")==0)&&(nosr1<=T.nos1))
{
    printf("Enter number of seats required");
scanf("%d",&nosr1);
for(i=0;i<nosr1;i++){
printf("Enter passenger name");
scanf("%s",&r1[i].psname);
printf("Enter age");
scanf("%d",&r1[i].age);

}
amount=T.fare1*nosr1;
}
if(nosr1>T.nos1)
printf("seats not available in class 1");
/*void insert()
{char name[20];
printf("enter name");
	scanf("%s",name);
	if(rear==MAX-1)
			printf("\n Overflow");
	if(front==-1 && rear==-1)
			front=rear=0;
	else
		rear++;

	strcpy(W[rear],name);
}*/

pnr1(nosr1);
else if((strcmp(cl,"class2")==0)&&(nosr2<=T.nos2))
{
     printf("Enter number of seats required");
scanf("%d",&nosr2);
for(i=0;i<nosr2;i++){
printf("Enter passenger name");
scanf("%s",&r2[i].psname);
printf("Enter age");
scanf("%d",&r2[i].age);
}

amount=T.fare2*nosr2;
}
if(nosr2>T.nos2)
printf("seats not available in class 2");
/*void insert()
{char name[20];
printf("enter name");
	scanf(“%s”,name);
	if(rear==MAX-1)
			printf(“\n Overflow”);
	if(front==-1 && rear==-1)
			front=rear=0;
	else
		rear++;

	strcpy(W[rear],name);
}*/
pnr2(nosr2);
printf("enter date of travel");
scanf("%d%d%d",&d,&m,&y);
printf("The available categories for concession are:");
printf("1.Military\n");
printf("2.Senior citizens\n");
printf("3.Children below 5 years\n");
printf("4.None");
printf("Please enter choice:");
scanf("%d",&category);
switch(category)
{


case 1:amount=amount-amount*0.01;break;
case 2:amount=amount-amount*0.05;break;
case 3:amount=amount-amount*0.5;break;
case 4:printf("no concession");
}
printf("total amount %d",amount);
rupdate();
printf("want to reserve more seats(1/0)");
scanf("%d",&ch);
    }while(ch==1);
}

void cancellation()
{ int clas;
printf("enter class(1/2)");
scanf("%d",&clas);
if(clas==1)
printf("Enter pnrno");
scanf("%d",&p);
if(p%2==0)
printf("cancellation done");
else
    if(clas==2)
    printf("enter pnrno");
scanf("%d",&q);
if(q%2!=0)
printf("cancellation done");
else
printf("incorrect pnrno");

}


/*int delete()
{
	char  val[20];
	if(front==-1|| front>rear)
		{
			printf(“Underflow”);
			return -1;
		}
	else
		{
			strcpy(val,queue[front]);
			front++;
			return val;
		}
		printf("ticket confirmed");
	}*/
}

void viewcancellation1()

{
    printf("Name of the passenger:%s",R[p/2-1].psname);
    printf("Age:%d",R[p/2-1].age);

}
void viewcancellation2()

{
    printf("Name of the passenger:%s",R[(q-1)/2].psname);
    printf("Age:%d",R[(q-1)/2].age);

}
void viewreserve1()
{int i;
for(i=0;i<nosr1;i++){
printf("pnrno:%d",r1[i].pnrno);
printf("Name:%s",r1[i].psname);
printf("Age:%d",r1[i].age);
}
printf("Date of Travel%d/%d/%d",T.d,T.m,T.y);
}

void viewreserve2()
{int i;
for(i=0;i<nosr2;i++){
printf("pnrno:%d",r2[i].pnrno);
printf("Name:%s",r2[i].psname);
printf("Age:%d",r2[i].age);
}
printf("Date of Travel%d/%d/%d",T.d,T.m,T.y);
}
void main()
{
int ch;
do
{
printf("WELCOME TO RAILWAY RESERVATION SYSTEM\n\nthe menu is as follows:\n\n1-adding train details\n2-view available trains\n3-ticket reservation\n4-display information\n5-ticket cancellation\n6-back to menu");
printf("\nenter choice");
scanf("%d",&ch);

switch(ch)
{
case 1:traindata();break;
case 2:displaytrain();break;
case 3:reservation();break;
case 4:viewreserve();break;
case 5:cancellation();break;
case 6:viewcancellation();break;
default:printf("invalid choice");
}
}while(ch<=6);
}
