/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utillities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:09:48 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/09 13:58:34 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/stack_machine/stack_machine.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	min_of(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max_of(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
