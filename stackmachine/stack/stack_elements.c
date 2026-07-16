// --- include ---

#include "./stack.h"

// --- DOC --

/*
	This file contains all basic t_element functions
*/

// --- proto --- for tests

t_element	*element_new(int val);
t_element	*element_add_next(t_element *prev, t_element *new);
t_element	*element_new_list(int *arr, int len);
int			element_free(t_element *element);
int			element_free_tail(t_element *element);

// --- define ---

/*
returns a pointer to an allocated node (element)
*/

t_element	*element_new(int val)
{
	t_element	*new;

	new = malloc(sizeof(t_element));
	if (!new)
		return (NULL);
	new -> val = val;
	new -> prev = NULL;
	new -> next = NULL;
	return (new);
}

/*
adds a single node *new as next to prev
returns a pointer to (new) last element
*/

t_element	*element_add_next(t_element *prev, t_element *new)
{
	if (!prev)
		return (NULL);
	new -> prev = prev;
	new -> next = NULL;
	prev -> next = new;
	return (prev -> next);
}

/*
takes an array of int incl length and creates a list
deletes list, if allocation fails and returns NULL
returns Pointer to first element
*/

t_element	*element_new_list(int *arr, int len)
{
	int			i;
	t_element	*first;
	t_element	*last;
	t_element	*new;

	if ((!arr) || (len <= 0))
		return (NULL);
	i = 1;
	first = element_new(arr[0]);
	last = first;
	if (!first)
		return (NULL);
	while (i < len)
	{
		new = element_new(arr[i]);
		last = element_add_next(last, new);
		if (!new)
		{
			element_free_tail(first);
			return (NULL);
		}
		i++;
	}
	return (first);
}

/*
takes one element and set its members to NULL before freeing it
returns 1 if succes and 0 if not
*/

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

/*
casts element_free on element and all of its next elements
returns number of frees as int
*/

int	element_free_tail(t_element *element)
{
	t_element	*ptr;
	int			count;

	ptr = NULL;
	count = 0;
	while (element)
	{
		ptr = element -> next;
		count += element_free(element);
		element = ptr;
	}
	return (count);
}
