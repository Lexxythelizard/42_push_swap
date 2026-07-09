/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:14:04 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/09 14:00:12 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

// --- Makros ---

# define FLAG_NULL     "--"
# define FLAG_BENCH     "--bench"
# define FLAG_SIMPLE    "--simple"
# define FLAG_MEDIUM    "--medium"
# define FLAG_COMPLEX   "--complex"
# define FLAG_ADAPTIVE  "--adaptive"

// --- prototypes ---

// ::: sorting :::

// sort_complex_base.c

void    sort_pairs(
			t_interface *stacks,
			t_stack_track *st_tr);

void    		split_stack(
					t_interface *stacks,
					t_stack_track *st_tr,
					int size);

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

// sort_simple.c

int				sort_simple(t_interface *stacks);

// sort_run.c

void			run_sort(t_interface *stacks, int flag);

// ::: UI :::

// ui_convert_arguments.c

int				*get_int_list(const char **argv);
int				get_flag_values(const char **argv);
int				get_flag_value(const char *flag);
int				count_numbers(const char **argv);

// ui_validate_arguments.c

int				is_numbers_unique(int *list, int len);
int				is_args_valid(const char **argv);
int				is_valid_nbr(const char *s);
int				is_valid_flag(const char *s);
int				is_flag(const char *s);

// ui_output.c

void			print_bench(t_stats *stats);

// ::: utilities :::

// utilities.c

int				min_of(int a, int b);
int				max_of(int a, int b);
int				is_numbers_unique_simple(int *list, int len);

// --- end ---

#endif
