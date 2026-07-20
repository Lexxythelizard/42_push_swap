/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utillities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:09:48 by lenivorb          #+#    #+#             */
/*   Updated: 2026/07/09 13:58:34 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./push_swap.h"

// --- DOC ---

/*
	... your comment here ...
*/

// --- define ---

int	int_min_of_two(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	int_max_of_two(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
