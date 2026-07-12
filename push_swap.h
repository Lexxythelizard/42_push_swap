/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:14:04 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/09 15:56:31 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
#include "./libraries/stack_machine/stack_machine.h"

// --- Makros ---

# define FLAG_NULL     "--"
# define FLAG_BENCH     "--bench"
# define FLAG_SIMPLE    "--simple"
# define FLAG_MEDIUM    "--medium"
# define FLAG_COMPLEX   "--complex"
# define FLAG_ADAPTIVE  "--adaptive"

// --- prototypes ---



// ::: sorting :::

// sort_adaptive.c

void			sort_adaptive(t_stack_machine *machine);

// sort_complex.c

void			sort_complex(t_stack_machine *machine);

// sort_complex_mergesort_base.c

void			sort_pairs(
					t_stack_machine *machine,
					t_stack_track *st_tr);

void    		split_stack(
					t_stack_machine *machine,
					t_stack_track *st_tr,
					int size);

t_stack_track	*init_stack_track(void);

// sort_complex_mergesort.c

void			merge_sort(t_stack_machine *machine);
void			merge_level(t_stack_machine *machine, t_stack_track *st_tr);
void			merge(t_stack_machine *machine, t_stack_track *st_tr);
void			merge_to_a(t_stack_machine *machine, t_stack_track *st_tr);
void			merge_to_b(t_stack_machine *machine, t_stack_track *st_tr);

// sort_medium.c

void			sort_medium(t_stack_machine *machine);
void			sort_bucket(t_stack_machine *machine, int bs, int side);
int				ft_sqrt(int nb);

// sort_simple.c

int				sort_simple(t_stack_machine *machine);

// sort_run.c

void			run_sort(t_stack_machine *machine, int flag);

// ::: UI :::

// ui_calculate_entropy.c

float			calculate_entropy(int *arr, int len);

// ui_convert_arguments.c

int				*get_int_list(const char **argv, int argc);
int				count_valid_numbers(const char **argv, int argc);
int				get_flag_values(const char **argv, int argc);
int				get_flag_value(const char *flag);

// ui_validate_arguments.c

int				is_args_valid(const char **argv, int argc);

// ui_validate_arguments_numbers.c

int				is_numbers_unique(int *list, int len);
int				is_valid_nbr(const char *s);

// ui_validate_arguments_flags.c

int				is_valid_flag(const char *s);
int				count_repitition_of_flags(const char **argv, int argc);
int				is_unique_and_one_bench(const char **argv, int argc);
int				is_any_flag(const char *s);

// ui_output.c

void			print_bench(t_stats *stats);

// ::: utilities :::

// utilities.c

int				min_of(int a, int b);
int				max_of(int a, int b);

// --- end ---

#endif
