/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:40:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/29 17:12:07 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"

// --- DOC ---

// --- proto ---

// --- define ---

char	**calloc_char_arr(size_t size)
{
	size_t	i;
	char	**null_ptr_arr;

	i = 0;
	null_ptr_arr = malloc(size * 8);
	if (!(null_ptr_arr))
		return (NULL);
	while (i++ <= size)
		null_ptr_arr[(i - 1)] = NULL;
	return (null_ptr_arr);
}

void	free_str_array(char ***strs)
{
	size_t	i;

	i = 0;
	if ((!(strs)) || (!(*strs)))
		return ;
	while (strs[i])
	{
		free((*strs)[i]);
		(*strs)[i] = NULL;
		i++
	}
	free(*strs);
	*strs = NULL;
}

void	free_int_array(char **ints)
{
	if ((!(ints)) || (!(*ints)))
		return ;
	free(*ints);
	(*ints) = NULL;
}
