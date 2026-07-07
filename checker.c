/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:36:50 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/06 18:37:56 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

int	main(int argc, char **argv)
{
	t_interface	*c;

	if (!is_args_valid(argv))
		ft_putendl_fd("Error", 2);
	else
	{
		c = init(argc, argv);
		checker(c);
		free_interface(c);
	}
	return (0);
}

void	checker(t_interface *c)
{
	char	*call;
	int		i;

	call = get_next_line(0);
	while (call)
	{
		i = 0;
		while ((c -> funcs -> name)[i] != call)
			if (++i == 11)
				return (ft_printendl_fd("Error", 2));
		exec(c, i);
		free(call);
		call = get_next_line(0);
	}
	if (compute_disorder((c -> stacks)[0]->head) == 0 \
	&& (c -> stacks)[1]->head == NULL)
		ft_printendl_fd("OK", 1);
	else
		ft_printendl_fd("KO", 1);
}
