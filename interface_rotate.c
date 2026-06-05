/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:19:39 by rcollet           #+#    #+#             */
/*   Updated: 2026/06/05 14:38:59 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(t_interface *c)
{
	r((c -> stacks)[0]);
}

void	rb(t_interface *c)
{
	r((c -> stacks)[1]);
}

void	rr(t_interface *c)
{
	ra(c);
	rb(c);
}
