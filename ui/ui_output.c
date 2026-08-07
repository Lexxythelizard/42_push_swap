/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:15:28 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:15:30 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "./ui.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/libft/libft.h"

// --- define ---

/*
puts an Error message followd by a new line to the standart error
and returns 1
*/

int	put_error(void)
{
	ft_putendl_fd(ERR_STR, STDERR);
	return (1);
}
