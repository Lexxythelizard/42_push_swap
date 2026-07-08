/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_machine.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:55:43 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 20:44:43 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MACHINE_H
# define STACK_MACHINE_H

// --- include ---

# include <stdlib.h>
# include "./core/stack.h"
# include "./core/machine"
# include "./core/stack_track.h"

// --- makros ---

typedef struct s_stats
{
	unsigned int	calls[11];
	unsigned int	total_ops;
	float			disorder;
	char			*strategy;
}					t_stats;

typedef struct s_func
{
	void	(*f)(struct s_interface *c);
	char	*name;
}			t_func;

typedef struct s_interface
{
	t_stack	stacks[2];
	t_stats	*stats;
	t_func	funcs[11];	
}			t_interface;

// --- prototype ---

// disorder_metric.c

float		compute_disorder(t_stack_frame *a);

// machine_exec.c

void		exec(t_interface *stacks, int idx);
void		exec_n(t_interface *stacks, int idx, int n);

// machine_free.c

void		free_machine(t_stack_machine *machine);

// machine_init.c

int			machine_init_empty(t_stack_machine *machine);
int			machine_stack_init(t_stack_machine *machine, int *nums, int len);
void		func_init(t_stack_machine *machine);
void		stats_init(t_stack_machine *machine, int flag);
t_func		func_wrap(void (*f)(t_interface *), char *name);

// machine_operation_push.c

void		pa(t_stack_machine *machine);
void		pb(t_stack_machine *machine);

// machine_operation_rotate.c

void		ra(t_stack_machine *machine);
void		rb(t_stack_machine *machine);
void		rr(t_stack_machine *machine);

// machine_operation_reverse_rotate.c

void		rra(t_stack_machine *machine);
void		rrb(t_stack_machine *machine);
void		rrr(t_stack_machine *machine);

// machine_operation_swap.c

void		sa(t_stack_machine *machine);
void		sb(t_stack_machine *machine);
void		ss(t_stack_machine *machine);

// stack_manipulation.c

t_element	*new_element(int val, t_element *prev);
void		stack_init(t_stack *stack, int  *nums, size_t len);
void		stack_init_empty(t_stack *stack);
void		free_stack(t_stack *stack);

// stack_operation.c

void		swap(t_stack *c);
void		push(t_stack *c, t_stack *d);
void		rotate(t_stack *c);
void		reverse_rotate(t_stack *c);

// stack_scan.c

int			stack_comp(t_stack *stack);
int			get_stack_size(t_element *element);
int			get_min_geq_n(t_element *element, int n);
int			get_nth_min(t_element *element, int n);

// --- end ---

#endif
