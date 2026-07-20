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
# include "./stackmachine/machine.h"
# include "./ui/ui.h"

// --- Makros ---

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

// sort_utilities.c

int				min_of(int a, int b);
int				max_of(int a, int b);

// --- end ---

#endif
