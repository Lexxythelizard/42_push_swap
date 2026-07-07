/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:39:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/02 15:41:56 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "../ft_printf.h"
#include "../core/ft_printf_core.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	process_flagg(t_flags *flags, const char *line)
{
	int	i;
	int	wrt;
	int	len;

	i = 1;
	len = 0;
	while ((line[i]) && (is_flag(line[i])))
	{
		flags -> hash += (line[i] == 35);
		flags -> wsp += (line[i] == 32);
		flags -> plus += (line[i] == 43);
		i++;
	}
	if (is_specifier(&(line[i])))
		return (0);
	i = 0;
	while ((line[i]) && (is_flag(line[i])))
	{
		wrt = lxy_put_char(line[i]);
		if (wrt < 0)
			return (-1);
		len += wrt;
		i++;
	}
	return (len);
}

int	process_specifier(t_flags *flags, va_list *args, const char *line, int *idx)
{
	char	*ptr;
	int		wrt0;
	int		wrt1;
	int		move;

	ptr = (char *)(line);
	wrt0 = process_flagg(flags, ptr);
	if (wrt0 < 0)
		return (-1);
	move = flags -> hash + flags -> wsp + flags -> plus + 1;
	ptr += move;
	wrt1 = call_put_func(ptr, args, flags);
	if (wrt1 < 0)
		return (-1);
	*idx += ((get_specifier_lenght(ptr)) + move - 1);
	clean_flags(flags);
	return (wrt0 + wrt1);
}
