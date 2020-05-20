import random
from node import Node

#######################################################################################################
#######################################################################################################

class Stack:


  def __init__(self, limit=1000): # only as an exercise, a limit will be imposed on the number of elements
    self.top = None    # when a stack is initialized, the reference to the first item points to None
    self.size = 0           # Its size starts with zero
    self.limit = limit      
  
  def __repr__ (self):
      stack_string = 'Top ->'
      temp = self.top
      if self.is_empty() :
          return "Empty Stack !!"
      while(temp is not None):
          if(temp.get_value() is not None):  # check is the stack started with a value
            stack_string += str(temp.get_value())+" ->"
            temp = temp.get_next_node()
      stack_string += "None" 
      return stack_string

  def has_space(self):      # helper function to check whether there is available space to add new items
    return self.limit > self.size

  def is_empty(self):       # helper function to check if the stack is empty or not 
    return self.size == 0

  def push(self, value):    # method to add new elements at the top of the stack
    if self.has_space() :
      temp = Node(value)
      temp.set_next_node(self.top)
      self.top = temp
      self.size += 1        # Increment stack size by 1     
      print("New element added at the top of the Stack")
    else:
      print("All out of space !!")    

  def pop(self):            # method to remove elements from the stack
    if self.size > 0:
      item_to_remove = self.top
      self.top = item_to_remove.get_next_node()
      self.size -= 1
      print("Element Removed from the top of the Stack")
      return item_to_remove.get_value()
    else:
      print("This stack is empty !!")
  
  def peek(self):
    if self.size > 0:
	    return self.top.get_value()
    else:
      print("This stack is empty !!")
      
  
#######################################################################################################
#######################################################################################################
## TEST 
my_stack = Stack(10)

def main():
  for i in range(12):
      temp = random.randint(1, 100)
      my_stack.push(temp)
  print(my_stack)
  print(my_stack.peek())
  for i in range(6):
      my_stack.pop()
  print(my_stack)
  for i in range(7):
      my_stack.pop()
  print(my_stack)


if __name__ == "__main__":
    main()
