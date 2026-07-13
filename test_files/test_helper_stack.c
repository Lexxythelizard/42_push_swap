// --- icludes ---

#include <stdlib.h>
#include "test_helper.h"
#include "../libraries/stack_machine/core/stack.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

// ../libraries/stack_machine/stack_elements.c

t_element   *element_new(int val, t_element *prev);
t_element   *element_new_list(int *arr, int len);
int         element_free(t_element *element);
int         element_free_tail(t_element *element);

// ../libraries/stack_machine/stack_stack.c

void		stack_init_empty(t_stack *stack);
int			stack_init(t_stack *stack, int *arr, int len);
int			free_stack(t_stack *stack);

// this file

t_element	*create_element_one(void);
t_element	*create_element_two(void);
t_element	*create_element_list(void);
t_stack		create_stack_init_empty(void);
t_stack		create_stack_init_one_elements(void);
t_stack		create_stack_init_two_elements(void);
t_stack		create_stack_init_three_elements(void);
t_stack		create_stack_init(void);
int			create_stack_free(t_stack *stack);

// --- define ---

t_element	*create_element_one(void)
{
	return (element_new(21, NULL));
}

t_element	*create_element_two(void)
{
	return (element_new(22, new_element(21, NULL)));
}

t_element	*create_element_list(void)
{
	int	arr[3];
	int	len;

	arr[0] = 21;
	arr[1] = 22;
	arr[2] = 23;
	len = 3;
	return (element_new_list(arr, len));
}

t_stack	create_stack_init_empty(void)
{
	t_stack	new_stack;

	stack_init_empty(&new_stack);
	return (new_stack);
}

t_stack	create_stack_init_one_elements(void)
{
	t_stack	new_stack;
	int		arr[1];

	arr[0] = 21;
	stack_init(&new_stack, arr, 1);
	return (stack);
}

t_stack	create_stack_init_two_elements(void)
{
	t_stack	new_stack;
	int		arr[2];

	arr[0] = 21;
	arr[1] = 22;
	stack_init(&new_stack, arr, 2);
	return (stack);
}

t_stack	create_stack_init_three_elements(void)
{
	t_stack	new_stack;
	int		arr[3];

	arr[0] = 21;
	arr[1] = 22;
	arr[2] = 23;
	stack_init(&new_stack, arr, 3);
	return (stack);
}

int	create_stack_free(t_stack *stack)
{
	return (stack_free(stack));
}
