/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 22:23:24 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char			**ft_split(char const *s, char c);
static size_t	lxy_count_fields(const char *str, const char dil);
static char		**lxy_valid_or_null(char ***new_arr, size_t size);
static void		lxy_free_broken_str_arr(char ***strs, size_t size);

// --- DOC ---
/*
DESCRIPTION:

ft_split allocates memory malloc() array of strings obtained 
by splitting ’s’ using the character ’c’ as a delimiter.
The array of pointers itself is allocated dynamically.
Each string in the returned array is allocated independently 
by calling ft_substring()
The returned array is NULL terminated

utility : lxy_is_chr_in_str(const char *str, const char c)

PARAMS:

    s1:     string
    set:    set of characters to look for

GUARD:

    if s or set is NULL return [NULL]
    if memory allocation fails returns NULL
	if memory allocation fails in any string --> return NULL

RETURN:

    pointer to new string
    NULL if Guard was triggered

UTILITY FUNCTIONS:

	lxy_count_fields(const char *str, const char dil)

		--> count fields 0 - MAX_SIZE possible

	**lxy_valid_or_null(char ***new_arr, size_t size);

		--> created because of ROL (running out of lines)
			either checks if some str is broken or NULL
			in this case free everything and return NULL
			else just return the array itself

	lxy_free_broken_str_arr(char ***strs, size_t size);

		--> runs size time and frees every single string
			then frees the array itself and set pointer to NULL

NOTE:

	if memory allocation failed in any step
					--> NULL 			was returned

	if s was empty	--> array { NULL }	was returned

*/

// --- define ---

char	**ft_split(char const *s, char c)
{
	char		**str_array;
	size_t		i;
	size_t		fields;
	size_t		start;
	size_t		stop;

	i = 0;
	start = 0;
	fields = lxy_count_fields(s, ((const char)(c)));
	str_array = malloc((fields + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);
	while (i < fields)
	{
		while ((s[start] == c) && (s[start]))
			start++;
		stop = start;
		while ((s[stop] != c) && (s[stop]))
			stop++;
		str_array[i] = ft_substr(s, start, (stop - start));
		start = stop;
		i++;
	}
	str_array[i] = NULL;
	return (lxy_valid_or_null(&str_array, fields));
}

// --- utillities ---

static size_t	lxy_count_fields(const char *str, const char dil)
{
	size_t	count;
	size_t	i;
	int		on_dil;

	count = 0;
	i = 0;
	on_dil = 1;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == dil)
			on_dil = 1;
		if ((on_dil) && (str[i] != dil))
		{
			count++;
			on_dil = 0;
		}
		i++;
	}
	return (count);
}

static char	**lxy_valid_or_null(char ***new_arr, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if ((*new_arr)[i] == NULL)
		{
			lxy_free_broken_str_arr(new_arr, size);
			return (NULL);
		}
		i++;
	}
	return (*new_arr);
}

static void	lxy_free_broken_str_arr(char ***strs, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((*strs)[i] != NULL)
			free((*strs)[i]);
		(*strs)[i] = NULL;
		i++;
	}
	free(*strs);
	*strs = NULL;
}
