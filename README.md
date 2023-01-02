# 42_push_swap

The Push Swap project is a C language algorithm that organizes random integer numbers in ascending order. It uses two stacks called "a" and "b" and a set of instructions to manipulate these stacks.

## Goal

The push_swap program calculates and displays the smallest possible set of instructions, using the available operations, to sort the numbers in stack "a" in ascending order. It handles positive and negative numbers and ensures that numbers are not repeated.

## Rules

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


