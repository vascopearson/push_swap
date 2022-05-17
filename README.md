# push_swap

## 🗣️ About this project

> This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.<br/>
> This is Version 6 of this project<br/>

The push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. 
You have at your disposal a set of int values, 2 stacks (stack **a** and stack **b**) and a set of instructions to manipulate both stacks.

This project contains 2 programs:

The first, named checker, takes integer arguments and reads instructions on the standard output. 
Once read, the checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.
The second one, called push_swap, calculates and displays on the standard output the instructions that sort the integer arguments received.

For detailed information, refer to the [**subject of this project**](https://github.com/vascopearson/Libft/blob/master/libft_subject.pdf).

### Push swap instructions

- **sa**: *swap a* - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **sb**: *swap b* - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **ss**: sa and sb at the same time.
- **pa**: *push a* - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **pb**: *push b* - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **ra**: *rotate a* - shift up all elements of stack a by 1. The first element becomes the last one.
- **rb**: *rotate b* - shift up all elements of stack b by 1. The first element becomes the last one.
- **rr**: ra and rb at the same time.
- **rra**: *reverse rotate a* - shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb**: *reverse rotate b* - shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr**: rra and rrb at the same time.

### Approach

The algorithm I used for stacks with more than 5 numbers is explained very well in [**this video**](https://youtu.be/7KW59UO55TQ).

## 🛠️ Usage

### Requirements

The project is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile the library, run:

```shell
$ cd path/to/push_swap && make all
```

