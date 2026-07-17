// --- include ---

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "test_helper.h"

// --- proto ---

void	test_machine_init_empty(void);
void	test_machine_assign_by_flag(void);
void	test_machine_assign_by_entro(void);

// --- run ---

int	main(void)
{
	printf("run test machine basic manipulation:\n\n");
	test_machine_init_empty();
	test_machine_assign_by_flag();
	test_machine_assign_by_entro();
	printf("\nall passed\n");
	return (0);
}

// --- define ---

void	test_machine_init_empty(void)
{
	t_stack_machine	test;
	int				i;

	printf("test machine init empty: ");
	i = 0;
	test = create_machine_init_empty();
	assert(test.stacks[0].len == 0);
	assert(test.stacks[0].first == NULL);
	assert(test.stacks[0].last == NULL);
	assert(test.stacks[1].len == 0);
	assert(test.stacks[1].first == NULL);
	assert(test.stacks[1].last == NULL);
	while (i++ < OPS_N)
	{
		assert(test.funcs[(i - 1)].name == NULL);
		assert(test.funcs[(i - 1)].func == NULL);
	}
	i = 0;
	while (i++ < OPS_N)
		assert(test.stats.calls[(i - 1)] == 0);
	assert(test.stats.entropy == 0.0);
	assert(test.stats.strategy == NULL);
	assert(machine_free(NULL) == (-1));
	assert(machine_free(&test) == 0);
	printf("[OK] \n");
}

// TODO: test machine_free...

void	test_machine_assign_by_flag(void)
{
	t_stats	test;

	printf("test assign by flag: ");



	printf("[Implement] \n");
}

void	test_machine_assign_by_entro(void)
{
	t_stats	test;
	printf("test assign by entropy: ");



	printf("[Implement] \n");
}
