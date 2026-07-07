/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:52:44 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:49:06 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the function f to each character of the string s, passing its index
   as the first argument and the character itself as the second. Allocates
   memory and creates a new string from the return values of the successive
   applications of f. Returns either that string or NULL on error. */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rtrn;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	rtrn = ft_calloc(ft_strlen(s) + 1, 1);
	if (!rtrn)
		return (NULL);
	i = -1;
	while (s[++i])
		rtrn[i] = f(i, s[i]);
	return (rtrn); 
}

/* --test program-- */

/*
static char	rvn_fun(unsigned int n, char c);

// Puts every even-indexed character to lowercase and every odd-indexed
// character to uppercase
static char	rvn_fun(unsigned int n, char c)
{
	if (n % 2)
		return (ft_toupper(c));
	return (ft_tolower(c));
}

int	main(int argc, char **argv)
{
	char	*rtrn;

	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	rtrn = ft_strmapi(argv[1], &rvn_fun);
	if (!rtrn)
		ft_putendl_fd("(null)", 1);
	else
	{
		ft_putendl_fd(rtrn, 1);
		free(rtrn);
	}
	return (0);
}
*/
