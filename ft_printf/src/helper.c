/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:40:25 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/22 19:31:14 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints a string until encountering either '%' or the end of the string,
   returns the number of characters printed and advances the format string
   position */
int	rvn_printuntil(const char **s)
{
	int	count;

	count = 0;
	while (*(*s) != '\0' && *(*s) != '%')
	{
		ft_putchar_fd(*((*s)++), 1);
		count++;
	}
	return (count);
}

/* Calculates the log_base(|num|), i.e. the logarithm of a certain base 
   of the absolute value of a signed or unsigned number */
int	rvn_getlog(unsigned long num, int base, bool issigned)
{
	int		rtrn;
	long	num_signed;

	rtrn = 0;
	if (issigned)
	{
		num_signed = (long)num;
		while (num_signed)
		{
			num_signed /= base;
			rtrn++;
		}
	}
	else
	{
		while (num)
		{
			num /= base;
			rtrn++;
		}
	}
	return (rtrn);
}

/* Prints out an unsigned number using a certain base */
void	rvn_putbase(unsigned long n, char *base)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		rvn_putbase(n / base_len, base);
	ft_putchar_fd(base[n % base_len], 1);
}
