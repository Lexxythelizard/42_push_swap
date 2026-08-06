/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intranam <intranam@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20xx/xx/xx xx:xx:xx by intranam          #+#    #+#             */
/*   Updated: 20xx/xx/xx xx:xx:xx by intranam         ###   ########.fr       */
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
