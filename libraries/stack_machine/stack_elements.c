
// --- include ---

#include "./stack_machine.h"

// --- DOC --

/*TODO: test functions*/

// --- proto --- for tests

t_element	*element_new(int val, t_element *prev);
t_element	*element_new_list(int *arr, int len);
int			element_free(t_element *element);
int			element_free_tail(t_element *element);

// --- define ---

t_element	*element_new(int val, t_element *prev)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new -> val = val;
	new -> prev = prev;
	new -> next = NULL;
	return (new);
}

t_element	*element_new_list(int *arr, int len)
{
	int			i;
	t_element	*next;

	if ((!arr) || (len <= 0))
		return (NULL);
	i = 1;
	next = NULL;
	first = new_element(arr[0], NULL);
	if (!first)
		return (NULL);
	while (i < len)
	{
		next = new_element(arr[i], next);
		if (!next)
			element_free_tail(first);
		i++;
	}
	return (first);
}

int	element_free(t_element *element)
{
	if (element)
	{
		element -> next = NULL;
		element -> prev = NULL;
		free(element);
		return (1);
	}
	return (0);
}

int	element_free_tail(t_element *element)
{
	t_element	*ptr;
	int			count;

	ptr = NULL;
	count = 0;
	while (element)
	{
		ptr = element -> next;
		count += free_element(element);
		element = ptr;
	}
	return (count);
}
