#ifndef SORT_H
# define SORT_H

# include <stddef.h>
# include "../stackmachine/machine.h"

// --- Makros ---

// --- prototypes ---

// ::: sorting :::

// sort_adaptive.c

void	sort_adaptive(t_stack_machine *machine);

// sort_complex.c

void	sort_complex(t_stack_machine *machine);

// sort_complex_mergesort_base.c

void	sort_pairs(t_stack_machine *machine);

void    split_stack(t_stack_machine *machine);

// sort_complex_mergesort.c

void	merge_sort(t_stack_machine *machine);
void	merge_level(t_stack_machine *machine);
void	merge(t_stack_machine *machine);
void	merge_to_a(t_stack_machine *machine);
void	merge_to_b(t_stack_machine *machine);

// sort_medium.c

void	sort_medium(t_stack_machine *machine);

// sort_simple.c

void	sort_simple(t_stack_machine *machine);

// sort_run.c

void	run_sort(t_stack_machine *machine, int flag);

// sort_benchmarks.c

void	print_bench(t_stack_machine *machine);

// sort_utilities.c

int		min_of(int a, int b);
int		max_of(int a, int b);

// --- end ---

#endif
