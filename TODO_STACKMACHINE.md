Branch: stackmachine

# TODO:

## Implementation:

### Test:

- `stack_elements.c`							[x] DONE
- `stack_manipulation.c`						[x] DONE

### Refactor and test:

- `machine_operation.c`							[x] DONE
- `machine_operation_push.c`					[x] DONE
- `machine_operation_reverse_rotate.c`			[x] DONE
- `machine_operation_rotate.c`					[x] DONE
- `machine_operation_swap.c`					[x] DONE

### Reimplement from the scratch:

- `disorder_metric.c`		removed				[x] DONE			
- `machine_assign.c`							[x] DONE
- `machine_machine.c`							[x] DONE
- `stack_operation.c`							[x] DONE
- `stack_pop_add.c`								[x] DONE
- `stack_scan.c`

### Implement:

- `machine_stats`								[x] DONE
- `machine_func`								[x] DONE

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
  - `[OP_STR]` 	`[str]`								[x] DONE
  - `[OP]` 		`[int]`								[x] DONE
