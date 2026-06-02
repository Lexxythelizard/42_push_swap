/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:55:43 by rcollet           #+#    #+#             */
/*   Updated: 2026/06/02 18:10:58 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_interface
{
	t_stack		*a;
	t_stack		*b;
	t_func		func[11];	
}	t_interface;

typedef struct s_funcs
{
	void	(*f)(t_interface);
	char	*name;
}	t_funcs;

# define SIMPLE "(O(n²))";
# define MEDIUM "(O(n√n\u0305)"
# define COMPLEX "(O(n))"
# define STDIN 0
# define STDOUT 1
# define STDERR 2

#endif
