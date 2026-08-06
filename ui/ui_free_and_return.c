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

#include <stdlib.h>
#include "./ui.h"

// --- define ---

int	free_and_return_int(void *ptr, int i)
{
	if (ptr)
		free(ptr);
	return (i);
}

void	*free_and_return_any_ptr(void *ptr, void *address)
{
	if (ptr)
		free(ptr);
	return (address);
}
