/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// sort_complex_mergesort_base.c

int		mergesort_sub_split_stack(
			t_stack_machine *machine);

int		mergesort_sub_sort_pairs(
			t_stack_machine *machine);

// sort_complex_mergesort_merge_to_side_x.c

void	mergesort_sub_merge_to_a(
			t_stack_machine *machine,
			int to_merge_in_a,
			int to_merge_in_b);

void	mergesort_sub_merge_to_b(
			t_stack_machine *machine,
			int to_merge_in_a,
			int to_merge_in_b);

// sort_complex_mergesort_efficientcy.c

void	mergesort_a_smaller_stack_more_efficient(
			t_stack_machine *machine);

// sort_complex_mergesort.c

void	merge_sort(
			t_stack_machine *machine);

// sort_medium.c

void	sort_medium(
			t_stack_machine *machine);

// sort_medium_bucketsort.c

void	bucket_sort_adaption(
			t_stack_machine *machine);

int		bucketsort_sub_push_and_sort_buckets(
			t_stack_machine *machine,
			int **bucket_map,
			int bucket_size);

int		bucketsort_sub_push_and_sort_rest(
			t_stack_machine *machine,
			int **bucket_map,
			int last_bucket_idx,
			int rest);

// sort_medium_bucketsort_efficieny.c

void	bucketsort_a_smaller_stack_more_efficient(
			t_stack_machine *machine,
			int **bucket_map);

// sort_medium_bucketsort_fill_bucket.c

void	bucketsort_sub_push_last_bucket_to_b(
			t_stack_machine *machine);

void	bucketsort_sub_push_bucket_to_b(
			t_stack_machine *machine,
			int **bucket_map,
			int bucket_i,
			int bucket_size);

// sort_medium_bucketsort_sort_bucket.c

void	bucketsort_sub_sort_bucket_descending_with_min_extraction(
			t_stack_machine *machine,
			int *pre_sorted_bucket,
			int len);

// sort_medium_bucketsort_sort_bucket_efficiency.c

void	bucketsort_sub_sub_sort_two_ascending_and_two_descending(
			t_stack_machine *machine);

void	bucketsort_sub_sub_sort_two_elements_descanding(
			t_stack_machine *machine);

void	bucketsort_sub_sub_sort_two_elements_ascanding(
			t_stack_machine *machine);

void	bucketsort_sub_sub_sort_three_elements_descanding(
			t_stack_machine *machine);

void	bucketsort_sub_sub_sort_three_elements_ascanding(
			t_stack_machine *machine);

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

int		anysort_sort_two(
			t_stack_machine *machine);

int		anysort_sort_three(
			t_stack_machine *machine);

// sort_utilities.c

int		int_min_of_two(
			int a,
			int b);

int		int_max_of_two(
			int a,
			int b);

// sort_anysort_utilities_execute_push_a_b.c

int		anysort_push_all_elements_to_stack_a(
			t_stack_machine *machine);

int		anysort_push_all_elements_to_stack_b(
			t_stack_machine *machine);

// sort_anysort_utilities_execute_rotation_a.c

int		anysort_sub_rotate_smallest_element_to_top_of_stack_a(
			t_stack_machine *machine);

int		anysort_sub_rotate_element_to_the_top_of_stack_a_by_idx(
			t_stack_machine *machine,
			int idx);

// sort_anysort_utilities_execute_rotation_b.c

int		anysort_sub_rotate_largest_element_to_top_of_stack_b(
			t_stack_machine *machine);

int		anysort_sub_rotate_element_to_the_top_of_stack_b_by_idx(
			t_stack_machine *machine,
			int idx);

// new file with anysort_*_b.c

void	anysort_sub_swap_second_and_third_b(
			t_stack_machine *machine);

void	anysort_sub_swap_second_and_third_then_second_and_first_b(
			t_stack_machine *machine);

void	anysort_sub_swap_second_and_first_then_second_and_third_b(
			t_stack_machine *machine);

void	anysort_sub_swap_first_and_second_b(
			t_stack_machine *machine);

void	anysort_sub_swap_first_and_third_b(
			t_stack_machine *machine);

// new file with anysort_*_a.c

void	anysort_sub_swap_second_and_third_a(
			t_stack_machine *machine);

void	anysort_sub_swap_second_and_third_then_second_and_first_a(
			t_stack_machine *machine);

void	anysort_sub_swap_second_and_first_then_second_and_third_a(
			t_stack_machine *machine);

void	anysort_sub_swap_first_and_second_a(
			t_stack_machine *machine);

void	anysort_sub_swap_first_and_third_a(
			t_stack_machine *machine);

// --- end ---

#endif
