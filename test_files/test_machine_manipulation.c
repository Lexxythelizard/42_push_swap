// --- include ---

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "test_helper.h"

// --- proto ---

void	test_machine_init_empty(void);
void	test_machine_assign_by_flag(void);
void	test_machine_assign_by_entro(void);
void	test_machine_asign_stack(void);
void	test_machine_assign_func(void);

// --- run ---

int	main(void)
{
	printf("run test machine basic manipulation:\n\n");
	test_machine_init_empty();
	test_machine_assign_by_flag();
	test_machine_assign_by_entro();
	test_machine_asign_stack();
	test_machine_assign_func();
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

void	test_machine_assign_entro(void)
{
	t_stack_machine	test;

	printf("test assign entropy: ");

	test = create_machine_init_empty();
	assert(machine_assign_entropy(NULL, 0) == (-1));
	assert(machine_assign_entropy(&test, (-0.23)) == (-1));
	assert(machine_assign_entropy(&test, 1.01) == (-1));
	assert(machine_assign_entropy(&test, 0.0) == 1);
	assert(machine_assign_entropy(&test, (float)(0.23)) == 1);
	assert(test.stats.entropy == (float)(0.23));

	printf("[OK] \n");
}

void	test_machine_assign_by_flag(void)
{
	t_stack_machine	test;

	printf("test assign by flag: ");

	test = create_machine_init_empty();
	assert(machine_assign_strategy(NULL, 0) == (-1));
	assert(machine_assign_strategy(&test, 0) == 0);
	assert(test.stats.strategy == NULL);
	assert(machine_assign_strategy(&test, 0) == 0);
	assert(test.stats.strategy == NULL);
	assert(machine_assign_strategy(&test, 16) == 0);
	assert(test.stats.strategy == NULL);
	assert(machine_assign_strategy(&test, 20) == 4);
	assert(strncmp(test.stats.strategy, COMPLEX_STR, 15) == 0);
	assert(machine_assign_strategy(&test, 4) == 4);
	assert(strncmp(test.stats.strategy, COMPLEX_STR, 15) == 0);
	assert(machine_assign_strategy(&test, 18) == 2);
	assert(strncmp(test.stats.strategy, MEDIUM_STR, 15) == 0);
	assert(machine_assign_strategy(&test, 2) == 2);
	assert(strncmp(test.stats.strategy, MEDIUM_STR, 15) == 0);
	assert(machine_assign_strategy(&test, 17) == 1);
	assert(strncmp(test.stats.strategy, SIMPLE_STR, 15) == 0);
	assert(machine_assign_strategy(&test, 1) == 1);
	assert(strncmp(test.stats.strategy, SIMPLE_STR, 15) == 0);
	assert(machine_assign_entropy(&test, 0.23f) == 1);
	assert(test.stats.entropy == 0.23f);
	assert(machine_assign_entropy(&test, (float)(23 / 100)) == 1);
	assert(test.stats.entropy == (float)(23/ 100));
	assert(machine_assign_entropy(&test, (float)(73 / 100)) == 1);
	assert(test.stats.entropy == (float)(73 / 100));
	assert(machine_assign_entropy(&test, 0.73f) == 1);
	assert(test.stats.entropy == 0.73f);

	assert(0.0 == 0);	
	assert((float)(0) == 0);
	assert(0.0f == 0);

	printf("[OK] \n");
}

void	test_machine_assign_by_entro(void)
{
	t_stack_machine	test;
	printf("test assign by entropy: ");

	test = create_machine_init_empty();
	assert(machine_assign_strategy(NULL, 0) == (-1));
	assert(machine_assign_strategy(&test, 0) == 0);
	assert(machine_assign_entropy(&test, 0.19f) == 1);
	assert(machine_assign_strategy(&test, 24) == 1);
	assert(strncmp(test.stats.strategy, SIMPLE_STR, 15) == 0);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, (float)(19) / (float)(100)) == 1);
	assert(machine_assign_strategy(&test, 8) == 1);
	assert(strncmp(test.stats.strategy, SIMPLE_STR, 15) == 0);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, (float)(19.999) / (float)(100)) == 1);
	assert(machine_assign_strategy(&test, 8) == 1);
	assert(strncmp(test.stats.strategy, SIMPLE_STR, 15) == 0);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, (float)(20) /(100)) == 1);
	assert(machine_assign_strategy(&test, 8) == 2);
	assert(strncmp(test.stats.strategy, MEDIUM_STR, 15) == 0);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, 0.20f) == 1);
	assert(machine_assign_strategy(&test, 8) == 2);
	assert(strncmp(test.stats.strategy, MEDIUM_STR, 15) == 0);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, (float)(49.999) / (100)) == 1);
	assert(machine_assign_strategy(&test, 8) == 2);
	assert(strncmp(test.stats.strategy, MEDIUM_STR, 15) == 0);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, 0.50f) == 1);
	assert(machine_assign_strategy(&test, 8) == 4);
	assert(strncmp(test.stats.strategy, COMPLEX_STR, 15) == 0);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, (float)(51) / (100)) == 1);
	assert(machine_assign_strategy(&test, 8) == 4);
	assert(strncmp(test.stats.strategy, COMPLEX_STR, 15) == 0);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, 0.99f) == 1);
	assert(machine_assign_strategy(&test, 8) == 4);
	assert(strncmp(test.stats.strategy, COMPLEX_STR, 15) == 0);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, 0 == 1));
	assert(machine_assign_strategy(&test, 8) == 0);
	assert(test.stats.strategy == NULL);
	machine_init_new_empty(&test);
	assert(machine_assign_entropy(&test, (float)(0 / 100)) == 1);
	assert(machine_assign_strategy(&test, 8) == 0);
	assert(test.stats.strategy == NULL);

	printf("[OK] \n");
}

