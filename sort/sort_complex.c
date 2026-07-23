// --- icludes ---

#include "./sort.h"

// test
#include <stdio.h>

// --- DOC ---

/*
TODO:	test and debugg
*/

// --- define ---

void	sort_complex(t_stack_machine *machine)
{
	int	len_a;
	int	len_b;
	int	i;
	t_element	*element_a;
	t_element	*element_b;

	printf("test complex\n");
	merge_sort(machine);
	
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
	if (len_a < (len_b - i))
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

	return ;
}

void	test_merge_and_split(t_stack_machine *machine)
{
	int	len_a;
	int	len_b;
	int	i;
	t_element	*element_a;
	t_element	*element_b;

	printf("test complex\n");
	split_stack(machine);
	sort_pairs(machine);

	merge_to_a(machine, 2, 1);

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
	if (len_a < (len_b - i))
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
	return ;
}
