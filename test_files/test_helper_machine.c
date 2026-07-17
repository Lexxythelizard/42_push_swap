// --- icludes ---

#include <stdlib.h>
#include "test_helper.h"
#include "../stackmachine/machine.h"

// --- DOC ---

/*
	define all test functions needed to test all the stack functions
*/

// --- prototype ---

// this file

t_stack_machine	create_machine_init_empty(void);
t_stack_machine	create_machine_init_one_elements(void);
t_stack_machine	create_machine_init_two_elements(void);
t_stack_machine	create_machine_init_three_elements(void);

// --- define ---

t_stack_machine	create_machine_init_empty(void)
{
	t_stack_machine	new_machine;

	machine_init_new_empty(&new_machine);
	return (new_machine);
}

t_stack_machine	create_machine_init_one_elements(void)
{
	t_stack_machine	new_machine;
	int		arr[1];

	arr[0] = 21;
	machine_stack_init(&new_machine, arr, 1);
	return (new_machine);
}

t_stack_machine	create_machine_init_two_elements(void)
{
	t_stack_machine	new_machine;
	int		arr[2];

	arr[0] = 21;
	arr[1] = 22;
	machine_stack_init(&new_machine, arr, 2);
	return (new_machine);
}

t_stack_machine	create_machine_init_three_elements(void)
{
	t_stack_machine	new_machine;
	int		arr[3];

	arr[0] = 21;
	arr[1] = 22;
	arr[2] = 23;
	machine_stack_init(&new_machine, arr, 3);
	return (new_machine);
}
