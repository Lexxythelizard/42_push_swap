/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:36:28 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/22 19:09:46 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Prints the next argument according to the conversion rule
   c   - Prints a character
   s   - prints a string
   p   - prints a pointer value in the format 0x... or '(nil)' when receiving
         NULL
   d/i - prints a signed integer
   u   - prints an unsigned integer
   x   - prints an unsigned integer as a hexadecimal number using 0-9,a-f
   X   - prints an unsigned integer as a hexadecimal number using 0-9,A-F
   %   - prints a percentage sign (%)
   Returns the number of characters printed. */
int	rvn_printconv(char c, va_list *args)
{
	unsigned long	next;

	if (c == '%')
		return (rvn_printchar('%'));
	next = va_arg(*args, unsigned long);
	if (c == 'c')
		return (rvn_printchar((char)next));
	if (c == 's')
		return (rvn_printstr((char *)next));
	if (c == 'p')
	{
		if (!next)
			return (rvn_printstr("(nil)"));
		return (rvn_printstr("0x") + \
		rvn_printhex(next, false));
	}
	if (c == 'd' || c == 'i')
		return (rvn_printnbr((int)next, "0123456789", true));
	if (c == 'u')
		return (rvn_printnbr((unsigned int)next, "0123456789", false));
	if (c == 'x')
		return (rvn_printhex((unsigned int)next, false));
	if (c == 'X')
		return (rvn_printhex((unsigned int)next, true));
	return (0);
}

/* Prints a format string inserting additional arguments in place of 
   conversion rules. Returns the number of printed characters */
int	ft_printf(const char *format, ...)
{
	const char	*curr;
	int			count;
	va_list		args;

	if (!format)
		return (0);
	va_start(args, format);
	count = 0;
	curr = format;
	while (*curr)
	{
		count += rvn_printuntil(&curr);
		if (*curr)
		{
			curr++;
			count += rvn_printconv(*(curr++), &args);
		}
	}
	va_end(args);
	return (count);
}

/* --test program-- */

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	ft_putendl_fd("My version:", 1);
	printf("%d", ft_printf("Insert whatever!"));
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("Original:", 1);
	printf("%d", printf("Insert whatever!"));
	return (0);
}
*/
