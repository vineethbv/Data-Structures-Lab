#include <stdio.h>
#include <malloc.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

node* head = NULL; //The first node in the list
node* curr = NULL; //The last node in the list
int count = 0; //Tracks the number of elements in the node

//Push element (add at beginning) of List
void push(int data) {
  node* nPtr = (node*)malloc(sizeof(node));

  nPtr->data = data;

  //Checks for empty list
  if (head == NULL) {
    nPtr->next = NULL;
    head = nPtr;
    printf("First node created: %d\n", data);
    count++;
    return;
  }

  //Pushes new node
  nPtr->next = head;
  head = nPtr;
  count++;
  printf("New node added at beginning: %d\n", data);
}

//Adding new node at nth position (Offset from first node) in List
void addAtPos(int data, int offset) {
  node* nPtr = (node*)malloc(sizeof(node));
  curr = head;
  int pos = offset;
  
  nPtr->data = data;

  //Validates the offset
  if (offset > (count + 1) || offset < 0) {
    printf("Out of limits.\n");
    return;
  }
  
  //Checks for empty list
  if (head == NULL) {
    nPtr->next = NULL;
    head = nPtr;
    printf("First node created: %d\n", data);
    count++;
    return;
  }

  //Checks if offset is at beginning of list
  if (offset == 0){
    push(data);
    return;
  }

  //Traverses the list until offset is 0
  while (--offset) {
    curr = curr->next;
    
    if (offset == 0)
      break;
  }

  //Adds new node to the list
  nPtr->next = curr->next;
  curr->next = nPtr;
  printf("New node added at %d: %d\n", pos, data);
  count++;
}

//Adding new node to end of List
void append(int data) {
  node* nPtr = (node*)malloc(sizeof(node));
  curr = head;
  
  nPtr->data = data;
  
  //Checks for empty list
  if (head == NULL) {
    nPtr->next = NULL;
    head = nPtr;    
    printf("First node created: %d\n", data);
    count++;
    return;
  }
  
  //Traverses the list till curr is NULL
  while (curr->next!=NULL) {
    curr = curr->next;
  }

  //Appends the new node to the list
  curr->next = nPtr;
  printf("New node appended: %d\n", data);
  count++;
}

//Print all elements in the list
void printList() {
  node* nPtr = head;

  printf("List conatins: \n");

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
  
  printf("Node count in current list: %d\n", count);
}

int main(void) {
  printList();
  append(28);
  append(12);
  append(10);
  append(20);
  printList();

  push(1);
  printList();

  addAtPos(100, 3);
  addAtPos(2000, 3);
  addAtPos(911, 7);
  printList();
}
