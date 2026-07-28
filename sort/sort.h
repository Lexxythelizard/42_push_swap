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

// sort_medium_bucket.c

void	bucket_sort_adaption(
			t_stack_machine *machine);

int		push_and_sort_buckets(
			t_stack_machine *machine,
			int **bucket_map,
			int bucket_size);

int		push_and_sort_rest(
			t_stack_machine *machine,
			int rest);

// sort_medium_bucket_fill_bucket.c

void	push_last_bucket_to_b(
			t_stack_machine *machine);

void	push_bucket_to_b(
			t_stack_machine *machine,
			int **bucket_map,
			int bucket_i,
			int bucket_size);

// sort_medium_bucket_sort_bucket.c

void	bucket_insertion_sort_descending(
			t_stack_machine *machine,
			int len);

// sort_medium_bucketsort_utiliy.c

int		**get_pre_sorted_buckets_as_arrays(
			t_stack_machine *machine,
			int buckets,
			int rest);

int		**arr_arr_int_free(
			int **arr_arr_int);

float	get_sqrt(
			int x);

// sort_medium_bucketsort_utiliy_arr.c

int		*arr_int_get_presorted(
			t_stack_machine *machine);

// sort_medium_bucketsort_utiliy_arr_arr.c

int		**arr_arr_int_fill_buckets(
			int *pre_sorted_arr,
			int buckets,
			int rest);

// sort_simple.c

void	sort_simple(
			t_stack_machine *machine);

// sort_simple_min_extraction.c

int		min_extraction_adaption_sort(
			t_stack_machine *machine);

// sort_benchmarks.c

void	print_bench(
			t_stack_machine *machine);

// sort_small_stacks.c

int		sort_two(
			t_stack_machine *machine);

int		sort_three(
			t_stack_machine *machine);

// sort_utilities.c

int		int_min_of_two(
			int a,
			int b);

int		int_max_of_two(
			int a,
			int b);

// sort_utilities_execute_a.c

int		push_all_elements_to_stack_a(
			t_stack_machine *machine);

int		swap_second_and_third_a(
			t_stack_machine *machine);

int		swap_first_and_third_a(
			t_stack_machine *machine);

// sort_utilities_execute_b.c

int		push_all_elements_to_stack_b(
			t_stack_machine *machine);

int		swap_second_and_third_b(
			t_stack_machine *machine);

int		swap_first_and_third_b(
			t_stack_machine *machine);

// --- end ---

#endif
