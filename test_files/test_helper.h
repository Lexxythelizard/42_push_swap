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

// ../libraries/stack_machine/stack_elements.c

t_element   *element_new(int val);
t_element   *element_add_next(t_element *prev, t_element *new);
t_element   *element_new_list(int *arr, int len);
int         element_free(t_element *element);
int         element_free_tail(t_element *element);

// ../libraries/stack_machine/stack_stack.c

int			stack_init_empty(t_stack *stack);
int			stack_init(t_stack *stack, int *arr, int len);
int			stack_free(t_stack *stack);

// ../libraries/stack_machine/stack_stack.c

t_element   *stack_pop_first(t_stack *stack);
t_element   *stack_pop_last(t_stack *stack);
int         stack_add_first(t_stack *stack, t_element *new);
int         stack_add_last(t_stack *stack, t_element *new);
int         stack_init_add(t_stack *stack, t_element *new);

// --- end ---

#endif
