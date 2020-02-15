#include <stdio.h> // Standard C language header
#include <stdlib.h> // contains functions that will help to dynamically allocate memory, such as malloc
#include <limits.h> // contains the INT_MIN value.

// we will implement a "stack" data structure through the functions and applications
//that we have already seen in our previous linked list implementation.

// Defining the data structure
struct Node{
  int key; // The "key value" represents the informantion that we want to store in our "stack".
          // In this first implementation, we will work with integers,
          // easy to work with and better suited to our main objective, which is to understand the logic behind the algorithm.
  struct Node *link;  // This is a pointer to the next node of our structure.
};

//////////////////////////////////////////////////////////

//Declaring the functions
//////////////////////////////////////////////////////////

// We have four essential functions to manipulate our data structure:
void push(struct Node** head_node, int new_key); //Adds a new item to the stack.
int pop(struct Node** head_node); // Remove the item from the stack.
int top(struct Node** head_node);// Returns which is the top element of the stack, the last added.
int isEmpty(struct Node** head_node); //Assess whether the "stack" is empty or not.
// Auxiliary functions that we have used to implement a linked list:
struct Node* newNode(int new_key); // Creates a new element.
void cleanStack(struct Node** head_node); // free the memory allocated
void printStack(struct Node* head_node) ;// function to print the elemen of the stack, iterative approach

//////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  //testing the push function
  struct Node* head = NULL; // the first element
  printStack(head);
  head = newNode(4);
  printf("\n" );
  push(&head, 2);
  push(&head, 5);
  push(&head, 7);
  push(&head, 3);
  push(&head, 0);
  printStack(head);
  printf("\n" );
  //testing the pop function
  int p = 0;
  p = pop(&head);
  printf("Popped element = %d\n", p );
  p = pop(&head);
  printf("Popped element = %d\n", p );
  // testing the top function
  int t = 0;
  t = top(&head);
  printf("Top element = %d\n", t );
  cleanStack(&head);
  printStack(head);
  p = pop(&head);
  printf("Popped element = %d\n", p );
  t = top(&head);
  printf("Top element = %d\n", t );
return 0;
}

//FUNCTIONS
//////////////////////////////////////////////////////////

struct Node* newNode(int new_key){
    struct Node* temp = (struct Node * )malloc(sizeof(struct Node)); // Temporary variable that will help allocate memory for the new node.
    temp->key = new_key;
    temp->link = NULL; // At first, we set the pointer to NULL to avoid some errors due to the incorrect use of the address.
    return temp;
}

//////////////////////////////////////////////////////////

void push(struct Node** head_node, int new_key){
  /*
     We have two different approaches to adding a new element to the "stack". We could add the element at the end or at the beginning of the structure,
     but we have to analyze the consequences of that choice.
     If we choose to add at the end of the "stack", as a "linked list" does not allow random access to memory, we would have to go through all the elements,
     pointer to pointer, until we finally reach the end and then add the new element.
     This increases the time complexity of the operation to O(n), as we need to check all the elements before adding a new one.
     But, otherwise, if we choose to insert the new element always at the beginning of the "stack",
     the algorithm will always make the same number of movements to add the elements, therefore, we can guarantee a time complexity of O (1).
  */
  // First, we need to allocate the extra memory for the new node.
  struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
  temp->key = new_key; // Inserting the key value.
  temp->link = (*head_node);// Updating the pointer value for the next element in the stack.
  (*head_node) = temp;// Updating the head node.
}

//////////////////////////////////////////////////////////

void cleanStack(struct Node** head_node) {
  struct Node* aux; // auxiliar variable to help in the process
  aux = (*head_node); // store the reference of the head_node
  struct Node* next;// contains the reference to the next elements of the stack
  while (aux != NULL) {
    // when aux == NULL, we are in the last element of the stack
    next = aux->link; // save the address of the others elements of the stack
    free(aux); // releasing the memory in the adress aux
    aux = next; // walking through the stack
  }
  (*head_node) = NULL;// returning to an empty stack
}


//////////////////////////////////////////////////////////

void printStack(struct Node* head_node) {
  if (isEmpty(&head_node)) {
    printf("The Stack is empty\n" );
  }else{
    while (head_node != NULL) {
      printf("%d ",head_node->key ); // printing the element
      head_node = head_node->link; //walking in the list, at each loop the reference changes to the next element
    }
  }
}

//////////////////////////////////////////////////////////

int pop(struct Node** head_node){
  /*  To keep the time complexity as a constant and also to meet the "LIFO" constraint,
      we delete elements from the beginning of the stack.
  */
  // First we will check some special cases
  // In the case the stack is empty :
  if(isEmpty(head_node)){
    printf("The Stack is empty!! \n");
    return INT_MIN;
  }else{
    struct Node* temp = (*head_node); // temporary variable that saves the pointer to the stack .
    int aux = temp->key; // store the value that will be popped up.
    (*head_node) = temp->link;// Updating the head node .
    free(temp); // free memory
    return (aux);
  }
}

//////////////////////////////////////////////////////////

int top(struct Node** head_node){
  if(isEmpty(head_node)){
    printf("The Stack is empty!! \n");
    return INT_MIN;
  }else{
    int aux = (*head_node)->key;
    return aux;
  }
}

//////////////////////////////////////////////////////////

int isEmpty(struct Node** head_node){
    return !(*head_node);// check if the stack is empty or not .
}

//////////////////////////////////////////////////////////
