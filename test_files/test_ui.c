// --- include ---

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "test_helper.h"

// --- proto ---

void	test_args_validation_and_counting(void);

// --- run ---

int	main(void)
{
	printf("run test machine operations:\n\n");
	test_args_validation_and_counting();
	printf("\n\t...actually they should be fine\n");
	return (0);
}

// --- define ---

void	test_args_validation_and_counting(void)
{
	const char	*argv0[] = {"push_swap", "1", "2", "3", NULL};
	const char	*argv1[] = {"push_swap", "3", "2", "1", NULL};
	const char	*argv2[] = {"push_swap", "--bench", "1", "2", "3", NULL};
	const char	*argv3[] = {"push_swap", "--simple", "1", "2", "3", NULL};
	const char	*argv4[] = {"push_swap", "1", "--simple", "2", "3", NULL};
	const char	*argv5[] = {"push_swap", "--bench", "--simple", "2", "3", NULL};
	const char	*argv6[] = {"push_swap", "--bench", "--simple", NULL};
	const char	*argv7[] = {"push_swap", "--simple", "--complex", "1", NULL};
	const char	*argv8[] = {"push_swap", "5", NULL};
	const char	*argv9[] = {"push_swap", NULL};
	int			argc0 = 4;
	int			argc1 = 4;
	int			argc2 = 5;
	int			argc3 = 5;
	int			argc4 = 5;
	int			argc5 = 5;
	int			argc6 = 3;
	int			argc7 = 4;
	int			argc8 = 2;
	int			argc9 = 1;

	printf("test: arg validation and counting");
	assert(is_args_valid(argv0, argc0) == 1);
	assert(is_args_valid(argv1, argc1) == 1);
	assert(is_args_valid(argv2, argc2) == 1);
	assert(is_args_valid(argv3, argc3) == 1);
	assert(is_args_valid(argv4, argc4) == 0);
	assert(is_args_valid(argv5, argc5) == 1);
	assert(is_args_valid(argv6, argc6) == 1);
	assert(is_args_valid(argv7, argc7) == 0);
	assert(is_args_valid(argv8, argc8) == 1);
	assert(is_args_valid(argv9, argc9) == 0);

	assert(count_valid_numbers(argv0, argc0) == 3);
	assert(count_valid_numbers(argv1, argc1) == 3);
	assert(count_valid_numbers(argv2, argc2) == 3);
	assert(count_valid_numbers(argv3, argc3) == 3);
	assert(count_valid_numbers(argv4, argc4) == 3);
	assert(count_valid_numbers(argv5, argc5) == 2);
	assert(count_valid_numbers(argv6, argc6) == 0);
	assert(count_valid_numbers(argv7, argc7) == 1);
	assert(count_valid_numbers(argv8, argc8) == 1);
	assert(count_valid_numbers(argv9, argc9) == 0);

	assert(get_flag_values(argv0, argc0) == 0);
	assert(get_flag_values(argv1, argc1) == 0);
	assert(get_flag_values(argv2, argc2) == 16);
	assert(get_flag_values(argv3, argc3) == 1);
	assert(get_flag_values(argv4, argc4) == 1);
	assert(get_flag_values(argv5, argc5) == 17);
	assert(get_flag_values(argv6, argc6) == 17);
	assert(get_flag_values(argv7, argc7) == 5);
	assert(get_flag_values(argv8, argc8) == 0);
	assert(get_flag_values(argv9, argc9) == (-1));

	printf("[OK] \n");
}
