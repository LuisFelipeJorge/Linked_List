  #include <stdio.h> // Standard C language header
#include <stdlib.h> // contains functions that will help to dynamically allocate memory, such as malloc
#include <limits.h> // contains the INT_MIN value.

// we will implement a "queue" data structure through the functions and applications
//that we have already seen in our previous linked list implementation.

// Defining the data structure
//Node structure
struct Node {
  int key;// stores the value of the queue, in our example, we will be working with a queue of integers
  struct Node* next;// pointer to the next element in the queue
};
//Queue structure
struct Queue{
  struct Node *front, *rear;  //unlike a "list" or "stack", to keep the time complexity constant in operations like inserting or removing elements,
                              //we need to have two variables to store the addresses of the first and last elements.
};

////////////////////////////////////////////////////////////

// Declaring the program functions
////////////////////////////////////////////////////////////
//// Auxiliary functions that we have used to implement a linked list:
struct Node* createNode(int new_key); // create a new element of the structure.
struct Queue* createQueue();
void cleanQueue(struct Queue* q); // funtion to free the memory allocated for the structure.
void printQueue(struct Queue* q); // function to print the queue.
//// Basic functions for implementing a queue
void enQueue(struct Queue* q, int new_key); // function to add a new element to the queue.
void deQueue(struct Queue* q); // function to remove an element from the queue .
int front(struct Queue* q); // function to get the front element of the queue.
int isEmpty(struct Queue* q);//Assess whether the "queue" is empty or not.

////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  struct Queue* q = createQueue();
  // testing printQueue,cleanQueue, enQueue and deQueue.
  printQueue(q); // must show that the queue is empty
  enQueue(q,2); // front -> 2 -> NULL <- rear
  printQueue(q);
  enQueue(q,1);// front -> 2 -> 1 -> NULL <- rear
  printQueue(q);
  enQueue(q,5);// front -> 2 -> 1 -> 5 -> NULL <- rear
  printQueue(q);
  enQueue(q,7);// front -> 2 -> 1 -> 5 -> 7 -> NULL <- rear
  printQueue(q);
  int check = isEmpty(q);
  printf("Check : %d \n", check );
  int f = front(q);
  printf("Front : %d\n",f );
  deQueue(q);// front -> 2 -> 1 -> 5 -> NULL <- rear
  printQueue(q);
  cleanQueue(q);
  printQueue(q);
  check = isEmpty(q);
  printf("Check : %d \n", check );
  f = front(q);
  free(q);
  return 0;
}

////////////////////////////////////////////////////////////

////FUNCTIONS
////////////////////////////////////////////////////////////

struct Node* createNode(int new_key){
  struct Node* temp = (struct Node * )malloc(sizeof(struct Node)); // Temporary variable that will help allocate memory for the new node.
  temp->key = new_key;
  temp->next = NULL; // At first, we set the pointer to NULL to avoid some errors due to the incorrect use of the address.
  return temp;
}

////////////////////////////////////////////////////////////

struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); // allocate the memory
    q->front = q->rear = NULL; // empty queue
    return q; // return an empty queue
}

////////////////////////////////////////////////////////////


void cleanQueue(struct Queue* q) {
  struct Node* aux; // auxiliar variable to help in the process
  aux = q->front; // store the reference of the front_node
  struct Node* next;// contains the reference to the next elements of the queue
  while (aux != NULL) {
    // when aux == NULL, we are in the last element of the stack
    next = aux->next; // save the address of the others elements of the queue
    free(aux); // releasing the memory in the adress aux
    aux = next; // walking through the queue
  }
  q->front = q->rear = NULL;// returning to an empty queue
}

////////////////////////////////////////////////////////////

void printQueue(struct Queue* q) {
  if (q->front == NULL ) {
    printf("The Queue is empty\n" );
  }else{
    struct Node* temp = q->front;
    while (temp != NULL) {
      printf("%d ",temp->key ); // printing the element
      temp = temp->next; //walking in the queue, at each loop the reference changes to the next element
    }
    printf("\n");
  }
}

////////////////////////////////////////////////////////////

void enQueue(struct Queue* q, int new_key){
  /*
  Example: 7 -> 5 -> 9 -> NULL; 7 is the front element and 9 is the rear element.
  enQueue must add an element after 9
  enQueue 3 :
  7 -> 5 -> -> 9 -> 3 -> NULL
  */
  struct Node* temp = createNode(new_key); // temporary variable to help allocate the extra memory for the new node .
  // In the case the queue is empty, front and rear must point to NULL
  if (q->rear == NULL){
    q->front = q->rear = temp;
    return;
  }else{
    // In the case the queue is not empty we must update the front address
    q->rear->next = temp; // adding a new element at the end of the queue
    q->rear = temp; // change the rear
  }
}

////////////////////////////////////////////////////////////

void deQueue(struct Queue* q){
  // In the case the queue is empty, front and rear must point to the same node
  if (q->front == NULL) {
    printf("The Queue is empty\n");
    return;
  }else{
    struct Node* temp = q->front;// temporary variable to save the address of the queue
    //In the case that the queue has only one element
    if (q->front ==  q->rear) {
      // rear must be updated to NULL
      q->front = q->rear = NULL;
    }else{
      q->front = temp->next;// Updating the address of the front node
        free(temp);// free memory
    }
  }
}

////////////////////////////////////////////////////////////

int front(struct Queue* q){
  // In the case that the queue is empty
  if (q->front == NULL) {
    printf("The Queue is empty\n");
    return INT_MIN;
  }else{
    return q->front->key; //auxiliary variable to store the key value at the front of the queue.
  }
}

////////////////////////////////////////////////////////////

int isEmpty(struct Queue* q){
    return !(q->front && q->rear);
}

////////////////////////////////////////////////////////////
