// --- include ---

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "test_helper.h"

// --- proto ---

void	test_stack_init_empty(void);
void	test_stack_assign_by_flag(void);
void	test_stack_assign_by_entro(void);

// --- run ---

int	main(void)
{
	printf("run test stacks:\n\n");
	test_stack_init_empty();
	test_stack_assign_by_flag();
	test_stack_assign_by_entro();
	printf("\nall passed\n");
	return (0);
}

// --- define ---

void	test_stack_init_empty(void)
{
	t_stats	test;
	int		i;

	printf("test stack init empty: ");
	i = 0;
	test = create_stats_init_empty();
	assert(test.strategy == NULL);
	assert(test.entropy == 0.0);
	assert(test.total_ops == 0);
	while (i++ < OPS_N)
		assert(test.calls[(i - 1)] == 0);
	printf("[OK] \n");
}

void	test_stack_assign_by_flag(void)
{
	t_stats	test;

	printf("test assign by flag: ");
	test = create_stats_init_empty();
	assert(stats_assign_strategy_by_flag(&test, 0) == 0);
	assert(test.strategy == NULL);
	stats_init_empty(&test);
	assert(stats_assign_strategy_by_flag(&test, 16) == 0);
	assert(test.strategy == NULL);
	stats_init_empty(&test);
	assert(stats_assign_strategy_by_flag(&test, 1) == 1);
	assert(strncmp(test.strategy, SIMPLE_STR, 15) == 0);
	stats_init_empty(&test);
	assert(stats_assign_strategy_by_flag(&test, 17) == 1);
	assert(strncmp(test.strategy, SIMPLE_STR, 15) == 0);
	stats_init_empty(&test);
	assert(stats_assign_strategy_by_flag(&test, 18) == 2);
	assert(strncmp(test.strategy, MEDIUM_STR, 15) == 0);
	stats_init_empty(&test);
	assert(stats_assign_strategy_by_flag(&test, 20) == 4);
	assert(strncmp(test.strategy, COMPLEX_STR, 15) == 0);
	stats_init_empty(&test);
	assert(stats_assign_strategy_by_flag(&test, 4) == 4);
	assert(strncmp(test.strategy, COMPLEX_STR, 15) == 0);
	stats_init_empty(&test);
	assert(stats_assign_strategy_by_flag(&test, 8) == 8);
	assert(strncmp(test.strategy, ADAPTIVE_STR, 15) == 0);
	stats_init_empty(&test);
	assert(stats_assign_strategy_by_flag(&test, 24) == 8);
	assert(strncmp(test.strategy, ADAPTIVE_STR, 15) == 0);
	stats_init_empty(&test);
	printf("[OK] \n");
}

void	test_stack_assign_by_entro(void)
{
	t_stats	test;
	printf("test assign by entropy: ");
	test = create_stats_init_empty();
	test.entropy = 0.0;
	assert(stats_assign_strategy_by_entropy(&test) == 0);
	assert(test.strategy == NULL);
	stats_init_empty(&test);

	test.entropy = 0.001;
	assert(stats_assign_strategy_by_entropy(&test) == 1);
	assert(strncmp(test.strategy, SIMPLE_STR, 15) == 0);
	stats_init_empty(&test);

	test.entropy = 0.1;
	assert(stats_assign_strategy_by_entropy(&test) == 1);
	assert(strncmp(test.strategy, SIMPLE_STR, 15) == 0);
	stats_init_empty(&test);

	test.entropy = 0.19;
	assert(stats_assign_strategy_by_entropy(&test) == 1);
	assert(strncmp(test.strategy, SIMPLE_STR, 15) == 0);
	stats_init_empty(&test);

	test.entropy = 0.2;
	assert(stats_assign_strategy_by_entropy(&test) == 2);
	assert(strncmp(test.strategy, MEDIUM_STR, 15) == 0);
	stats_init_empty(&test);

	test.entropy = 0.23;
	assert(stats_assign_strategy_by_entropy(&test) == 2);
	assert(strncmp(test.strategy, MEDIUM_STR, 15) == 0);
	stats_init_empty(&test);

	test.entropy = 0.49;
	assert(stats_assign_strategy_by_entropy(&test) == 2);
	assert(strncmp(test.strategy, MEDIUM_STR, 15) == 0);
	stats_init_empty(&test);

	test.entropy = 0.5;
	assert(stats_assign_strategy_by_entropy(&test) == 4);
	assert(strncmp(test.strategy, COMPLEX_STR, 15) == 0);
	stats_init_empty(&test);

	test.entropy = 1;
	assert(stats_assign_strategy_by_entropy(&test) == 4);
	assert(strncmp(test.strategy, COMPLEX_STR, 15) == 0);
	stats_init_empty(&test);

	printf("[OK] \n");
}
