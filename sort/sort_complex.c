// --- icludes ---

#include "./sort.h"

// test
#include <stdio.h>

// --- DOC ---

/*
TODO:	implement from scratch
*/

// --- define ---

void	sort_complex(t_stack_machine *machine)
{
	int	len_a;
	int	len_b;
	t_element	*element_a;
	t_element	*element_b;

	printf("test complex\n");
	merge_sort(machine);
	
	len_a = machine -> stacks[0].len;
	len_b = machine -> stacks[1].len;
	
	element_a = machine -> stacks[0].first;
	element_b = machine -> stacks[1].first;
	
	printf("stacks: len a: %d\tlen b: %d\n", len_a, len_b);
	if (len_a > len_b)
	{
		printf("%d\t\t\n", element_a -> val);
		element_a = element_a -> next;
	}
	if (len_a < len_b)
	{
		printf("\t\t%d\n", element_b -> val);
		element_b = element_b -> next;
	}
	while ((element_a) && (element_b))
	{
		printf("%d\t\t%d\n", element_a -> val, element_b -> val);
		element_a = element_a -> next;
		element_b = element_b -> next;
	}
	printf("------------\n");
	printf("a\t\tb\n");
	return ;
}
