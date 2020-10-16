#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

int main(void) {
  int opt = 0;

  while (opt != 4){
    printf("Operations available:\n1. Enqueue\n2. Dequeue\n3. Display\n>>>");
    scanf("%d", &opt);

    switch (opt){
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        break;
      default:
        printf("Invalid arguments.\n");
    }
  }
}

void enqueue() {
  int ele;

  if (rear == front + (SIZE - 1))
    printf("Queue overflow.\n");
  else {
    
    printf("Enter element to be inserted.\n");
    scanf("%d", &ele);
    
    if (rear == -1){
      front = 0;
    }

    rear++;
    queue[rear] = ele;

    printf("Added : %d\n", ele);
  }
}

void dequeue() {
  if ((front > rear) || (rear == -1))
    printf("Queue underflow.\n");
  else {
    printf("Removed : %d\n", queue[front]);
    front++;
  }
}

void display() {
  if (front < 0)
    printf("Empty queue\n");
  else {
    printf("Queue contains: ");

    for (int i = front; i <= rear; i++)
      printf("%d\t", queue[i]);
    
    printf("\n");
  }
}
