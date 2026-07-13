/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:49:39 by rcollet           #+#    #+#             */
/*   Updated: 2026/07/08 19:43:03 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack_node {
	int					val;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_element;

typedef struct s_stack {
	int			len;
	t_element	*first;
	t_element	*last;
}				t_stack;

#endif
