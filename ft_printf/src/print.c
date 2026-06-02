/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:29:29 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/22 19:00:56 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints a character and returns 1 */
int	rvn_printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

/* Prints a string and returns the length of the printed string, prints 
   '(null)' when receiving NULL */
int	rvn_printstr(const char *s)
{
	int	count;

	if (s == NULL)
		return (rvn_printstr("(null)"));
	count = ft_strlen(s);
	ft_putstr_fd((char *)s, 1);
	return (count);
}

/* Prints a signed or unsigned number using a certain base and returns the
   number of characters used to represent the number */
int	rvn_printnbr(unsigned long n, char *base, bool issigned)
{
	int	count;

	count = rvn_getlog(n, ft_strlen(base), issigned) + !n + (issigned && \
	((long)n < 0));
	if (issigned && (long)n < 0)
		ft_putchar_fd('-', 1);
	rvn_putbase(n * (1 - 2 * ((long)n < 0 && issigned)), base);
	return (count);
}

/* Prints an unsigned number in hexadecimal using either 0-9 and either 
   a-f or A-F to represent it, returns the number of characters used to
   represent the number */
int	rvn_printhex(unsigned long hex, bool isupper)
{
	if (!isupper)
		return (rvn_printnbr(hex, "0123456789abcdef", false));
	else
		return (rvn_printnbr(hex, "0123456789ABCDEF", false));
}
