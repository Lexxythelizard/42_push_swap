/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_free_and_return.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:15:06 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:15:07 by lenivorb         ###   ########.fr       */
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
