/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:21:06 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/27 17:22:24 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rra(t_interface	*stacks)
{
	rr(stacks -> a);
}

void	rrb(t_interface *stacks)
{
	rr(stacks -> b);
}

void	rrr(t_interface *stacks)
{
	rr(stacks -> a);
	rr(stacks -> b);
}
