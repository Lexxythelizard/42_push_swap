#ifndef STACK_H
# define STACK_H

// --- include ---

# include <stdlib.h>

// --- struct ---

typedef struct s_stack_node {
	int					val;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_element;

typedef struct s_stack {
	int			len;
	t_element	*first;
	t_element	*last;
}				t_stack;

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

// stack_pop_add.c

t_element	*stack_pop_first(t_stack *stack);
t_element	*stack_pop_last(t_stack *stack);
int			stack_add_first(t_stack *stack, t_element *new);
int			stack_add_last(t_stack *stack, t_element *new);
int			stack_init_add(t_stack *stack, t_element *new);

// stack_operation.c

int			swap(t_stack *stack);
int			push(t_stack *from, t_stack *to);
int			rotate(t_stack *stack);
int			reverse_rotate(t_stack *stack);

// --- end ---

#endif
