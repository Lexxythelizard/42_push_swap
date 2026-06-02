/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:40:57 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/02 18:00:51 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "libft.h"

// --- DOC ---

// --- proto ---

// --- define ---

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
