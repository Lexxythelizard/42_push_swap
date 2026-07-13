#ifndef STACKMACHINE_H
# define STACKMACHINE_H

// --- include ---

# include <stdlib.h>
# include "./core/stack.h"
# include "./core/machine.h"
# include "./core/stack_track.h"

// --- prototype ---

// stack_elements.c

t_element	*element_new(int val);
t_element	*element_add_next(t_element *prev, t_element *new);
t_element	*element_new_list(int *arr, int len);
int			element_free(t_element *element);
int			element_free_tail(t_element *element);

// stack_stack.c

int			stack_init_empty(t_stack *stack);
int			stack_init(t_stack *stack, int *arr, int len);
int			stack_free(t_stack *stack);

// --- end ---

#endif
