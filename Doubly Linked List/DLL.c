#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
void insert_bef()
{
	int listele;
	struct node *new_node,*temp;
	 new_node=(struct node*)malloc(sizeof(struct node));
	 printf("Enter the item\n");
	 scanf("%d",&new_node->data);
	 new_node->next=NULL;
	 new_node->prev=NULL;
	 
	 if(head==NULL)
	 {
		 printf("List is currently empty! Inserting at the very first node instead\n");
		 head=new_node;
	}
	else
	{
		printf("Enter the element in the list\n");
		scanf("%d",&listele);
		temp=head;
		if(head->data== listele)
		{
			new_node->next=head;
			head->prev=new_node;
			head=new_node;
		}
		else
		{
			while(temp->next->data!=listele)
			{
				temp=temp->next;
				if(temp->next==NULL)
				{
					printf("Element is  not in the list");
					return;
				}
			}
			new_node->next= temp->next;
			new_node->prev= temp;
			temp->next->prev=new_node;
			temp->next=new_node;
			
		}
	}
}
void del()
{
	struct node *temp;
	int ele;
    if(head==NULL)
    {
        printf("Empty List \n");
        return;
    }
	printf("Enter the element to be deleted\n");
	scanf("%d",&ele);
	temp=head;
	while(temp->data!=ele)
	{
		temp=temp->next;
		if(temp==NULL)
		{
		 printf("Element is not in the list\n");
		 return;
		}
	 }
	 if(temp==head)
	 {
		 head=head->next;
	 }
	 else if(temp->next==NULL)
	 {
			temp=temp->prev;
			temp->next=NULL;
	 }

	 else
	 {
		 temp->prev->next=temp->next;
		 temp->next->prev=temp->prev;
	 }
}
void display()
{
	 struct node *temp;
	 temp=head;
	 while(temp!=NULL)
	 {
		 printf("%d  ",temp->data);
		 temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int choice;
	
	 do
	 {
			printf(" 1. Insert before a node \n");
			printf(" 2. Delete a specific node \n");
			printf(" 3. Display\n");
			printf(" 4. Exit\n");
			printf("Enter your choice\n");
			scanf("%d",&choice);
			switch(choice)
			{
				 case 1: insert_bef();
				 break;
				 
				 case 2: del(); 
				 break;
				 
				 case 3: display(); 
				 break;
				 
				 case 4: 
				 break;
				 
				 default:
				 printf("Wrong choice!\n");
				 break;
			}
	 }while(choice!=4);
	 return 0;
	 
}
