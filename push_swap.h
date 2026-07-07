/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:55:43 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/07 17:15:01 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// --- include ---

# include "./stack.h"
# include "./stack_track.h"
# include "./ui_cli.h"

// --- makros ---

# define SIMPLE "(O(n²))"
# define MEDIUM "(O(n√n\u0305)"
# define COMPLEX "(O(n*log(n)))"

// --- prototypes ---

struct	s_interface;
struct	s_func;
struct	s_stats;

// --- structs ---

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

// cleanup.c

void			free_stack(t_stack *stack);
void			free_interface(t_interface *c);

// disorder_metric.c

float			compute_disorder(t_stack_frame *a);

// exec.c

void			exec(t_interface *stacks, int idx);
void			exec_n(t_interface *stacks, int idx, int n);

// interface.c

t_interface		*init(const char **argv);
void			stacks_init(t_interface *c, int *nums, int len);
void			func_init(t_interface *c);
void			stats_init(t_interface *c, int flag);
t_func			func_wrap(void (*f)(t_interface *), char *name);

// interface_push.c

void			pa(t_interface *c);
void			pb(t_interface *c);

// interface_rotate.c

void			ra(t_interface *c);
void			rb(t_interface *c);
void			rr(t_interface *c);

// interface_rrotate.c

void			rra(t_interface *c);
void			rrb(t_interface *c);
void			rrr(t_interface *c);

// interface_swap.c

void			sa(t_interface *c);
void			sb(t_interface *c);
void			ss(t_interface *c);

// output.c

void			print_bench(t_stats *stats);

// scan_stack_1.c

int				stack_comp(t_stack *stack);
int				get_stack_size(t_stack_frame *stack);
int				get_min_geq_n(t_stack_frame *stack, int n);
int				get_nth_min(t_stack *stack, int n);
int				get_nth_min_idx(t_stack *stack, int n);

// sort_complex_base.c

void			sort_pairs(t_interface *stacks, t_stack_track *st_tr);
void			split_stack(
					t_interface *stacks, t_stack_track *st_tr, int size);
t_stack_track	*init_stack_track(void);

// sort_complex.c

void			merge_sort(t_interface stacks);
void			merge_level(t_interface stacks, t_stack_track *st_tr);
void			merge(t_interface stacks, t_stack_track *st_tr);
void			merge_to_a(t_interface stacks, t_stack_track *st_tr);
void			merge_to_b(t_interface stacks, t_stack_track *st_tr);

// sort_medium.c

void			sort_medium(t_interface *stacks);
void			sort_bucket(t_stack_frame stack, int bs);
int				ft_sqrt(int nb);

// sort_simple_0.c

int				sort_simple(t_interface *stacks);

// sort_run.c

void			run_sort(t_interface *stacks, int flag);

// stack.c

void			stack_init(t_stack *stack, int *nums, size_t len);
void			s(t_stack *c);
void			p(t_stack *c, t_stack *d);
void			r(t_stack *c);
void			rr_(t_stack *c);

// ui_cli.c

int				*get_int_list(const char **argv);
int				get_flag_values(const char **argv);
int				get_flag_value(const char *flag);
int				count_numbers(const char **argv);

// utillities.c

int				min_of(int a, int b); 
int				max_of(int a, int b); 
int				is_numbers_unique_simple(int *list, int len);

// validation.c

int				is_numbers_unique(int *list, int len);
int				is_numbers_unique(int *list, int len);
int				is_valid_nbr(const char *s);
int				is_valid_flag(const char *s);
int				is_flag(const char *s);

// --- end ---

#endif
