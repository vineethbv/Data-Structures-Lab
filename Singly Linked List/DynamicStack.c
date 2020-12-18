#include <stdio.h>
#include <malloc.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

node* head = NULL; //The first node in the list
node* temp = NULL; //The last node in the list
int count = 0; //Tracks the number of elements in the node

//Push element (add at beginning) of List
void push(int data) {
  node* nPtr = (node*)malloc(sizeof(node));

  nPtr->data = data;

  //Checks for empty list
  if (head == NULL) {
    nPtr->next = NULL;
    head = nPtr;
    printf("First node pushed: %d\n", data);
    count++;
    return;
  }

  //Pushes new node
  nPtr->next = head;
  head = nPtr;
  count++;
  printf("Pushed: %d\n", data);
}

void pop() {
  node* temp;

  //Checks for empty list
  if (head == NULL) {
    printf("Stack Underflow\n");
    return;
  }

  //Deletion of first element
  temp = head;
  printf("Popped = %d\n", head->data);
  head = head->next;
  free(temp);
  count--;
}

void printList() {
  node* nPtr = head;

  printf("Stack conatins: \n");

  //Checks for empty list
  if (head == NULL) {
    printf("\tNothing!!\n");
    return;
  }

  //Traverses the list while printing the elements
  while (nPtr != NULL) {
    printf("\t\t\t%d\n", nPtr->data);
    nPtr = nPtr->next;
  }
  
  //Gives node count in the list
  printf("Node count in current stack: %d\n", count);
}

int main(void) {
  push(28);
  push(12);
  push(100);
  push(20);
  printList();
  pop();
  printList();
}
