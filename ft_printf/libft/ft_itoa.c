/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:10:42 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/07 13:08:04 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory and returns a string representing the integer received
   as an argument */
char	*ft_itoa(int n)
{
	int		len;
	int		h;
	char	*rtrn;

	len = n <= 0;
	h = n;
	while (h)
	{
		h /= 10;
		len++;
	}
	rtrn = malloc(len + 1);
	if (!rtrn)
		return (NULL);
	h = n * (1 - 2 * (n > 0));
	rtrn[len] = '\0';
	while (len--)
	{
		rtrn[len] = (-(h % 10) + '0');
		h /= 10;
	}
	if (n < 0)
		rtrn[0] = '-';
	return (rtrn);
}

/* --test program-- */

/*

int	main(int argc, char **argv)
{
	char	*rtrn;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	rtrn = ft_itoa(ft_atoi(argv[1]));
	if (!rtrn)
		ft_putendl_fd("(null)", 1);
	else
	{
		ft_putendl_fd(rtrn, 1);
		free (rtrn);
	}
	return (0);
}
*/
