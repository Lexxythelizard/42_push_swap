ARCHITECTURE.md

NOTE:

```bash
code ./ARCHITECTURE.md
```

then press:

```text
[ctrl] + [shift] + [v]
```
to render it :)

---

## Current File Overview

### Core / Interface
- `interface.c`
- `interface_flags.c`
- `interface_push.c`
- `interface_rotate.c`
- `interface_rrotate.c`
- `interface_swap.c`

### Stack Operations
- `stack.c`
- `stack.h`
- `exec_push.c`
- `exec_rotate.c`
- `exec_rrotate.c`
- `exec_swap.c`

### Scanning / Metrics
- `scan_stack_0.c`
- `scan_stack_1.c`
- `disorder_metric.c`

### Sorting
- `sort_simple_0.c`

### CLI / Validation
- `ui_cli.c`
- `ui_cli.h`
- `validation.c`

### Output / Tracking
- `output.h`
- `op_tracker.h`
- `output_layer_0.c`
- `output_layer_1.c`
- `utility_output.c`

### General
- `push_swap.h`
- `array_handling.c`
- `skeleton_def.c`

---

## Dependency layers

### main function

*this is basicly just the scratchnotes of how I imagined the dependency in our main 
since most of the neted funnctions aren't implemented yet*

NOTE: I'm not sure if flags and numbers could be parsed in an arbitary order, see DEV\_NOTES

```text
Program flow
└── main()                              main.c
    ├── validate arguments
    │   └── is_args_valid()             validation.c
    │       ├── is_valid_nbr()          validation.c
    │       └── is_valid_flag()         validation.c
    │
    ├── handle errors
    │   └── raise_x_error()             ...not implemented yet...
    │
    ├── initialize flags
    │   └── init_flags()                ...not implemented yet...
    │
    ├── initialize interface
    │   └── init()                      interface.c
    │
    ├── run sorting
    │   └── run_sort()                  ...not implemented yet...
    │       ├── sort_simple()           sort_simple_0.c
    │       ├── sort_medium()           ...not implemented yet...
    │       ├── sort_complex()          ...not implemented yet...
    │       └── sort_adaptive()         ...not implemented yet...
    │
    └── return (0)                      main.c
```

### init functions

since I slightly modified the init() (*just by sourcing out the creating and initializing 
of the in array*) I mapped the dependencies here.

NOTE: init does not do any validation, validation should be called befor or in main()

```text
Core Interface
└── init()                      		interface.c
    ├── stack_init()            		stack.c
    └── get_int_list()          		ui_cli.c
        ├── count_numbers()     		ui_cli.c
        └── is_valid_number()   		validation.c
```

### sorting functions

using the scanning and the exec functions

```text
sorting functions
├── sort_simple()				sort_simple_0.c
│   ├── get_stack_size()		scan_stack_1.c
│   ├── get_index_min_val()		scan_stack_1.c
│   ├── exec_ra_n()             exec_rotate.c
│   ├── exec_rra_n()            exec_rrotate.c
│   ├── exec_pa_n()             exec_push.c
│   └── exec_pb_n()             exec_push.c
│
├── sort_medium()				...
│   ├── ... follows
│
├── sort_complex()				...
│   ├── ... follows
│
└── sort_adaptive()				...
    ├── ... follows

```

### exec functions

using interface functions and executing them n times 
updating the operation tracker and printing the operation to STDOUT

```text
Exec functions
├── Rotate operations
│   ├── exec_ra_n()             exec_rotate.c
│   │   └── ra()                interface_rotate.c
│   │       └── r()             stack.c
│   ├── exec_rb_n()             exec_rotate.c
│   │   └── rb()                interface_rotate.c
│   │       └── r()             stack.c
│   └── exec_rr_n()             exec_rotate.c
│       └── rr()                interface_rotate.c
│           └── r()             stack.c
│
├── Reverse rotate operations
│   ├── exec_rra_n()            exec_rrotate.c
│   │   └── rra()               interface_rrotate.c
│   │       └── rr()            stack.c
│   ├── exec_rrb_n()            exec_rrotate.c
│   │   └── rrb()               interface_rrotate.c
│   │       └── rr()            stack.c
│   └── exec_rrr_n()            exec_rrotate.c
│       └── rrr()               interface_rrotate.c
│           └── rr()            stack.c
│
├── Swap operations
│   ├── exec_sa_n()             exec_swap.c
│   │   └── sa()                interface_swap.c
│   │       └── s()             stack.c
│   ├── exec_sb_n()             exec_swap.c
│   │   └── sb()                interface_swap.c
│   │       └── s()             stack.c
│   └── exec_ss_n()             exec_swap.c
│       └── ss()                interface_swap.c
│           └── s()             stack.c
│
└── Push operations
    ├── exec_pa_n()             exec_push.c
    │   └── pa()                interface_push.c
    │       └── p()             stack.c
    └── exec_pb_n()             exec_push.c
        └── pb()                interface_push.c
            └── p()             stack.c
```

