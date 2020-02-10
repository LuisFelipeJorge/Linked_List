#include <stdio.h> // Standard C language header
#include <stdlib.h> // contains functions that will help to dynamically allocate memory, such as malloc

// we will implement a "stack' data structure through the functions and applications
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

//////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {

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



//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
