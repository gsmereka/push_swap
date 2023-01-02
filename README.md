# 42_push_swap

The Push Swap project utilizes some C language algorithms that organize random integer numbers in ascending order. It uses two stacks called "a" and "b" and a set of instructions to manipulate these stacks.

## About the project

The push_swap program calculates and displays the smallest possible set of instructions, using the available operations, to sort the numbers in stack "a" in ascending order. It handles positive and negative numbers and does not accept repeated numbers or arguments that do not represent integers.

## How it works ?

- Stack "a" starts with a random amount of numbers, while stack "b" starts empty.
- The goal is to sort the numbers in stack "a" in ascending order.
- The available operations are:
  - **sa** (**swap a**): Swap the top 2 elements in stack **a**. Do nothing if there is only one or no element.
  - **sb** (**swap b**): Swap the top 2 elements in stack **b**. Do nothing if there is only one or no element.
  - **ss** : **sa** and **sb** at the same time.
  - **pa** (**push a**): Take the first element at the top of **b** and put it on top of **a**. Do nothing if **b** is empty.
  - **pb** **(push b**): Take the first element at the top of **a** and put it on top of **b.** Do nothing if **a** is empty.
  - **ra** (**rotate a**): Raise all elements in stack **a** by 1. The first element becomes the last.
  - **rb** (**rotate b**): Shift all elements in stack **b** up by 1. The first element becomes the last.
  - **rr : ra** and **rb** at the same time.
  - **rra** (**reverse rotate a**): Shift all elements in stack **a** down by 1. The last element becomes the first.
  - **rb (reverse rotate b)**: Shift all elements in stack **b** down by 1. The last element becomes the first.
  - **rrr : rra** and **rrb** at the same time.

## Examples:

Init a and b:  
2  
1  
3  
6  
5  
8  
_ _  
a b  

Exec sa:  
1  
2  
3  
6  
5  
8  
_ _  
a b  

Exec pb pb pb:  
6 3  
5 2  
8 1  
_ _  
a b  

Exec ra rb (equiv. to rr):  
5 2  
8 1  
6 3  
_ _  
a b  

Exec rra rrb (equiv. to rrr):  
6 3  
5 2  
8 1  
_ _  
a b  

Exec sa:  
5 3  
6 2  
8 1  
_ _  
a b  

Exec pa pa pa:  
1  
2  
3  
5  
6  
8  
_ _  
a b  

In this example, the program's output would be:  

sa  
pb  
pb  
pb  
rr  
rrr  
sa  
pa    
pa  
pa  