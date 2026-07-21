README.md

*This project has been created as part of the 42 curriculum \
as a collaboration by esakella and lenivorb.*

# Push Swap

## Description

Push Swap is a custom C program created as part of the 42 curriculum.

The goal of this project is to implement a program which simulates a \
stack machine with two stacks and is able to sort them by using \
the following operations:

- `sa` :	swap first two elements of stack a
- `sb` :	swap first two elements of stack b
- `sa` :	swap first two elements of stack a and stack b
- `pa` :	pushes first element of stack b to stack a
- `pb` :	pushes first element of stack a to stack b
- `ra` :	rotate elements of stack a
- `rb` :	rotate elements of stack b
- `rr` :	rotate elements of stack a and stack b
- `rra` :	reverse rotate elements of stack a
- `rrb` :	reverse rotate elements of stack b
- `rrr` :	reverse rotate elements of stack a and stack b

the program is capable of using three different sorting algorythms

**simple disorder**

`min extraction sort`

**medium disorder**

`bucket sort`		*planend*

**complex disorder**

`merge sort`		*planned*

 
also takes flags:

- `--simple` forced simple algorythm
- `--medium` forced medium algorythm
- `--complex` forced complex algorythm
- `--adaptive` choses the algorythm based on level of entropy
- `--bench` print benchmarks to STDERR


## Instructions

Compile programm with 

```bash
make push_swap
```

`[describe how to interact in Terminal]` 

```bash
./push_swap [fist flags] [opt. sec flag] [sequenz of valid numbers separated by space]
```

### valid and invalid arguments

	...follows...

## Resources

*The following resources were useful while working on this project:*

### Documentation

**man pages**
- ...
- ...

**makefile**
- ...

**common webpages**
- Geeks for Geeks : https://www.geeksforgeeks.org/c/c-programming-language/
- stackoverflow : https://stackoverflow.com/questions
- wikiboks : https://en.wikibooks.org/wiki/C\_Programming/
	- espacially: 
	  https://en.wikibooks.org/wiki/C\_Programming/POSIX\_Reference/unistd.h
- ... 

### Tools

- cc for compilation
- make for build automation
- ar for creating the static library
- valgrind for memory checking
- custom test files for comparing original and ft_ behavior
- utility bash files:
	- ...
- codes testers:
	- ...

### AI usage

AI assistance was used for:
- not at all
- also A.I. is some kinda sub cultural appropriation, but no LLMs were used so far

---

## Architecture

### Tree

```text
push_swap/
├── Makefile
├── README.md
├── main.c
├── push_swap.h
├── interface_sort.c
├── interface_stackmachine.c
├── interface_ui.c
├── libraries/
│   ├── libft/
│   └── ft_printf/
├── sort/
│   ├── sort.h
│   ├── sort_simple.c
│   ├── sort_medium.c
│   ├── sort_adaptive.c
│   ├── sort_complex.c
│   ├── sort_complex_mergesort.c
│   ├── sort_complex_mergesort_base.c
│   ├── sort_utillities.c
│   └── sort_benchmarks.c
├── stackmachine/
│   ├── machine.h
│   ├── machine_assign.c
│   ├── machine_machine.c
│   ├── machine_operation.c
│   ├── machine_operation_push.c
│   ├── machine_operation_rotate.c
│   ├── machine_operation_reverse_rotate.c
│   ├── machine_operation_swap.c
│   ├── funcs/
│   │   ├── funcs.h
│   │   └── machine_funcs.c
│   ├── stack/
│   │   ├── stack.h
│   │   ├── stack_stack.c
│   │   ├── stack_elements.c
│   │   ├── stack_operation.c
│   │   ├── stack_pop_add.c
│   │   └── stack_scan.c
│   └── stats/
│       ├── stats.h
│       ├── machine_stats.c
│       ├── machine_stats_strategy_flag.c
│       └── machine_stats_strategy_entro.c
└── ui/
    ├── ui.h
    ├── ui_convert_arguments.c
    ├── ui_validate_arguments.c
    ├── ui_validate_arguments_flags.c
    ├── ui_validate_arguments_numbers.c
    ├── ui_entropy.c
    └── ui_output.c

```

## Structs

### overview

- `t_stack_machine`
  - `t_stack`
    - `t_element`
  - `t_stats`
  - `t_func`

### define

**t_stack_machine**

defined in `./stackmachine/machine.h`
`t_stack_machine` contains two instances of `t_stack` one instance of `t_stats` \
and `OPS_N` instances of `t_func` \
while `OPS_N` is defined in `./stackmachine/funcs/funcs.h`

```C
typedef struct s_stack_machine
{
    t_stack stacks[2];
    t_stats stats;
    t_func  funcs[OPS_N];   
}           t_stack_machine;

```

**t_stack**

defined in `./stackmachine/stack/stack.h`
`t_stack` contails the length of the `t_stack` instance \
as well as a pointer to first element and last element in stack
(pointer to instance of `t_element`)
while `t_element` is defined in the same file

```C
typedef struct s_stack {
    int         len;
    t_element   *first;
    t_element   *last;
}               t_stack;

```

**t_element**

	...folows...

**t_stats**

	...folows...

**t_funcs**

	...folows...

---

## Modules

### Stackmachine 

- ...
- ...
- ...


### Ui

- ...
- ...
- ...


---

## Authors

`esakella` \
`lenivorb`

42 Berlin login: `esakella` \
42 Berlin login: `lenivorb`

private Github:	https://github.com/esakella ? \
private Github:	https://github.com/Lexxythelizard
