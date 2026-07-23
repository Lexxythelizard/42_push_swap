#ifndef SORT_H
# define SORT_H

# include <stddef.h>
# include "../stackmachine/machine.h"

// --- Makros ---

// --- prototypes ---

// ::: sorting :::

// sort_adaptive.c

void	sort_adaptive(
			t_stack_machine *machine);

// sort_complex.c

void	sort_complex(
			t_stack_machine *machine);

void	test_merge_and_split(
			t_stack_machine *machine);

// sort_complex_mergesort_base.c

int		split_stack(
			t_stack_machine *machine);

int		sort_pairs(
			t_stack_machine *machine);

// sort_complex_mergesort_merge_to_side_x.c

void	merge_to_a(
			t_stack_machine *machine,
			int to_merge_in_a,
			int to_merge_in_b);

void	merge_to_b(
			t_stack_machine *machine,
			int to_merge_in_a,
			int to_merge_in_b);

// sort_complex_mergesort.c

void	merge_sort(
			t_stack_machine *machine);

void	merge_to(
			t_stack_machine *machine,
			int merge_to_size);

// sort_medium.c

void	sort_medium(
			t_stack_machine *machine);

// sort_medium_chunk.c

void	chunck_sort_adaption(
			t_stack_machine *machine);

// sort_simple.c

void	sort_simple(
			t_stack_machine *machine);

// sort_simple_min_extraction.c

int		min_extraction_adaption_sort(
			t_stack_machine *machine);

// sort_benchmarks.c

void	print_bench(
			t_stack_machine *machine);

// sort_utilities.c

int		int_min_of_two(
			int a,
			int b);

int		int_max_of_two(
			int a,
			int b);

// --- end ---

#endif
