############################################################################################################
############################################################################################################
from node import Node

############################################################################################################

class Queue:

  def __init__(self, max_size=None):

    self.head = None
    self.tail = None
    self.max_size = max_size
    self.size = 0    

  def __repr__ (self):
      queue_string = 'Head '
      temp = self.head
      if self.is_empty() :
          return "Empty Queue !!"
      while(temp is not None):
          if(temp.get_value() is not None):  # check is the queue started with a value
            queue_string += " ->"+str(temp.get_value())
            temp = temp.get_next_node()
      queue_string += "<- Tail" 
      return queue_string


  def enqueue(self, value):

    if self.has_space():
      item_to_add = Node(value)
      print("Adding " + str(item_to_add.get_value()) + " to the queue!")

      if self.is_empty():           # Check if the queue is empty
        self.head = item_to_add     # the new item is both head and tail of the queue
        self.tail = item_to_add
      else:                         # if there are already elements in the queue, only the tail reference must be updated
        self.tail.set_next_node(item_to_add)
        self.tail = item_to_add
      self.size += 1                # update the size of the structure 
    else:
      print("Overflow !!")
      
  def dequeue(self):
    if not self.is_empty():

      item_to_remove = self.head
      print("Removing "+str(item_to_remove.get_value())+" from the queue!")
      if self.size == 1 :           # if the row has only 1 element, the tail and head should become None
        self.head = self.tail = None
      else:                         # average case
        self.head = self.head.get_next_node()
      self.size += -1

      return item_to_remove.get_value()

    print("Underflow !")

  def peek(self):

    if self.is_empty():
      print("Nothing to see here!")

    else:
      return self.head.get_value()

  

  def get_size(self):
    return self.size

  def has_space(self):
    if self.max_size == None:       # if there is no limit, always return True 
      return True
    else:                           # Othewise, check if the size is lower than the limit
      return self.max_size > self.get_size()

  def is_empty(self):
    return self.size == 0

############################################################################################################
### Test

def main():    
  my_queue = Queue(10)
  for i in range(12):
      my_queue.enqueue(i)

  print(my_queue)
  print(my_queue.peek())


  for i in range(7):
      my_queue.dequeue()
  print(my_queue.peek())

  for i in range(7):
      my_queue.dequeue()

  print(my_queue.dequeue())
  print(my_queue)

############################################################################################################

if __name__ == "__main__":
    main()


