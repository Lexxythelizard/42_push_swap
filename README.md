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

--> `min extraction sort`

**medium disorder**

--> `bucket sort`

**complex disorder**

--> `merge sort`

 
**takes flags:**

- `--simple` forced simple algorythm
- `--medium` forced medium algorythm
- `--complex` forced complex algorythm
- `--adaptive` choses the algorythm based on level of entropy
- `--bench` print benchmarks to STDERR


**Execution:**

Acording to the flags it choses one of three sorting algorythms \
if adaptive was selected it applies the sorting algorythm \
based on the level of entropy (no flag : adapptive by default) \
adaptive will not order an allready sorted stack \
if you want to force sort it: \
apply either `--simple`, `--medium` or `--complex`


### Our Approach

**We are craftsman / craftsgirls!** \
To us a good program - a good machine - isn't something abstract, \
it's something which is build of many parts working perfectly together. \
We imagine a program as a machine, driven by gears and springs \
...and probaply powered by steam ;) \
\
This how we write our code and how we planed the architecture of our project.


## Instructions

Compile programm with 

```bash
make push_swap
```

Run in the terminal

```bash
./push_swap [fist flags] [opt. sec flag] [sequenz of valid numbers separated by space]
```

### valid and invalid arguments

- flags have to be passed at the very beginning:
  - takes up to two flags in arbitary order
  - one of two flags have to be `--bench` (`--simple` `--complex` would be paradox)
  - no double flags allowed: `--bench` `--bench` [numbers] : --> invalid
- numbers have to be passed after the flags if there are flags
  - numbers have to be valid: `   -23` works but `23a` don't
  - numbers have to be unique: double values : --> invalid

## Resources

*The following resources were useful while working on this project:*

### Documentation

**man pages**
- git
  - git branch
  - git merge
  - git fetch
- ...

**makefile**
- GNU Make
- and simple try and error

**common webpages**
- algorythm visualisations

### Tools

- cc for compilation
- make for build automation
- ar for creating the static library
- valgrind for memory checking
- gdb for debugging
- custom test files for comparing original and ft_ behavior

### AI usage

**AI assistance was used for:**
- the term A.I. is some kinda sub cultural appropriation ;) 
- anyway it was used to check for typo and logic bugs in:
  - `./sort/sort_complex_mergesort*.c` files
  - `./sort/sort_medium_bucketsort*.c` files
- as a typist:
  - to type down the architecture tree as you see it down below :)

**What we learned about the usage of AI:** \
if you have a kinda unique way of coding, the AI appears to have a hard time to adapt. \
when we promted it our approach and the context what we coded so far \
the results / code we got out wasn't sadisfying at all \
(even if the feedback to our approach was positive) \
when we tried if it could fix a logical bug for us and keep the code readable \
it made it worse (on a bigger scale) in 2 / three cases.
But it was very good in smaller tasks like solving typo and logic bugs \
when we were prompting what three utility \
functions in a file should do and how we designed \
the gears turning each other and prompting the file itself \
In this cases it just fixed two or three lines and adapted our coding style :)

---

## Architecture

### Modules

#### Stackmachine 

- contains the two stacks
- contains the stats
- contains the 11 Operations as function pointers
- keeps track of elements in stacks
- keeps track of called operations
- keeps track of strategy
- keeps track of entropy
- takes just raw datas:
  - `int *` array of valid numbers
  - `int` flag key


#### Ui

- processes and validates user cli input
- checks if arguments are valid
  - checks are valid
  - checks if numbers are valid
  - checks if numbers are unique
- converts arguments:
  - converts valid numbers to `int *` array
  - converts valid flag to `int` : power of two or sum of two powers of two
- takes:
  - `int` argc
  - `char **` argv


#### Sort

- contains the simple sorting algorythm
- contains the medium sorting algorythm
- contains the complex sorting algorythm
- contains utilites for sorting
- takes a pointer to the instance of `t_stack_machine`
- gets called by orchestering functions in root directory


### Tree

