/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_arguments_spaces.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 2026/08/06 15:45:22 by lenivorb         ###   ########.fr       */
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
