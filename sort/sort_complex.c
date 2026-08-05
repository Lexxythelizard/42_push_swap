/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 2026/08/05 19:33:10 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./sort.h"

// --- DOC ---

/*
TODO:	write comments
*/

//static void print_stacks(t_stack_machine *machine);

// --- define ---

void	sort_complex(t_stack_machine *machine)
{
    // for testing
    int len;

    len = machine -> stacks[0].len;
    if (len == 3)
        return ((void)(anysort_sort_three(machine)));
    if (len == 4)
        return ((void)(anysort_sort_four(machine)));
    if (len == 5)
		return ((void)(anysort_sort_five(machine)));
    // test end
	merge_sort(machine);
	return ;
}

// --- for testing ---
/*
static void print_stacks(t_stack_machine *machine)
{
	int	len_a;
	int	len_b;
	int	i;
	t_element	*element_a;
	t_element	*element_b;

	i = 0;

	len_a = machine -> stacks[0].len;
	len_b = machine -> stacks[1].len;

	element_a = machine -> stacks[0].first;
	element_b = machine -> stacks[1].first;

	printf("stacks: len a: %d\tlen b: %d\n", len_a, len_b);
	while ((len_a - i) > len_b)
	{
		printf("%d\t\t\n", element_a -> val);
		element_a = element_a -> next;
		i++;
	}
	while ((len_b - i) > len_a)
	{
		printf("\t\t%d\n", element_b -> val);
		element_b = element_b -> next;
		i++;
	}
	while ((element_a) && (element_b))
	{
		printf("%d\t\t%d\n", element_a -> val, element_b -> val);
		element_a = element_a -> next;
		element_b = element_b -> next;
	}
	printf("-----------------------------\n");
	printf("a\t\tb\n");
}
*/