```text
.
├── Makefile
├── README.md
├── main.c
├── push_swap.h
├── interface_sort.c
├── interface_stackmachine.c
├── interface_ui.c
├── libraries/
│   ├── ft_printf/
│   └── libft/
├── sort/
│   ├── sort.h
│   ├── sort_adaptive.c
│   ├── sort_benchmarks.c
│   ├── sort_complex.c
│   ├── sort_complex_mergesort.c
│   ├── sort_complex_mergesort_base.c
│   ├── sort_complex_mergesort_efficiency.c
│   ├── sort_complex_mergesort_merge_to_side_x.c
│   ├── sort_medium.c
│   ├── sort_medium_bucketsort.c
│   ├── sort_medium_bucketsort_fill_bucket.c
│   ├── sort_medium_bucketsort_sort_bucket.c
│   ├── sort_medium_bucketsort_utility.c
│   ├── sort_medium_bucketsort_utility_arr.c
│   ├── sort_medium_bucketsort_utility_arr_arr.c
│   ├── sort_simple.c
│   ├── sort_simple_min_extraction.c
│   ├── sort_small_stacks.c
│   ├── sort_utillities_execute_a.c
│   ├── sort_utillities_execute_b.c
│   └── sort_utillities_scan.c
├── stackmachine/
│   ├── machine.h
│   ├── machine_assign.c
│   ├── machine_machine.c
│   ├── machine_operation.c
│   ├── machine_operation_push.c
│   ├── machine_operation_reverse_rotate.c
│   ├── machine_operation_rotate.c
│   ├── machine_operation_swap.c
│   ├── funcs/
│   │   ├── funcs.h
│   │   └── machine_funcs.c
│   ├── stack/
│   │   ├── stack.h
│   │   ├── stack_elements.c
│   │   ├── stack_operation.c
│   │   ├── stack_pop_add.c
│   │   ├── stack_scan.c
│   │   ├── stack_scan_max.c
│   │   ├── stack_scan_min.c
│   │   └── stack_stack.c
│   └── stats/
│       ├── stats.h
│       ├── machine_stats.c
│       ├── machine_stats_strategy_entro.c
│       └── machine_stats_strategy_flag.c
└── ui/
    ├── ui.h
    ├── ui_convert_arguments.c
    ├── ui_entropy.c
    ├── ui_output.c
    ├── ui_validate_arguments.c
    ├── ui_validate_arguments_flags.c
    └── ui_validate_arguments_numbers.c
```

---

## Structs

### overview

- `t_stack_machine`
  - `t_stack`
    - `t_element`
  - `t_stats`
  - `t_func`

### define

**t_stack_machine**

defined in `./stackmachine/machine.h` \
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

defined in `./stackmachine/stack/stack.h`
`t_element` contails the value `int` \
as well as a pointer to prev element and next element in list
(pointer to instance of `t_element`) \
NOTE: \
	`last_element -> next` == `NULL` \
	`first_element -> prev` == `NULL` \
\
	`t_stack` is defined in the same file \

```C
typedef struct s_stack_node
{
    int                 val;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}                       t_element;

```

**t_stats**

defined in `./stackmachine/stats/stats.h`
`t_stats` contails an `int*` array of `OPS_N` lenght \
 as the total ops, a pointer to string strategy and the \
`float` entropy \
NOTE: `OPS_N` is `11`

```C
typedef struct s_stats
{
    unsigned int    calls[OPS_N];
    unsigned int    total_ops;
    float           entropy;
    char            *strategy;
}                   t_stats;
```

**t_funcs**

defined in `./stackmachine/funcs/funcs.h`
`t_func` contails an `int*` `function pointer` \
 and the name of the function as string \

```C
typedef struct s_func
{
    int     (*func)(struct s_stack_machine *machine);
    char    *name;
}           t_func;
```

---

## Authors

`esakella` \
`lenivorb`

42 Berlin login: `esakella` \
42 Berlin login: `lenivorb`

private Github:	https://github.com/esakella ? \
private Github:	https://github.com/Lexxythelizard
