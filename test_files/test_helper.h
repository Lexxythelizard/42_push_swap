#ifndef TEST_HELPER_H
# define TEST_HELPER_H

// --- include ---

#include <stdio.h>
#include <assert.h>
#include "../stackmachine/stack/stack.h"
#include "../stackmachine/stats/stats.h"
#include "../stackmachine/funcs/funcs.h"
#include "../stackmachine/machine.h"

// --- DOC ---

// --- Makros ---

// --- prototype ---

// test_helper_stack.c

t_element		*create_element_one(void);
t_element		*create_element_two(void);
t_element		*create_element_list(void);
t_stack			create_stack_init_empty(void);
t_stack			create_stack_init_one_elements(void);
t_stack			create_stack_init_two_elements(void);
t_stack			create_stack_init_three_elements(void);
t_stack			create_stack_init(void);
int				create_stack_free(t_stack *stack);

t_stats			create_stats_init_empty(void);

t_func			create_funcs_init_empty(void);

t_stack_machine	create_machine_init_empty(void);
t_stack_machine	create_machine_init_one_elements(void);
t_stack_machine	create_machine_init_two_elements(void);
t_stack_machine	create_machine_init_three_elements(void);

// --- end ---

#endif
