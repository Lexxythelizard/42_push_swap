/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:21:06 by rcollet           #+#    #+#             */
/*   Updated: 2026/06/05 14:40:10 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rra(t_interface *c)
{
	rr((c -> stacks)[0]);
}

void	rrb(t_interface	*c)
{
	rr((c -> stacks)[1]);
}

void	rrr(t_interface *c)
{
	rra(c);
	rrb(c);
}
