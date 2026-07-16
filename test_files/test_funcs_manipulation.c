// --- include ---

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "test_helper.h"

// --- proto ---

void	test_funcs_init_empty(void);

// --- run ---

int	main(void)
{
	printf("run test funcss:\n\n");
	test_funcs_init_empty();
	printf("\nall passed\n");
	return (0);
}

// --- define ---

void	test_funcs_init_empty(void)
{
	t_func	test;

	printf("test funcs init empty: ");
	test = create_funcs_init_empty();
	assert(test.name == NULL);
	assert(test.func == NULL);
	assert(func_init_empty(NULL) == (-1));
	assert(func_init_empty(&test) == 0);
	assert(func_init(NULL, NULL, NULL) == (-1));
	assert(func_init(&test, NULL, NULL) == 0);
	printf("[OK] \n");
}
