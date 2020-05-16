##################################################################################################################
##################################################################################################################
#              A Linked List is a linear Data Structure, different from arrays, 
#              the elements within a list are not stored in contiguous spaces inside the computer memory, 
#              the elements are connected using pointers.  
#              The use of a linked list has some advantages over arrays, a list is a 
#              data structure with dynamic size and also allows inserting and deleting elements without difficulties.
##################################################################################################################
##################################################################################################################

class Node:
    
    def __init__(self, value, next=None):
        # The node class has two components: tha data to be stored and 
        # a pointer with the reference to the next node of the structure
        # By default the reference must be None when a new node is initialized
        self.value = value
        self.next_node = next
    
    def get_value(self):        # To access the value of a node
        return self.value
    
    def get_next_node(self):    # To access the reference to the next node
        return self.next_node
    
    def set_next_node(self, next):  # To update the link of the current node
        self.next_node = next

##################################################################################################################

class LinkedList:
    def __init__(self, value=None):
        self.head_node = Node(value)

    def get_head_node(self):
        return self.head_node

    def __repr__(self):
        string_list = ''
        temp = self.head_node
        if (temp is None):
            return "Empty List"
        while(temp is not None ):
            if (temp.get_value() is not None): # check if the list started with a value 
                string_list += str(temp.get_value())+" ->"
                temp = temp.get_next_node()
        string_list += "None"        
        return string_list  

    def insert_beginning(self, new_value):
        # To insert a new node at the neginning of the list we need four steps:
        # 1 -> Create a new node
        # 2 -> Store the new value within the new node
        # 3 -> Link the new node with the current head node
        # 4 -> Change the reference of the head node to the new node
        new_node = Node(new_value, self.head_node) # 1, 2, 3
        # the same as: new_node = Node(new_value)
        #              new_node.set_next_node(self.head_node)
        self.head_node = new_node   # 4

    def insert_atEnd(self, new_value):
        new_node = Node(new_value)
        current_node = self.get_head_node()
        while(current_node.get_next_node() is not None):
            current_node = current_node.get_next_node()
        current_node.set_next_node(new_node)


    def remove_node(self, value_to_remove):
        prev = None # previous node reference
        current_node = self.get_head_node() # save the reference of the list
        # if the value to be removed is within the head node:
        if ((current_node is not None)and(current_node.get_value() == value_to_remove) ): # Check whether the list is empty
            self.head_node = current_node.get_next_node()
            current_node = None
            return
        # Otherwise, the program must search for the value in the list
        while((current_node is not None)and(current_node.get_value() != value_to_remove)):
            prev = current_node
            current_node = current_node.get_next_node()
        # Check whether the value to be removed was found
        if (current_node is None):
            print("The list does not contain this value !!")
            return
        prev.set_next_node(current_node.get_next_node())
        current_node = None 

    def remove_atPosition(self, position):
        current_node = self.get_head_node() # get the reference of the list
        # Check whether the list is empty
        if (current_node is None):
            return
        # reove the first position
        if (position == 0):
            self.head_node = current_node.get_next_node()
            current_node = None
            return
        # Otherwise, we must find the element one position before the element to be removed
        flag = 0
        i = 0
        while(i < (position - 1) and (flag == 0)):
            current_node = current_node.get_next_node()
            if (current_node is None): # make sure the input position is larger than the list size
                flag = 1               # finish the loop   
            i = i + 1        
        # Same as :
        # for i in range(position - 1):
        #     current_node = current_node.get_next_node()
        #     if current_node is None :   # make sure the input position is larger than the list size
        #         break

        # if the position is larger than the list size end the function
        if ((flag == 1) or (current_node.get_next_node() is None)):
            print("This position does not exist in the list !")
            return
        # current_node.next must be removed
        next_node = current_node.get_next_node() # get the reference
        current_node.set_next_node(next_node.get_next_node())

    def deleteList(self):
        current_node = self.head_node
        if (current_node is None):
            return
        while (current_node is not None):
            prev = current_node.get_next_node()
            del current_node.value
            current_node = prev
        print("List Deleted")
        self.head_node = None

    def insert_atPosition(self, new_value, position):
        current_node =self.get_head_node()
        #Check if the list is empty
        if (current_node is None):
            print("Empty List")
            return
        # if the position is 0, we have already solved this problem
        if (position == 0):
            self.insert_beginning(new_value)
            return
        # Otherwise we must find the element at position - 1 
        flag = 0
        i = 0
        while(i < (position - 1) and (flag == 0)):
            current_node = current_node.get_next_node()
            if (current_node is None): # make sure the input position is larger than the list size
                flag = 1               # finish the loop   
            i = i + 1   
        # if the position is larger than the list size end the function
        if ((flag == 1) or (current_node.get_next_node() is None)):
            print("This position does not exist in the list !")
            return
        new_node = Node(new_value)
        new_node.set_next_node(current_node.get_next_node())
        current_node.set_next_node(new_node)
        
##################################################################################################################
###TEST
def main():
    my_list = LinkedList(1)
    for i in range(10):
        my_list.insert_beginning(i+1)

    print(my_list)
    my_list.remove_node(44)
    my_list.remove_node(2)
    my_list.remove_node(10)
    print(my_list)
    my_list.remove_atPosition(0)
    print(my_list)
    my_list.remove_atPosition(4)
    print(my_list)
    my_list.insert_atPosition(10,4)
    print(my_list)
    my_list.insert_atEnd(25)
    print(my_list)
    my_list.remove_atPosition(44)
    my_list.deleteList()
    print(my_list)

if __name__ == "__main__":
    main()
