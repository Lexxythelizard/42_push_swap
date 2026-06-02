/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:36:28 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/22 19:32:59 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Creates a struct t_conv used to represent a conversion rule and advances the
   format string position */
t_conv	rvn_getconv(const char **s)
{
	t_conv	conv;
	int		flag_idx;

	(*s)++;
	flag_idx = 0;
	while (flag_idx < 5)
		conv.flags[flag_idx++] = false;
	flag_idx = rvn_getidx("#0- +", *(*s));
	while (flag_idx != -1)
	{
		conv.flags[flag_idx] = true;
		flag_idx = rvn_getidx("#0- +", *(++(*s))); 
	}
	conv.min_width = ft_atoi(*s);
	conv.prec = -1;
	while (!ft_isalpha(*(*s)) && *(*s) != '%')
		if (*((*s)++) == '.')
			conv.prec = ft_atoi(*s);
	conv.conv_type = *((*s)++);
	return (conv);
}

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
   Returns the number of characters printed */
int	rvn_printconv(t_conv conv, va_list *args)
{
	if (conv.conv_type == 'c')
		return (rvn_printchar((char)va_arg(*args, int), conv));
	if (conv.conv_type == 's')
		return (rvn_printstr(va_arg(*args, char *), conv));
	if (conv.conv_type == 'p')
	{
		conv.flags[0] = true;
		return (rvn_printhex(va_arg(*args, unsigned long), conv, 0));
	}
	if (conv.conv_type == 'd' || conv.conv_type == 'i')
		return (rvn_printnbr(va_arg(*args, int), conv, "0123456789", true));
	if (conv.conv_type == 'u')
		return (rvn_printnbr(va_arg(*args, unsigned int), conv, "0123456789", \
		false));
	if (conv.conv_type == 'x')
		return (rvn_printhex(va_arg(*args, unsigned int), conv, false));
	if (conv.conv_type == 'X')
		return (rvn_printhex(va_arg(*args, unsigned int), conv, true));
	if (conv.conv_type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

/* Prints a format string inserting additional arguments in place of 
   conversion rules. Returns the number of printed characters */
int	ft_printf(const char *format, ...)
{
	const char	*curr;
	int			count;
	t_conv		conv;
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
			conv = rvn_getconv(&curr);
			count += rvn_printconv(conv, &args);
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
