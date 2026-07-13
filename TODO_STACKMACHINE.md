Branch: stackmachine

# TODO:

## Implementation:

### Test:

- `stack_elements.c`							[x] DONE
- `stack_manipulation.c`						[x] DONE

### Refactor and test:

- `machine_exec.c`
- `machine_operation_push.c`
- `machine_operation_reverse_rotate.c`
- `machine_operation_rotate.c`
- `machine_operation_swap.c`

### Reimplement from the scratch:

- `disorder_metric.c`
- `machine_free.c`
- `machine_init.c`
- `stack_operation.c`
- `stack_scan.c`


## move and make

### outsource split

- `machine_init.c` --> `machine_stats`			[x] DONE
- `machine_init.c` --> `machine_func`			[x] DONE
- `machine_init.c` --> `machine_machine`		[x] DONE

### rename

- `machine_manipulation.c` --> `stack_stack`	[x] DONE

## features

### Problemns

- count element in stacks after manipualting cost computation
- stacks.calls is array: lost track of idx...
- machine.func is array

### solution

- stacks should keep track of number of elements	[x] DONE
- use define to define
  - `[OP_STR]` 	`[str]`
  - `[OP]` 		`[int]`
