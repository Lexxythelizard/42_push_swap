/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:55:43 by rcollet           #+#    #+#             */
/*   Updated: 2026/06/05 14:34:34 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SIMPLE "(O(n²))";
# define MEDIUM "(O(n√n\u0305)"
# define COMPLEX "(O(n))"

typedef struct s_interface
{
	t_stack			stacks[2]
	t_op_tracker	*stats;
	t_func			func[11];	
}	t_interface;

typedef struct s_funcs
{
	void	(*f)(t_interface);
	char	*name;
}	t_funcs;

typedef struct s_op_tracker
{
	unsigned int	calls[11];
	unsigned int	total_ops;
	float			disorder;
	char			*strategy;
	void			(*print_bench)(s_op_tracker*);
}					t_op_track;

#endif
