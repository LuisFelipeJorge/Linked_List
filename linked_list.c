#include <stdio.h> // Standard C language header
#include <stdlib.h> // contains functions that will help to dynamically allocate memory, such as malloc

//Defining the list structure
struct Node{
  int key; // stores the list value, in our example, we will be working with a list of integers
  struct Node* next; // pointer to the next element in the list
};

//////////////////////////////////////////////////

//Declaring the functions of the program
//////////////////////////////////////////////////

void insertAtBegining(struct Node** head_node, int new_key); // function to put a new element at the begining of the list
void insertAtEnd(struct Node** head_node, int new_key);// function to put a new element at the ending of the list
void insertAfter(struct Node* previous_node, int new_key);// function to put a new element after a given previous node
void printList(struct Node* head_node); //function to print the list and check the changes that occur in the structure
struct Node* createElement(int key); // function to allocate space and point to NULL

//////////////////////////////////////////////////

int main(int argc, char const *argv[]) {

  struct Node* head = NULL; // creating an empty list
  printList(head);// empty list
  // inserting elements in the list
  head = createElement(4);// list: 4 -> NULL
  printList(head);
  printf("\n" );
  insertAtBegining(&head, 7);// list: 7-> 4 -> NULL
  printList(head);
  printf("\n" );
  insertAtBegining(&head, 5);// list: 5-> 7 -> 4 -> NULL
  printList(head);
  printf("\n" );
  insertAtBegining(&head, 6);// list: 6-> 5-> 7 -> 4 -> NULL
  printList(head);
  printf("\n" );
  insertAtEnd(&head,2);// list: 6-> 5-> 7 -> 4 -> 2 -> NULL
  printList(head);
  printf("\n" );
  insertAtEnd(&head,1);//  list: 6-> 5-> 7 -> 4 -> 2 -> 1 -> NULL
  printList(head);
  printf("\n" );
  insertAfter(head->next->next,9);// list: 6-> 5-> 7 -> 9 -> 4 -> 2 -> 1 -> NULL
  printList(head);
  printf("\n" );

  return 0;
}

//////////////////////////////////////////////////

void insertAtBegining(struct Node** head_node, int new_key) {
  // First, we need to dynamically allocate memory for the new element
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // temporary variable to help insert the new node
  temp->key = new_key; // putting the data inside the key
  temp->next = (*head_node); // the new node will point to the reference of the head, this mean to the rest of the list
  (*head_node) = temp;// the new node becomes the head of the list
}

//////////////////////////////////////////////////

void insertAtEnd(struct Node** head_node, int new_key) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));// temporary variable to help insert the new node
  temp = (*head_node);// receive as reverence the head adress
  while (temp->next != NULL) {
      temp =temp->next;// walking in the list, at each loop the reference changes to the next element
    }
  //At this moment we are in the last elem of the list
  temp->next = createElement(new_key);
}
//////////////////////////////////////////////////

void printList(struct Node* head_node) {
  if (head_node == NULL) {
    printf("The list is empty\n" );
  }else{
    while (head_node != NULL) {
      printf("%d ",head_node->key ); // printing the element
      head_node = head_node->next; //walking in the list, at each loop the reference changes to the next element
    }
  }
}

//////////////////////////////////////////////////

void insertAfter(struct Node* previous_node, int new_key){
    // First we need to check if the previous nde is NULL
    if (previous_node == NULL) {
      printf("The function cannot work on a NULL node; it is recommended to use the insertAtEnd function \n");
    }else{
      struct Node* temp = (struct Node*)malloc(sizeof(struct Node));// the idea is that the new node should be placed in the position of the previous_node
      // therefore we need to make the previous_node point to the new node , and make this point to the rest of the list.
      temp->key = new_key;
      temp->next = previous_node->next;
      previous_node->next = temp;
    }
}

//////////////////////////////////////////////////

struct Node* createElement(int key){
  struct Node* element = (struct Node*)malloc(sizeof(struct Node)); // allocating the space in the memory
  element->key = key;
  element->next = NULL;
  return element;
}

//////////////////////////////////////////////////
