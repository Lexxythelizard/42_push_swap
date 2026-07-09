/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 18:22:06 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/09 16:15:11 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include "./push_swap.h"
#include "./libraries/libft/libft.h"
#include "./libraries/ft_printf/ft_printf.h"
#include "./libraries/stack_machine/stack_machine.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

void	sort_adaptive(t_stack_machine *machine)
{
	if (!machine)
		return ;
	if (/*level of disorder < x*/)
		sort_simple(machine);
	else if (/*level of disorder < y*/)
		sort_medium(machin);
	else
		sort_complex(machine);
}
