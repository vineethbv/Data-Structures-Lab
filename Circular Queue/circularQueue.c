#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int front=-1;
int rear=-1;

int queue[MAX];

void Enque(int);
void Deque();
void display();
int main(int argc, char **argv)
{
	int option;
    int item;
    do{
        printf("\nCircular Queue\n");
        printf("\n 1. Insert to Queue (EnQueue)");
        printf("\n 2. delete from the Queue (DeQueue)");
        printf("\n 3. Display the content ");
        printf("\n 4. Exit\n");
        printf("Enter the option :");
        scanf("%d",&option);
        switch(option)
        {
            case 1:  printf("Enter the element\n");
                     scanf("%d",&item);
                     Enque(item);
                     break;
            case 2: Deque();
                    
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
        }
    } while (option!=4);
	return 0;
}

void Enque(int ele)
{
    if(((front == 0 && rear == MAX - 1))|| (front == rear + 1) )
    {
       printf("Queue is full\n");return;
       
    }
    else
    {
      rear=(rear+1)%MAX;
      queue[rear]=ele;
      if(front ==-1)
          front=0;
      
                    
    }
}
void Deque()
{
    int item;
    if((front == -1)&&(rear == -1))
    {
        
        printf("Queue is empty");
    }
    else 
    {
        item=queue[front];
        printf("Removed element from the queue %d",item);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
       
    }
    
}

void display()
{
    int i;
    if((front==-1)&& (rear==-1))
    {
    
        printf("Queue is empty\n");return;
        
    }
    else
    {
        printf("\n Queue contents:\n");
        i=front;
        do
        {
           printf("%d",queue[i]); 
           if(i==rear)
               break;
           i=(i+1)%MAX;
        }while (i!=front);
        
    }
}
