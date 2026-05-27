/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:18:26 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/27 17:19:33 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pa(t_interface	*stacks)
{
	p(stacks -> a, stacks -> b);
}

void	pb(t_interface	*stacks)
{
	p(stacks -> b, stacks -> a);
}
