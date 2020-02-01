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

struct Node* createElement(int key); // function to allocate space and point to NULL
void insertAtBegining(struct Node** head_node, int new_key); // function to put a new element at the begining of the list
void insertAtEnd(struct Node** head_node, int new_key);// function to put a new element at the ending of the list
void insertAfter(struct Node* previous_node, int new_key);// function to put a new element after a given previous node
void printList(struct Node* head_node); //function to print the list and check the changes that occur in the structure
void cleanList(struct Node** head_node); // function to delete all the elements of the list
void deleteKey(struct Node** head_node,int key); // function to delete the first key occurrence in the list
void deleteAtPosition(struct Node** head_node, int position); // function to delete a node at a given position

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
  deleteKey(&head, 6); // testing in the head , list: 5-> 7 -> 9 -> 4 -> 2 -> 1 -> NULL
  printList(head);
  printf("\n" );
  deleteKey(&head, 1);// deleting the last element, list: 5-> 7 -> 9 -> 4 -> 2 -> NULL
  printList(head);
  printf("\n" );
  deleteKey(&head, 10); // testing an element that does not belong to the list
  deleteAtPosition(&head, 2);// list : 5-> 7 -> 4 -> 2 -> NULL
  printList(head);
  printf("\n" );
  deleteAtPosition(&head, 0);// delete the head, list : 7 -> 4 -> 2 -> NULL
  printList(head);
  printf("\n" );
  deleteAtPosition(&head, 6 ); // position that is greater than the number of elements
  cleanList(&head);
  printList(head);
  printf("\n" );

  return 0;
}

//////////////////////////////////////////////////

struct Node* createElement(int key){
  struct Node* element = (struct Node*)malloc(sizeof(struct Node)); // allocating the space in the memory
  element->key = key;
  element->next = NULL;
  return element;
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
  temp = (*head_node);// receive as reverence the head address
  while (temp->next != NULL) {
      temp =temp->next;// walking in the list, at each loop the reference changes to the next element
    }
  //At this moment we are in the last elem of the list
  temp->next = createElement(new_key);
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

void cleanList(struct Node** head_node) {
  struct Node* aux; // auxiliar variable to help in the process
  aux = (*head_node); // store the reference of the head_node
  struct Node* next;// contains the reference to the next elements of the list
  while (aux != NULL) {
    // when aux == NULL, we are in the last element of the lista
    next = aux->next; // save the address of the others elements of the list
    free(aux); // releasing the memory in the adress aux
    aux = next; // walking through the list
  }
  (*head_node) = NULL;// returning to an empty list
}

//////////////////////////////////////////////////

void deleteKey(struct Node** head_node,int key){
    struct Node* temp = (*head_node); // temporary variable to help in the process
    // temp receive the address of the head_node as reference
    struct Node* previous; // will receive as a reference the address of the node prior to the key
    // in this case, the head has the key to be deleted
    if (temp != NULL && temp->key == key) {
      *head_node = temp->next; // changes the head reference of the list to the next node
      free(temp);
      return;// get out of the function and avoid the next steps
    }
    // if the key isn't in the head we need to look for the others elements in the list
    while (temp != NULL && temp->key != key) {
      // We need to store the node reference prior to the key to maintain the list structure after deleting the key
      previous = temp;
      temp = temp->next; // walking through the list
    }
    // after the 'while' loop we have two possibilities
    if (temp == NULL) {
      printf("The key does not belong to the list !!\n" );
      return;
    }else{
      // we  find the key in the list
      previous->next = temp->next; // retrieving the reference from the rest of the list
      free(temp); // releasing the memory
    }
}

//////////////////////////////////////////////////

void deleteAtPosition(struct Node** head_node, int position){
  // First we need to check some special cases
  // the list is empty
  if ((*head_node) == NULL) {
    printf("The list is empty\n");
    return;
  }else{
    struct Node* temp = (*head_node); // save the reference of the list
    // in the case we need to remove the head
    if (position == 0) {
      (*head_node) = temp->next; // changes the head of the list
      free(temp);
      return;
    }
    // if we want to delete the element from another position
    // we also need to find out what is the position of the previous node of the node to be deleted
    int i;
    for(i = 0; temp != NULL && i < position - 1; i++){
      // i < position - 1 ==> makes the loop stop when temp is the previous node at (n -1)th position, and temp->next is the node to be deleted (n)th position
      temp = temp->next;
    }
    // if we receive as input a position that is greater than the number of elements in the list
    if(temp == NULL || temp->next == NULL){
      printf("this position does not exist in the list\n");
      return;
    }else{
      // temp->next must be deleted
      // we need also to mantain the reference of the rest of the list
        struct Node* next = temp->next->next; // the variable next contains the reference for the rest of the list,(n+1)th position
        free(temp->next);// free the memory
        temp->next = next; // recover the rest of the list
    }
  }
}

//////////////////////////////////////////////////
