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