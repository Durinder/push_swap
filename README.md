# push_swap

## Introduction

A 42 School project about sorting data on a stack with a limited set of instructions.

Project goal is to write 2 programs in C:
- **checker**, which takes integer arguments and reads instructions on the standard output. Once read, it executes them and displays OK if integers are sorted and KO otherwise.
- **push_swap**, which calculates and displays on the standard output the smallest set of instructions that sorts the integer arguments received.

## Rules

Only following functions are allowed to be used:
- write
- read
- malloc
- free
- exit

The game is composed of 2 stacks named a and b.
- a contains a random number of either positive or negative numbers without any duplicates.
- b is empty.

The goal is to sort in ascending order the numbers into stack a.

Following operations are allowed:
- sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

## Example
```Init a and b:
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
```
## Solution
I solved the problem by using radix sort. First I initialized the stacks and modified the input integers into consecutive integers so that smallest becomes INT_MIN and next smallest becomes INT_MIN + 1 and so on. This is done so that the least significant bits contain more information and less reading and instructions have to be used.

Then I treated the ints as binary and sorted all ints with 0 as the least significant bit into stack b. After looping through all the numbers I pushed everything back to stack a. Then I repeated the process while reading the second least significant bit and pushed all ints with 0 at that position to b and then again everything back to stack a.

After each loop I check whether the stack a is sorted and if it is I stop sorting and output the solution.

## Usage
```
./push_swap [integers separated by spaces]
./checker [integers separated by spaces] [optional flag -v if you want to see the stacks visually after each operation]
```
or
```
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l // for the amount of instructions
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG // for displaying whether the push_swap binary sorts the input
```
