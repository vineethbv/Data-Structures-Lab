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
  temp = head;
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
    temp = temp->next;
    
    if (offset == 0)
      break;
  }

  //Adds new node to the list
  nPtr->next = temp->next;
  temp->next = nPtr;
  printf("New node added at %d: %d\n", pos, data);
  count++;
}

//Adding new node to end of List
void append(int data) {
  node* nPtr = (node*)malloc(sizeof(node));
  temp = head;
  
  nPtr->data = data;
  
  //Checks for empty list
  if (head == NULL) {
    nPtr->next = NULL;
    head = nPtr;    
    printf("First node created: %d\n", data);
    count++;
    return;
  }
  
  //Traverses the list till temp is NULL
  while (temp->next!=NULL) {
    temp = temp->next;
  }

  //Appends the new node to the list
  temp->next = nPtr;
  printf("New node appended: %d\n", data);
  count++;
}

//Deleting node at beginning of list
void delAtStart() {
  node* temp;

  //Checks for empty list
  if (head == NULL) {
    printf("Empty list\n");
    return;
  }

  //Deletion of first element
  temp = head;
  printf("Removed = %d\n", head->data);
  head = head->next;
  free(temp);
  count--;
}

void delAtEnd();

//Deleting node at specified location
void delAtPos(int offset) {
  node *temp = head, *del = NULL;

  //Validates the given offset within the list
  if ((offset > count) || (offset < 1)){
    printf("Out of bounds\n");
    return;
  }

  //Checks for empty list
  if (head == NULL) {
    printf("Empty list\n");
    return;
  }

  //Checks if specified offset is the first element in the list
  if (offset == 0) {
    delAtStart();
    return;
  }

  //Checks if specified offset is the last element in the list
  if (offset == count) {
    delAtEnd();
    return;
  }

  //Traverse through the entire list
  while (--offset > 1) {
    temp = temp->next;
  }

  del = temp->next;
  temp->next = temp->next->next;
  printf("Removed = %d\n", del->data);
  free(del);
  count--;
}

//Deleting node at end of list
void delAtEnd() {
  node* temp = head;

  //Checks for empty list
  if (head == NULL) {
    printf("Empty list\n");
    return;
  }

  //Checks if only 1 node remains
  if (temp->next == NULL) {
    printf("Removed = %d\n", temp->data);
    free(temp);
    head = NULL;
    count--;
    return;
  }

  //Traverses the list
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  //Deletion of last element
  printf("Removed = %d\n", temp->next->data);
  free(temp->next);
  temp->next = NULL;
  count--;
}

void swap(node *a, node *b);

//Sorts the elements in the list
void Sort(struct Node *start) 
{ 
  int swapped, i; 
  node *ptr1; 
  node *lptr = NULL; 
  
  //Checking for empty list
  if (start == NULL) 
    return; 
  
  do
  { 
    swapped = 0; 
    ptr1 = start; 
  
    while (ptr1->next != lptr) {
      if (ptr1->data > ptr1->next->data) {  
        swap(ptr1, ptr1->next); 
        swapped = 1; 
      } 
      
      ptr1 = ptr1->next; 
    } 
    
    lptr = ptr1; 
  } 
  while (swapped); 
}

//Swap data of two nodes a and b
void swap(struct Node *a, struct Node *b) 
{ 
  int temp = a->data; 
  a->data = b->data; 
  b->data = temp; 
}

//Reverses the order of elements in the list
static void reverse(struct Node** head_ref)
{
  node* prev = NULL;
  node* current = *head_ref;
  node* next = NULL;
  while (current != NULL) {
    // Store next
    next = current->next;
 
    // Reverse current node's pointer
    current->next = prev;
 
    // Move pointers one position ahead.
    prev = current;
    current = next;
  }
  
  *head_ref = prev;
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
  
  //Gives node count in the list
  printf("Node count in current list: %d\n", count);
}

int main(void) {
  printList();
  append(28);
  append(12);
  append(10);
  append(20);
  push(2000);
  push(1);
  printf("Initial list with all elements: \n");
  printList();
  printf("Sorted list with all elements: \n");
  Sort(head);
  printList();
  printf("Reversed order of elements in list: \n");
  reverse(&head);
  printList();
  delAtPos(5);
  printList();
  addAtPos(100, 5);
  printList();
  delAtStart();
  printList();
  delAtPos(5);
  printf("List after deleting certain elements: \n");
  printList();
}
