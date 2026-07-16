// --- include ---

#include <assert.h>
#include <stdio.h>
#include "test_helper.h"
#include "../stackmachine/stack/stack.h"

// --- proto ---

void	test_stack_init_add(void);
void	test_stack_add_first_empty(void);
void	test_stack_add_first_one(void);
void	test_stack_add_first_two(void);
void	test_stack_add_last_empty(void);
void	test_stack_add_last_one(void);
void	test_stack_add_last_two(void);
void	test_stack_pop_first_empty(void);
void	test_stack_pop_first_one(void);
void	test_stack_pop_first_two(void);
void	test_stack_pop_last_empty(void);
void	test_stack_pop_last_one(void);
void	test_stack_pop_last_two(void);

// --- run ---

int	main(void)
{
	printf("run test stack basic operations:\n\n");
	test_stack_init_add();
	test_stack_add_first_empty();
	test_stack_add_first_one();
	test_stack_add_first_two();
	test_stack_add_last_empty();
	test_stack_add_last_one();
	test_stack_add_last_two();
	test_stack_pop_first_empty();
	test_stack_pop_first_one();
	test_stack_pop_first_two();
	test_stack_pop_last_empty();
	test_stack_pop_last_one();
	test_stack_pop_last_two();
	printf("\nall passed\n");
	return (0);
}

// --- define ---

// add init

void	test_stack_init_add(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack init add: ");
	test = create_stack_init_empty();
	new = create_element_one();
	assert(stack_init_add(NULL, NULL) == (-1));
	assert(stack_init_add(&test, NULL) == 0);
	assert(stack_init_add(&test, new) == 1);
	assert(test.first == new);
	assert(test.last == new);
	assert(test.first == test.last);
	assert(test.first -> val == 21);
	assert(test.len == 1);
	assert(stack_free(&test) == 1);
	printf("[OK] \n");
}

// add first

void	test_stack_add_first_empty(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack add first with empty stack: ");
	test = create_stack_init_empty();
	new = create_element_one();
	assert(stack_add_first(NULL, NULL) == (-1));
	assert(stack_add_first(&test, NULL) == 0);
	assert(stack_add_first(&test, new) == 1);
	assert(test.first == new);
	assert(test.last == new);
	assert(test.first == test.last);
	assert(test.first -> val == 21);
	assert(test.len == 1);
	assert(stack_free(&test) == 1);
	printf("[OK] \n");
}

void	test_stack_add_first_one(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack add first with one element stack: ");
	test = create_stack_init_one_elements();
	new = create_element_one();
	test.first -> val += 1;
	assert(stack_add_first(NULL, NULL) == (-1));
	assert(stack_add_first(&test, NULL) == 0);
	assert(stack_add_first(&test, new) == 2);
	assert(test.first == new);
	assert(test.last == test.first -> next);
	assert(test.first == test.last -> prev);
	assert(test.first -> val == 21);
	assert(test.last -> val == 22);
	assert(test.len == 2);
	assert(stack_free(&test) == 2);
	printf("[OK] \n");
}

void	test_stack_add_first_two(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack add first with two element stack: ");
	test = create_stack_init_two_elements();
	new = create_element_one();
	test.first -> val += 1;
	test.last -> val += 1;
	assert(stack_add_first(NULL, NULL) == (-1));
	assert(stack_add_first(&test, NULL) == 0);
	assert(stack_add_first(&test, new) == 3);
	assert(test.first == new);
	assert(test.first -> val == 21);
	assert(test.first -> next -> val == 22);
	assert(test.last -> val == 23);
	assert(test.first -> next == test.last -> prev);
	assert(test.len == 3);
	assert(stack_free(&test) == 3);
	printf("[OK] \n");
}

// add last

void	test_stack_add_last_empty(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack add last with empty stack: ");
	test = create_stack_init_empty();
	new = create_element_one();
	assert(stack_add_first(NULL, NULL) == (-1));
	assert(stack_add_first(&test, NULL) == 0);
	assert(stack_add_first(&test, new) == 1);
	assert(test.first == new);
	assert(test.last == new);
	assert(test.first == test.last);
	assert(test.first -> val == 21);
	assert(test.len == 1);
	assert(stack_free(&test) == 1);
	printf("[OK] \n");
}

