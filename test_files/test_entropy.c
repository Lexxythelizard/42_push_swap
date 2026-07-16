/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_argparsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:28:12 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/05 20:11:45 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../push_swap.h"
#include "../libraries/libft/libft.h"
#include "../libraries/ft_printf/ft_printf.h"
#include "../libraries/stack_machine/stackmachine.h"

#include <stdio.h>

// --- prototype ---

void	test_entropy(int *arr, int len);

// --- run ---

int	main(int argc, char **argv)
{
	int	i;
	int	*arr;
	int	len;

	i = 1;
	arr = NULL;
	ft_printf("\n++++++++++++++++++++++++++++++++++++++++++++++\n\n");

	ft_printf("test: passed arguments:\n");
	while (i++ < argc)
		ft_printf("\"%s\" ", argv[(i - 1)]);
	ft_printf("\n\n");
	i = 1;
	len = argc - 1;
	if (len)
		arr = malloc(len * sizeof(int));
	while (i++ < argc)
		arr[(i - 2)] = ft_atoi(argv[(i - 1)]);
	test_entropy(arr, len);
	if (arr)
		free(arr);
	ft_printf("\n++++++++++++++++++++++++++++++++++++++++++++++\n");
	return (0);
}

// --- define ---

void test_entropy(int *arr, int len)
{
	float	entro;
	int		pre;
	int		post;

	entro = calculate_entropy(arr, len);
	
	printf("test 0 : entro %f\n\n", entro);

	pre = (int)(entro);
	post = (int)(entro * 100.00) % 100;

	ft_printf("level of entropy is: %d.%d%%\n\n", pre, post);
}
