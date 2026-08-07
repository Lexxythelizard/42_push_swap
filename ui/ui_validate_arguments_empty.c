/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_validate_arguments_empty.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:16:24 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:16:32 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./ui.h"
#include "../libraries/libft/libft.h"

// --- define ---

int	is_empty_str_in_arr(const char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_empty_str(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_empty_str(const char *s)
{
	if (!s)
		return (0);
	return (s[0] == 0);
}
