/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:19:39 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/27 17:21:03 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(t_interface *stacks)
{
	r(stacks -> a);
}

void	rb(t_interface *stacks)
{
	r(stacks -> b);
}

void	rr(t_interface *stacks)
{
	r(stacks -> a);
	r(stacks -> b);
}
