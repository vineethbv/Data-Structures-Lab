#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value)
{
    if(top<SIZE-1)
    {
        if (top < 0)
        {
            stack[0] = value;
            top = 0;
        }
        else
        {
            stack[top+1] = value;
            top++;
        }
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop()
{
    if(top >= 0)
    {
        int n = stack[top];
        top--;
        return n;
    }
    
    printf("Stack Underflow.\n");
    return -1;
}

int Top()
{
    return stack[top];
}

int isempty()
{
    return top<0;
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
}

int main(void)
{
    int opt, data, poppedData;

    while (opt != 4){
      printf("Enter option:\n");
      scanf("%d", &opt);

      if (opt == 1){
        printf("\nEnter data:\n");
        scanf("%d", &data);
        push(data);
      }
      else if (opt == 2){
        poppedData = pop();
        printf("\nPopped data: %d\n", poppedData);
      }
      else if (opt == 3){
        printf("\nStack contains:\n");
        display();
      }
      else if (opt == 4){
        break;
      }
      else
        printf("Invalid operational value.\n");
    }
}
