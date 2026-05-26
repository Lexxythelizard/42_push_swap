/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:49:39 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/26 10:53:08 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack_frame {
	int						val;
	struct s_stack_frame	*next;
}	t_stack_frame;

typedef struct s_stack {
	t_stack_frame	*head;
	t_stack_frame	*tail;
}	t_stack;
