// --- include ---

#include <assert.h>
#include <stdio.h>
#include "test_helper.h"
#include "../libraries/stack_machine/stackmachine.h"

// --- proto ---

void	test_swap_empty(void);
void	test_swap_one(void);
void	test_swap_two(void);
void	test_swap_three(void);
void	test_rotate_empty(void);
void	test_rotate_one(void);
void	test_rotate_two(void);
void	test_rotate_three(void);
void	test_reverse_rotate_empty(void);
void	test_reverse_rotate_one(void);
void	test_reverse_rotate_two(void);
void	test_reverse_rotate_three(void);
void	test_push_from_stack_empty(void);
void	test_push_from_stack_one(void);
void	test_push_from_stack_two(void);
void	test_push_from_stack_three(void);

// --- run ---

int	main(void)
{
	printf("run test stacks:\n\n");
	test_swap_empty();
	test_swap_one();
	test_swap_two();
	test_swap_three();
	test_rotate_empty();
	test_rotate_one();
	test_rotate_two();
	test_rotate_three();
	test_reverse_rotate_empty();
	test_reverse_rotate_one();
	test_reverse_rotate_two();
	test_reverse_rotate_three();
	test_push_from_stack_empty();
	test_push_from_stack_one();
	test_push_from_stack_two();
	test_push_from_stack_three();
	printf("\nall passed\n");
	return (0);
}

// --- define ---

// operations swap

void	test_swap_empty(void)
{
	t_stack	test;

	printf("test swap with empty stack: ");

	test = create_stack_init_empty();
	assert(stack_free(&test) == 0);

	printf("[implment] \n");
}

void	test_swap_one(void)
{
	t_stack	test;

	printf("test swap with one element stack: ");

	test = create_stack_init_one_elements();
	assert(stack_free(&test) == 1);

	printf("[implment] \n");
}

void	test_swap_two(void)
{
	t_stack	test;

	printf("test swap with two element stack: ");

	test = create_stack_init_two_elements();
	assert(stack_free(&test) == 2);

	printf("[implment] \n");
}

void	test_swap_three(void)
{
	t_stack	test;

	printf("test swap with three element stack: ");

	test = create_stack_init_three_elements();
	assert(stack_free(&test) == 3);

	printf("[implment] \n");
}

// operations rotate

void	test_rotate_empty(void)
{
	t_stack	test;

	printf("test rotate with empty stack: ");

	test = create_stack_init_empty();
	assert(stack_free(&test) == 0);

	printf("[implment] \n");
}

void	test_rotate_one(void)
{
	t_stack	test;

	printf("test rotate with one element stack: ");

	test = create_stack_init_one_elements();
	assert(stack_free(&test) == 1);

	printf("[implment] \n");
}

void	test_rotate_two(void)
{
	t_stack	test;

	printf("test rotate with two element stack: ");

	test = create_stack_init_two_elements();
	assert(stack_free(&test) == 2);

	printf("[implment] \n");
} 

void	test_rotate_three(void)
{
	t_stack	test;

	printf("test rotate with three element stack: ");

	test = create_stack_init_three_elements();
	assert(stack_free(&test) == 3);

	printf("[implment] \n");
}

// operations reverse rotate

void	test_reverse_rotate_empty(void)
{
	t_stack	test;

	printf("test reverse rotate with empty stack: ");

	test = create_stack_init_empty();
	assert(stack_free(&test) == 0);

	printf("[implment] \n");
}

void	test_reverse_rotate_one(void)
{
	t_stack	test;

	printf("test reverse rotate with one element stack: ");

	test = create_stack_init_one_elements();
	assert(stack_free(&test) == 1);

	printf("[implment] \n");
}

void	test_reverse_rotate_two(void)
{
	t_stack	test;

	printf("test reverse rotate with two element stack: ");

	test = create_stack_init_two_elements();
	assert(stack_free(&test) == 2);

	printf("[implment] \n");
}

void	test_reverse_rotate_three(void)
{
	t_stack	test;

	printf("test reverse rotate with three element stack: ");

	test = create_stack_init_three_elements();
	assert(stack_free(&test) == 3);

	printf("[implment] \n");
}


// operations push

void	test_push_from_stack_empty(void)
{
	t_stack	test;

	printf("test push from empty stack: ");

	test = create_stack_init_empty();
	assert(stack_free(&test) == 0);

	printf("[implment] \n");
}

void	test_push_from_stack_one(void)
{
	t_stack	test;

	printf("test push from one element stack: ");

	test = create_stack_init_one_elements();
	assert(stack_free(&test) == 1);

	printf("[implment] \n");
}

void	test_push_from_stack_two(void)
{
	t_stack	test;

	printf("test push from two element stack: ");

	test = create_stack_init_two_elements();
	assert(stack_free(&test) == 2);

	printf("[implment] \n");
}

void	test_push_from_stack_three(void)
{
	t_stack	test;

	printf("test push from three element stack: ");

	test = create_stack_init_three_elements();
	assert(stack_free(&test) == 3);

	printf("[implment] \n");
}
