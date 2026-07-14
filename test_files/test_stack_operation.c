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
	assert(swap(NULL) == (-1));
	assert(swap(&test) == 0);
	assert(stack_free(&test) == 0);

	printf("[OK] \n");
}

void	test_swap_one(void)
{
	t_stack	test;

	printf("test swap with one element stack: ");

	test = create_stack_init_one_elements();
	assert(swap(NULL) == (-1));
	assert(swap(&test) == 0);
	assert(test.first == test.last);
	assert(test.first -> next == NULL);
	assert(test.first -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(test.last -> prev == NULL);
	assert(stack_free(&test) == 1);

	printf("[OK] \n");
}

void	test_swap_two(void)
{
	t_stack	test;

	printf("test swap with two element stack: ");

	test = create_stack_init_two_elements();
	assert(swap(NULL) == (-1));
	assert(test.first -> val == 21);
	assert(test.last -> val == 22);
	assert(test.first != test.last);
	assert(swap(&test) == 1);
	assert(test.first -> val == 22);
	assert(test.last -> val == 21);
	assert(test.first != test.last);
	assert(test.first -> next == test.last);
	assert(test.first -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(test.last -> prev == test.first);
	assert(stack_free(&test) == 2);

	printf("[OK] \n");
}

void	test_swap_three(void)
{
	t_stack	test;

	printf("test swap with three element stack: ");

	test = create_stack_init_three_elements();
	assert(swap(NULL) == (-1));
	assert(test.first -> val == 21);
	assert(test.first -> next -> val == 22);
	assert(test.last -> val == 23);
	assert(test.first -> next == test.last -> prev);
	assert(swap(&test) == 1);
	assert(test.first -> val == 22);
	assert(test.first -> next -> val == 21);
	assert(test.last -> val == 23);
	assert(test.first -> next == test.last -> prev);
	assert(test.first -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(stack_free(&test) == 3);

	printf("[OK] \n");
}

// operations rotate

void	test_rotate_empty(void)
{
	t_stack	test;

	printf("test rotate with empty stack: ");

	test = create_stack_init_empty();
	assert(rotate(NULL) == (-1));
	assert(rotate(&test) == 0);
	assert(test.first == NULL);
	assert(test.last == NULL);
	assert(stack_free(&test) == 0);

	printf("[OK] \n");
}

void	test_rotate_one(void)
{
	t_stack	test;

	printf("test rotate with one element stack: ");

	test = create_stack_init_one_elements();
	assert(rotate(NULL) == (-1));
	assert(test.first -> val == 21);
	assert(test.last -> val == 21);
	assert(test.last == test.first);
	assert(rotate(&test) == 1);
	assert(test.first -> val == 21);
	assert(test.last -> val == 21);
	assert(test.first -> prev == NULL);
	assert(test.first -> next == NULL);
	assert(test.last -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(test.last == test.first);
	assert(stack_free(&test) == 1);

	printf("[OK] \n");
}

void	test_rotate_two(void)
{
	t_stack	test;

	printf("test rotate with two element stack: ");

	test = create_stack_init_two_elements();
	assert(rotate(NULL) == (-1));
	assert(rotate(&test) == 1);
	assert(test.first -> val == 22);
	assert(test.last -> val == 21);
	assert(test.first != test.last);
	assert(test.first -> next == test.last);
	assert(test.first -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(test.last -> prev == test.first);
	assert(stack_free(&test) == 2);

	printf("[OK] \n");
} 

void	test_rotate_three(void)
{
	t_stack	test;

	printf("test rotate with three element stack: ");

	test = create_stack_init_three_elements();
	assert(test.first -> val == 21);
	assert(test.first -> next -> val == 22);
	assert(test.last -> val == 23);
	assert(rotate(NULL) == (-1));
	assert(rotate(&test) == 1);
	assert(test.first -> val == 23);
	assert(test.first -> next -> val == 21);
	assert(test.last -> val == 22);
	assert(test.first -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(test.first -> next -> prev == test.first);
	assert(test.first -> next -> next == test.last);
	assert(test.last -> prev == test.first -> next);
	assert(stack_free(&test) == 3);

	printf("[OK] \n");
}

// operations reverse rotate

void	test_reverse_rotate_empty(void)
{
	t_stack	test;

	printf("test reverse rotate with empty stack: ");

	test = create_stack_init_empty();
	assert(reverse_rotate(NULL) == (-1));
	assert(reverse_rotate(&test) == 0);
	assert(test.first == NULL);
	assert(test.last == NULL);
	assert(stack_free(&test) == 0);

	printf("[OK] \n");
}

void	test_reverse_rotate_one(void)
{
	t_stack	test;

	printf("test reverse rotate with one element stack: ");

	test = create_stack_init_one_elements();
	assert(test.first -> val == 21);
	assert(test.last -> val == 21);
	assert(test.last == test.first);
	assert(reverse_rotate(NULL) == (-1));
	assert(reverse_rotate(&test) == 1);
	assert(test.first -> val == 21);
	assert(test.last -> val == 21);
	assert(test.first -> prev == NULL);
	assert(test.first -> next == NULL);
	assert(test.last -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(test.last == test.first);
	assert(stack_free(&test) == 1);

	printf("[OK] \n");
}

void	test_reverse_rotate_two(void)
{
	t_stack	test;

	printf("test reverse rotate with two element stack: ");

	test = create_stack_init_two_elements();
	assert(test.first -> val == 21);
	assert(test.last -> val == 22);
	assert(reverse_rotate(NULL) == (-1));
	assert(reverse_rotate(&test) == 1);
	assert(test.first -> val == 22);
	assert(test.last -> val == 21);
	assert(test.first != test.last);
	assert(test.first -> next == test.last);
	assert(test.first -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(test.last -> prev == test.first);
	assert(stack_free(&test) == 2);

	printf("[OK] \n");
}

void	test_reverse_rotate_three(void)
{
	t_stack	test;

	printf("test reverse rotate with three element stack: ");

	test = create_stack_init_three_elements();
	assert(test.first -> val == 21);
	assert(test.first -> next -> val == 22);
	assert(test.last -> val == 23);
	assert(reverse_rotate(NULL) == (-1));
	assert(reverse_rotate(&test) == 1);
	assert(test.first -> val == 22);
	assert(test.first -> next -> val == 23);
	assert(test.last -> val == 21);
	assert(test.first -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(test.first -> next -> prev == test.first);
	assert(test.first -> next -> next == test.last);
	assert(test.last -> prev == test.first -> next);
	assert(stack_free(&test) == 3);

	printf("[OK] \n");
}


// operations push

void	test_push_from_stack_empty(void)
{
	t_stack	test0;
	t_stack	test1;

	printf("test push from empty stack: ");

	test0 = create_stack_init_empty();
	test1 = create_stack_init_empty();
	assert(push(NULL, &test1) == (-1));
	assert(push(&test0, NULL) == (-1));
	assert(push(NULL, NULL) == (-1));
	assert(push(&test0, &test1) == 0);
	assert(stack_free(&test0) == 0);
	assert(stack_free(&test1) == 0);

	printf("[OK] \n");
}

void	test_push_from_stack_one(void)
{
	t_stack	test0;
	t_stack	test1;

	printf("test push from one element stack: ");

	test0 = create_stack_init_one_elements();
	test1 = create_stack_init_empty();
	assert(push(&test1, &test0) == 0);
	assert(test0.len == 1);
	assert(test1.len == 0);
	assert(push(&test0, &test1) == 1);
	assert(test0.len == 0);
	assert(test0.first == NULL);
	assert(test0.last == NULL);
	assert(test1.len == 1);
	assert(test1.first -> val == 21);
	assert(test1.first -> next == NULL);
	assert(test1.first -> prev == NULL);
	assert(test1.first == test1.last);
	assert(stack_free(&test0) == 0);
	assert(stack_free(&test1) == 1);

	printf("[OK] \n");
}

void	test_push_from_stack_two(void)
{
	t_stack	test0;
	t_stack	test1;

	printf("test push from two element stack: ");

	test0 = create_stack_init_two_elements();
	assert(stack_free(&test0) == 2);

	printf("[implment] \n");
}

void	test_push_from_stack_three(void)
{
	t_stack	test0;
	t_stack	test1;

	printf("test push from three element stack: ");

	test0 = create_stack_init_three_elements();
	assert(stack_free(&test0) == 3);

	printf("[implment] \n");
}
