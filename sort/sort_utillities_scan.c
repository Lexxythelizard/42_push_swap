/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utillities_scan.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:14:07 by lenivorb          #+#    #+#             */
/*   Updated: 2026/08/07 19:14:08 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- include ---

#include "./sort.h"

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
