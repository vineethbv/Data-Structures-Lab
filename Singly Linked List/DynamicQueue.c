#include <stdio.h>
#include <malloc.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

node* head = NULL;

//Adding new node to end of List
void append(int data) {
  node* nPtr = (node*)malloc(sizeof(node));
  node* temp = head;
  
  nPtr->data = data;
  nPtr->next = NULL;
  
  //Check for empty list
  if (head == NULL) {
    head = nPtr;
    printf("First node created: %d\n", data);
    return;
  }
  
  //Traverse through the list
  while (temp->next!=NULL) {
    temp = temp->next;
  }

  temp->next = nPtr;
  printf("New node appended: %d\n", data);
}

//Deleting node at beginning of list
void delAtStart() {
  node* temp;
  
  //Check for empty list
  if (head == NULL) {
    printf("Empty list\n");
    return;
  }

  temp = head;
  printf("Removed = %d\n", head->data);
  free(temp);
  head = head->next;
}

//Deleting node at end of list
void delAtEnd() {
  node* temp = head;
  
  //Check for empty list
  if (head == NULL) {
    printf("Queue Underflow\n");
    return;
  }

  //Checks if only 1 node exists
  if (temp->next == NULL) {
    printf("Removed = %d\n", temp->data);
    free(temp);
    head = NULL;
    return;
  }
  
  //Traverse through the list
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  printf("Removed = %d\n", temp->next->data);
  free(temp->next);
  temp->next = NULL;
}

//Print all elements in the queue
void printList() {
  node* nPtr = head;
  int count = 0;

  printf("List conatins: \n");
  
  //Check for empty list
  if (head == NULL) {
    printf("Nothing!!\n");
    return;
  }
  
  //Traverse through the list
  while (nPtr != NULL) {
    printf("\t\t\t%d\n", nPtr->data);
    count++;
    nPtr = nPtr->next;
  }
  
  printf("Node count in current list: %d\n", count);
}

int main(void) {
  printList();
  append(28);
  append(12);
  append(2000);
  append(20);
  append(100);
  printList();
  delAtEnd();
  delAtStart();
  delAtEnd();
  printList();
}
