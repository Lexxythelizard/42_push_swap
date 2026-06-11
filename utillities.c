/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utillities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 17:09:48 by lenivorb          #+#    #+#             */
/*   Updated: 2026/06/11 20:10:55 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- icludes ---

#include <[statlib].h>

// --- DOC ---

/*
	... your comment here ...
*/

// --- prototype ---

int	min_of(int a, int b);
int	max_of(int a, int b);
int	is_numbers_unique_simple(int *list, int len);

// --- define ---

int	min_of(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max_of(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int is_numbers_unique_simple(int *list, int len)
{
    int i;
    int j;

    i = 0;

    while ((i + 1) < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (list[i] == list[j])
                return (0);
            j++;
        }   
        i++;
    }   
    return (1);
}
