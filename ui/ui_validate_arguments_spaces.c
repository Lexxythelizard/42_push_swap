/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_arguments_spaces.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:17:23 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:17:24 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

// --- define ---

int	is_space_str_in_arr(const char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_space_str(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_space_str(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!(is_space((unsigned char)(s[i]))))
			return (0);
		i++;
	}
	return (1);
}

int	is_space(int c)
{
	c %= 256;
	return (((c >= 9) && (c <= 13)) || (c == 32));
}
