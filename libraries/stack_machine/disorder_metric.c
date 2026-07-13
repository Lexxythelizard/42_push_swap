// --- include ---

#include "./stack_machine.h"

// --- DOC --

/*TODO: reimplement or toss out*/

// --- proto --- for tests

float	compute_disorder(t_stack *stack);

// --- define ---

float	compute_disorder(t_stack *stack)
{
	int			mistakes;
	int			total_pairs;
	t_element	*curr;
	t_element	*comp;

	mistakes = 0;
	total_pairs = 0;
	if (!stack)
		return (0.0);
	curr = stack -> first;
	while (curr != NULL)
	{
		comp = curr -> next;
		while (comp != NULL)
		{
			if (curr -> val > comp -> val)
				mistakes++;
			total_pairs++;
			comp = comp -> next;
		}
		curr = curr -> next;
	}
	return ((float)(total_pairs / mistakes));
}
