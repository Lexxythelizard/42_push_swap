#ifndef TEST_HELPER_H
# define TEST_HELPER_H

// --- include ---

#include <stdio.h>
#include <assert.h>
#include "../libraries/stack_machine/core/stack.h"

// --- DOC ---

// --- Makros ---

// --- prototype ---

// test_helper_stack.c

t_element	*create_element_one(void);
t_element	*create_element_two(void);
t_element	*create_element_list(void);
t_stack		create_stack_init_empty(void);
t_stack		create_stack_init_one_elements(void);
t_stack		create_stack_init_two_elements(void);
t_stack		create_stack_init_three_elements(void);
t_stack		create_stack_init(void);
int			create_stack_free(t_stack *stack);

// test_helper_operations.c

// --- end ---

#endif
