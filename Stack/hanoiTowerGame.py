###########################################################################################################
#### With an understanding of the stack data structure, we will implement the Hanoi Tower game
#### The rules of the game are available at:
#### https://en.wikipedia.org/wiki/Tower_of_Hanoi
###########################################################################################################

from hanoiStack import Stack

###########################################################################################################
###########################################################################################################

print("\nLet's play Towers of Hanoi!!")

#Create the Stacks
###########################################################################################################
###########################################################################################################
stacks = []
left_stack = Stack("Left")
middle_stack = Stack("Middle")
right_stack = Stack("Right")
stacks += [left_stack, middle_stack, right_stack]

#Get User Input
###########################################################################################################
###########################################################################################################
def get_input():

  choices = [stack.get_name()[0] for stack in stacks]
  # ['L', 'M', 'R']
  while(True):
    for i in range(len(stacks)):
      name = stacks[i].get_name()
      letter = choices[i]
      print("\nEnter {letter} for {name}.".format(letter=letter,name=name))
    user_input = input("")
    if user_input in choices :
      for i in range(len(stacks)):
        if user_input == choices[i] :
          return stacks[i]

#Start  the Game
###########################################################################################################
def main():

  #Set up the Game
  ###########################################################################################################

  num_disks = int(input("\nHow many disks do you want to play with?\n"))
  while(num_disks < 3 ):
    num_disks = int(input("\nThis game is only fun when there is at least three disks!! \nInput a new value greater than or equal to 3: \n"))

  for i in range(num_disks, 0, -1): # adds the disks to the left stack at the beginning of the game
    left_stack.push(i)

  num_optimal_moves = (2**num_disks)-1  # calculate the minimum number of moves to win the game
  print("\nThe fastest you can solve this game is in {optimal} moves".format(optimal=num_optimal_moves))       

  num_user_moves = 0    # Count the number of moves used by the player

  while(right_stack.get_size() != num_disks): # while the stack on the right is not full, continue the game.
    print("\n\n\n...Current Stacks...")       # print the current status of the stacks
    for stack in stacks :
      stack.print_items()

    while True :
      # ask for a movement
      print("\nWhich stack do you want to move from?\n")
      from_stack = get_input()
      print("\nWhich stack do you want to move to?\n")
      to_stack = get_input()

      # check if this is a valid movement

      if from_stack.is_empty():
        print("\n\nInvalid Move. Try Again")
      elif to_stack.is_empty() or from_stack.peek() < to_stack.peek():
        disk = from_stack.pop()
        to_stack.push(disk)
        num_user_moves += 1
        break
      else:
        print("\n\nInvalid Move. Try Again")

  # End of the Game :
  print("\n\nYou completed the game in {0} moves, and the optimal number of moves is {1}".format(num_user_moves, num_optimal_moves))

if __name__ == "__main__":
    main()