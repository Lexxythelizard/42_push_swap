// --- icludes ---

#include "../push_swap.h"
#include "../libraries/libft/libft.h"
#include "../libraries/ft_printf/ft_printf.h"
#include "../libraries/stack_machine/stack_machine.h"

#include <stdio.h>
// --- DOC ---

/*
	unsigned int    calls[11];
    unsigned int    total_ops;
    float           disorder;
    char            *strategy;

*/

// --- prototype ---

t_stats	*init_stats(void);
void	assign_calls(t_stats *stats, char **argv, int argc);
void	assign_flag(t_stats *stats, char *flag);
void	print_test(t_stats *stats);

// --- run ---

int	main(int argc, char **argv)
{
	t_stats	*stats;

	stats = init_stats();
	if (argc > 1)
		assign_calls(stats, argv, argc);
	if (argc > 12)
		assign_flag(stats, argv[12]);
	print_bench(stats);
	//print_test(stats);
	free(stats);
	return (0);
}

// --- define ---

t_stats	*init_stats(void)
{
	int		i;
	t_stats	*new;

	i = 0;
	new = malloc(sizeof(t_stats));
	if (!new)
		return (NULL);
	while (i++ < 11)
		new -> calls[(i - 1)] = 0;
	new -> total_ops = 0;
	new -> disorder = 3.14;
	new -> strategy = NULL;
	return (new);
}

void	assign_calls(t_stats *stats, char **argv, int argc)
{
	int	i;

	i = 0;
	while ((i < argc) && (i < 11))
	{
		stats -> calls[i] = ft_atoi(argv[(i + 1)]);
		i++;
	}
	i = 0;
	while (i++ < 11)
		stats -> total_ops += stats -> calls[(i - 1)];
}

void	assign_flag(t_stats *stats, char *flag)
{
	stats -> strategy = flag;
}

void	print_test(t_stats *stats)
{
	float	temp;
	int		pre;
	int		post;

	temp = stats -> disorder;
	ft_printf("test0: temp was intialized and copied\n");
	printf("test1: original printf float: %f\n", temp);
	pre = (int)(temp);
	ft_printf("test2: pre initialized\n");
	ft_printf("test2: pre: %d\n", pre);
	post = (int)(temp * 100.00) % 100;
	ft_printf("test3: post initialized\n");	
	ft_printf("test4: post: %d\n", post);
	ft_printf("test5: finally all in a flow\n");
	ft_printf("[bench]  disorder:  %d.%d\n", pre, post);	
}