void	test_machine_asign_stack(void)
{
	t_stack_machine	test;

	printf("test assign stack: ");

	test = create_machine_init_empty();
	assert(machine_free(&test) == 0);

	test = create_machine_init_one_elements();
	assert(test.stacks[0].len == 1);
	assert(test.stacks[0].first -> val == 21);
	assert(test.stacks[0].last -> val == 21);
	assert(test.stacks[0].last == test.stacks[0].last);
	assert(test.stacks[1].len == 0);
	assert(test.stacks[1].first == NULL);
	assert(test.stacks[1].last == NULL);
	assert(machine_free(&test) == 1);

	test = create_machine_init_two_elements();
	assert(test.stacks[0].len == 2);
	assert(test.stacks[0].first -> val == 21);
	assert(test.stacks[0].last -> val == 22);
	assert(test.stacks[0].first -> next == test.stacks[0].last);
	assert(test.stacks[1].len == 0);
	assert(test.stacks[1].first == NULL);
	assert(test.stacks[1].last == NULL);
	assert(machine_free(&test) == 2);

	test = create_machine_init_three_elements();
	assert(test.stacks[0].len == 3);
	assert(test.stacks[0].first -> val == 21);
	assert(test.stacks[0].first -> next -> val == 22);
	assert(test.stacks[0].last -> val == 23);
	assert(test.stacks[0].first -> next == test.stacks[0].last -> prev);
	assert(test.stacks[1].len == 0);
	assert(test.stacks[1].first == NULL);
	assert(test.stacks[1].last == NULL);
	assert(machine_free(&test) == 3);

	printf("[OK] \n");
}

void	test_machine_assign_func(void)
{
	t_stack_machine	test;

	printf("test assign func: ");

	test = create_machine_init_empty();
	machine_func_assign(&test);
	assert(strncmp(test.funcs[SA].name, SA_STR, 4) == 0);
	assert(strncmp(test.funcs[SB].name, SB_STR, 4) == 0);
	assert(strncmp(test.funcs[SS].name, SS_STR, 4) == 0);
	assert(strncmp(test.funcs[PA].name, PA_STR, 4) == 0);
	assert(strncmp(test.funcs[PB].name, PB_STR, 4) == 0);
	assert(strncmp(test.funcs[RA].name, RA_STR, 4) == 0);
	assert(strncmp(test.funcs[RB].name, RB_STR, 4) == 0);
	assert(strncmp(test.funcs[RR].name, RR_STR, 4) == 0);
	assert(strncmp(test.funcs[RRA].name, RRA_STR, 4) == 0);
	assert(strncmp(test.funcs[RRB].name, RRB_STR, 4) == 0);
	assert(strncmp(test.funcs[RRR].name, RRR_STR, 4) == 0);
	assert(machine_free(&test) == 0);

	printf("[OK] \n");
}
