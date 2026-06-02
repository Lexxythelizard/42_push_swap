/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:41:13 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/15 18:41:18 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_conv
{
	int				min_width;
	int				prec;
	bool			flags[5];
	char			conv_type;
}	t_conv;

int		ft_printf(const char *format, ...);
int		rvn_printuntil(const char **s);
t_conv	rvn_getconv(const char **s);
int		rvn_getidx(const char *s, char c);
int		rvn_printconv(t_conv conv, va_list	*args);
int		rvn_printchar(char c, t_conv conv);
int		rvn_fill(int num, char c);
int		rvn_printstr(const char *s, t_conv conv);
int		rvn_printnbr(unsigned long n, t_conv conv, char *base, bool issigned);
int		rvn_getlog(unsigned long num, int base, bool issigned);
void	rvn_putbase(unsigned long n, char *base);
int		rvn_printhex(unsigned long hex, t_conv conv, bool isupper);

#endif
