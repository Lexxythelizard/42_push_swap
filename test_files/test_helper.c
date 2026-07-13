// --- icludes ---

#include <[statlib].h>

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

void	func0(void);
void	func0(void);
void	func0(void);
void	func0(void);
void	func0(void);

// --- define ---

t_element	*test_new_element_empty(void)
{
	return (new_element(161, NULL));
}

void	test_free_element(t_element *element)
{
	free_element(element);
}

void	test_free_element_tail(t_element *element)
{
	free_element_tail(element);
}

t_element	*test_new_element_add_back(void)
{
	return (new_element(1337, ));
}

t_stack	test_stack_init_empty(void)
{
	t_stack	new_stack;

	stack_init_empty(&new_stack);
	return (new_stack);
}
