/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollet <rcollet@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:19:31 by rcollet           #+#    #+#             */
/*   Updated: 2026/05/09 15:55:22 by rcollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rvn_clear(void ***s);
static int	rvn_countword(char const *s, char c);

/* frees a dynamically allocated, null-terminated array of pointers */
static void	rvn_clear(void ***s)
{
	size_t	i;

	if (s)
	{
		if (*s)
		{
			i = 0;
			while ((*s)[i])
			{
				free((*s)[i]);
				(*s)[i++] = 0;
			}
			free(*s);
			*s = NULL;
		}
	}
}

/* Counts the number of words in the string s, where words are delimited by
   a number of occurences of the character 'c' */
static int	rvn_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	i = -1;
	count = (s[0] != c && s[0] != '\0');
	while (s[++i])
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
	return (count);
}

/* Allocates memory and returns an array of strings obtained by splitting 's'
   using the character 'c' as a delimiter. Frees up the already allocated
   memory and returns NULL on error */
char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	size_t	i;
	char	*next;
	char	**rtrn;

	num_words = rvn_countword(s, c);
	rtrn = ft_calloc(num_words + 1, 8);
	i = 0;
	while (rtrn && i < num_words)
	{
		next = ft_strchr(s, c);
		if (!next)
			next = ft_strchr(s, 0);
		if (next != s)
		{
			rtrn[i++] = ft_substr(s, 0, next - s);
			if (!(rtrn[i - 1]))
				rvn_clear((void ***)(&rtrn));
		}
		s = next + 1;
	}
	return (rtrn);
}

/* --test program-- */

/*
int	main(int argc, char **argv)
{
	char	**rtrn;
	size_t	i;

	if (argc != 3)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (-1);
	}
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putendl_fd("Not a single character!", 2);
		return (-1);
	}
	rtrn = ft_split(argv[1], *(argv[2]));
	if (!rtrn)
		ft_putendl_fd("(null)", 1);
	else
	{
		i = 0;
		ft_putchar_fd('\'', 1);
		while (rtrn[i])
		{
			ft_putstr_fd(rtrn[i++], 1);
			if (rtrn[i])
				ft_putstr_fd("\', \'", 1);
		}
		ft_putendl_fd("\'", 1);
		rvn_clear((void ***)(&rtrn));
	}
	return (0);
}
*/
