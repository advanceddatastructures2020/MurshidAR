#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	struct node *next;
	int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();
void main()
{
	int choice=0;
	clrscr();
	while(choice!=9)
	{
		printf("1.insert at the beginning.\n2.insert at last.\n3.insert at random location.\n4.delete from beginning.\n5.delete from last.\n6.delete node after the given data.\m7.search.\n8.show.\n9.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insertion_beginning();
				break;
			case 2:
				insertion_last();
				break;
			case 3:
				insertion_specified();
				break;
			case 4:
				deletion_beginning();
				break;
			case 5:
				deletion_last();
				break;
			case 6:
				deletion_specified();
				break;
			case 7:
				search();
				break;
			case 8:
				display();
				break;
			case 9:
				exit(0);
				break;
			default:
				printf("invalid input!!");
			}
		}
	getch();
}

void inserton_beginning()
{
	struct node *ptr;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\noverflow");
	}
	else
	{
		printf("\nenter the value : ");
		scanf("%d",&item);
		if(head==NULL)
		{
			ptr->next=NULL;
			ptr->prev=NULL;
			ptr->data=item;
			head=ptr;
		}
		else
		{
			ptr->data=item;
			ptr->prev=NULL;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
		}
		printf("\n node inserted");
	}
}

void insert_last()
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\noverflow");
	}
	else
	{
		printf("\nenter the value :");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			ptr->prev=NULL;
			head=ptr;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=NULL;
		}
	}
	printf("\n node inserted");
}

void insert_specified()
{
	struct node *ptr,*temp;
	int item,loc,i;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\n overflow");
	}
	else
	{
		temp=head;
		printf("\nenter the location:");
		scanf("%d",&loc);
		for(i=0;i<loc;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("\n there are less than %d elements",loc);
				return;
			}
		}
		printf("\nenter the value :");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=temp->next;
		ptr->prev=temp;
		temp->next=ptr;
		temp->next->prev=ptr;
		printf("\n node inserted");
	}
}
void deletion_begin()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("\n undeflow");
	}
	else if(head->next == NULL)
	{
		head=NULL;
		free(head);
		printf("node deleted");
	}
	else
	{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		free(ptr);
		printf("node deleted");
	}
}

void deletion_last()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("\nunderflow");
	}
	else if(head->next == NULL)
	{
		head=NULL;
		free(head);
		printf("node delted");
	}
	else
	{
		ptr=head;
		if(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->prev->next=NULL;
		free(ptr);
		printf("node deleted");
	}
}

void deletion_specified()
{
	struct node *ptr,*temp;
	int val;
	printf("enter the data after which the node is to be deleted : ");
	scanf("%d",&val);
	ptr=head;
	while(ptr->next == NULL)
	ptr=ptr->next;
	if(ptr->next == NULL)
	{
		printf("\n cant delete");
	}
	else if(ptr->next->next == NULL)
	{
	ptr->next=NULL;
	}
	else
	{
		temp=ptr->next;
		ptr->next=temp->next;
		temp->next->prev=ptr;
		free(temp);
		printf("\n node deleted");
	}
}

void display()
{
	struct node *ptr;
	printf("\n printing values : \n");
	ptr=head;
	while(ptr != NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}

void search()
{
	struct node *ptr;
	int item,i=0,flag;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n empty list \n");
	}
	else
	{
		printf("enter thebitem which you want to search : \n");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
			if(ptr!=NULL)
			{
				printf("\n item found at location %d ",i+1);
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}
			i++;
			ptr=ptr->next;
		}
		if(flag==1)
		{
			printf("\n item not found");
		}
	}
}