void	test_stack_add_last_one(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack add last with one element stack: ");
	test = create_stack_init_one_elements();
	new = create_element_one();
	test.first -> val += 1;
	assert(stack_add_first(NULL, NULL) == (-1));
	assert(stack_add_first(&test, NULL) == 0);
	assert(stack_add_first(&test, new) == 2);
	assert(test.first == new);
	assert(test.last == test.first -> next);
	assert(test.first == test.last -> prev);
	assert(test.first -> val == 21);
	assert(test.last -> val == 22);
	assert(test.len == 2);
	assert(stack_free(&test) == 2);
	printf("[OK] \n");
}

void	test_stack_add_last_two(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack add last with two element stack: ");
	test = create_stack_init_two_elements();
	new = create_element_one();
	test.first -> val += 1;
	test.last -> val += 1;
	assert(stack_add_first(NULL, NULL) == (-1));
	assert(stack_add_first(&test, NULL) == 0);
	assert(stack_add_first(&test, new) == 3);
	assert(test.first == new);
	assert(test.first -> val == 21);
	assert(test.first -> next -> val == 22);
	assert(test.last -> val == 23);
	assert(test.first -> next == test.last -> prev);
	assert(test.len == 3);
	assert(stack_free(&test) == 3);
	printf("[OK] \n");
}

// pop first

void	test_stack_pop_first_empty(void)
{
	t_stack		test;

	printf("test stack pop first with empty stack: ");
	test = create_stack_init_empty();
	assert(stack_pop_first(NULL) == NULL);
	assert(stack_pop_first(&test) == NULL);
	assert(stack_free(&test) == 0);
	printf("[OK] \n");
}

void	test_stack_pop_first_one(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack pop first with one element stack: ");
	test = create_stack_init_one_elements();
	new = stack_pop_first(&test);
	assert(new -> next == NULL);
	assert(new -> prev == NULL);
	assert(new -> val == 21);
	assert(test.first == NULL);
	assert(test.last == NULL);
	assert(test.len == 0);
	assert(stack_free(&test) == 0);
	assert(element_free(new) == 1);
	printf("[OK] \n");
}

void	test_stack_pop_first_two(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack pop first with two element stack: ");
	test = create_stack_init_two_elements();
	new = stack_pop_first(&test);
	assert(new -> next == NULL);
	assert(new -> prev == NULL);
	assert(new -> val == 21);
	assert(test.first == test.last);
	assert(test.last -> prev == NULL);
	assert(test.len == 1);
	assert(stack_free(&test) == 1);
	assert(element_free(new) == 1);

	printf("[OK] \n");
}

// pop last

void	test_stack_pop_last_empty(void)
{
	t_stack		test;

	printf("test stack pop last with empty stack: ");
	test = create_stack_init_empty();
	assert(stack_pop_last(NULL) == NULL);
	assert(stack_pop_last(&test) == NULL);
	assert(stack_free(&test) == 0);
	printf("[OK] \n");
}

void	test_stack_pop_last_one(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack pop last with one element stack: ");
	test = create_stack_init_one_elements();

	new = stack_pop_last(&test);
	assert(new -> next == NULL);
	assert(new -> prev == NULL);
	assert(new -> val == 21);
	assert(test.first == NULL);
	assert(test.last == NULL);
	assert(test.len == 0);
	assert(stack_free(&test) == 0);
	assert(element_free(new) == 1);
	printf("[OK] \n");
}

void	test_stack_pop_last_two(void)
{
	t_stack		test;
	t_element	*new;

	printf("test stack pop last with two element stack: ");
	test = create_stack_init_two_elements();
	new = stack_pop_last(&test);

	assert(new -> val == 22);
	assert(new -> next == NULL);
	assert(new -> prev == NULL);

	assert(test.first -> val == 21);
	assert(test.len == 1);
	assert(test.first == test.last);
	
	assert(stack_free(&test) == 1);
	assert(element_free(new) == 1);
	printf("[OK] \n");
}
