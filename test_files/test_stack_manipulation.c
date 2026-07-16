// --- include ---

#include <assert.h>
#include <stdio.h>
#include "test_helper.h"
#include "../stackmachine/stack/stack.h"

// --- proto ---

void	test_element_one(void);
void	test_element_two(void);
void	test_stack_empty(void);
void	test_stack_one(void);
void	test_stack_two(void);
void	test_stack_three(void);

// --- run ---

int	main(void)
{
	printf("run test stacks:\n\n");
	test_element_one();
	test_element_two();
	test_stack_empty();
	test_stack_one();
	test_stack_two();
	test_stack_three();
	printf("\nall passed\n");
	return (0);
}

// --- define ---

void	test_element_one(void)
{
	t_element	*test;

	printf("test element one: ");
	test = create_element_one();
	assert(test -> val == 21);
	assert(test -> prev == NULL);
	assert(test -> next == NULL);
	assert(element_free(test) == 1);
	printf("[OK] \n");
}

void	test_element_two(void)
{
	t_element	*test;

	printf("test element two: ");
	test = create_element_two();
	assert(test -> prev == NULL);
	assert(test -> val == 21);
	assert(test -> next -> next == NULL);
	assert(test -> next -> val == 22);
	assert(test -> next -> prev == test);
	assert(test -> next -> prev -> prev == NULL);
	assert(test -> next -> prev -> val == 21);
	assert(test -> next -> prev -> next == test -> next);
	assert(element_free_tail(test) == 2);
	printf("[OK] \n");
}

void	test_stack_empty(void)
{
	t_stack	test;

	printf("test stack empty: ");
	test = create_stack_init_empty();
	assert(test.len == 0);
	assert(test.first == NULL);
	assert(test.last == NULL);
	assert(stack_free(&test) == 0);
	printf("[OK] \n");
}

void	test_stack_one(void)
{
	t_stack	test;

	printf("test stack one: ");
	test = create_stack_init_one_elements();
	assert(test.len == 1);
	assert(test.first -> val == 21);
	assert(test.first -> prev == NULL);
	assert(test.first -> next == NULL);
	assert(test.last -> val == 21);
	assert(test.last -> prev == NULL);
	assert(test.last -> next == NULL);
	assert(test.first == test.last);
	assert(stack_free(&test) == 1);
	printf("[OK] \n");
}

void	test_stack_two(void)
{
	t_stack	test;

	printf("test stack two: ");
	test = create_stack_init_two_elements();
	assert(test.len == 2);
	assert(test.first -> val == 21);
	assert(test.first -> prev == NULL);
	assert(test.first -> next == test.last);
	assert(test.last -> val == 22);
	assert(test.last -> prev == test.first);
	assert(test.last -> next == NULL);
	assert(test.first != test.last);
	assert(stack_free(&test) == 2);
	printf("[OK] \n");
}

void	test_stack_three(void)
{
	t_stack	test;

	printf("test stack three: ");
	test = create_stack_init_three_elements();
	assert(test.len == 3);
	assert(test.first -> val == 21);
	assert(test.first -> prev == NULL);
	assert(test.first -> next == test.last -> prev);
	assert(test.last -> val == 23);
	assert(test.last -> prev == test.first -> next);
	assert(test.last -> next == NULL);
	assert(test.first -> next -> val == 22);
	assert(test.last -> prev -> val == 22);
	assert(test.first != test.last);
	assert(stack_free(&test) == 3);
	printf("[OK] \n");
}
