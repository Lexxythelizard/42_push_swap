/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenivorb <lenivorb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:16 by lenivorb          #+#    #+#             */
/*   Updated: 2026/05/12 22:17:26 by lenivorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --- includes ---

#include "libft.h"

// --- prototypes ---

char			*ft_itoa(int n);
static void		lxy_put_pos_int_to_str(char *int_str, int n);
static size_t	lxy_countdigits_and_sign(int n);
static int		lxy_set_divisor_base_10(int n);
static int		lxy_to_negativ(int n);

// --- DOC ---

/*
DESCRIPTION:

ft_itoa allocates memory malloc() and returns a string 
representing the integer received as an argument. 

utility : lxy_is_chr_in_str(const char *str, const char c)

PARAMS:

		n:     integer given

GUARD:

		if memory allocation fails returns NULL

RETURN:

    pointer to new string
    NULL if Guard was triggered

UTILITY FUNCTIONS:

	lxy_put_pos_int_to_str(char *int_str, int n);

        --> puts a positv number into an existing str

	lxy_countdigits_and_sign(int n);

        --> uses aritmetical operations to count the digits 
			(characters needed) for the string without '\0'

	lxy_set_divisor_base_10(int n);

        --> sets the divisor to 10^(n) ; n = digits - 1

	lxy_to_negativ(int n);

        --> returns negativ of n

*/

// --- define ---

char	*ft_itoa(int n)
{
	char	*int_str;
	size_t	len;
	size_t	i;

	i = 0;
	len = lxy_countdigits_and_sign(n);
	int_str = malloc(len + 1);
	if (int_str == NULL)
		return (NULL);
	if (n < 0)
		int_str[i] = 45;
	if (n < 0)
		i++;
	n = lxy_to_negativ(n);
	lxy_put_pos_int_to_str(&(int_str[i]), n);
	return (int_str);
}

/*
utillity function
*/

static void	lxy_put_pos_int_to_str(char *int_str, int n)
{
	int		divisor;
	size_t	i;

	i = 0;
	n = lxy_to_negativ(n);
	divisor = lxy_set_divisor_base_10(n);
	while (divisor >= 10)
	{
		int_str[i] = ((((int)(n / divisor)) * (-1)) + 48);
		n = (int)(n % divisor);
		divisor /= 10;
		i++;
	}
	int_str[i] = (((int)(n / divisor)) * (-1)) + 48;
	int_str[i + 1] = '\0';
}

static size_t	lxy_countdigits_and_sign(int n)
{
	size_t	len;
	int		divisor;

	len = 1;
	if (n < 0)
		len++;
	divisor = 1;
	n = lxy_to_negativ(n);
	while ((int)(n / divisor) <= (-10))
	{
		len++;
		divisor *= 10;
	}
	return (len);
}

static int	lxy_set_divisor_base_10(int n)
{
	int	divisor;

	divisor = 1;
	n = lxy_to_negativ(n);
	while ((int)(n / divisor) <= (-10))
		divisor *= 10;
	return (divisor);
}

static int	lxy_to_negativ(int n)
{
	if (n > 0)
		return (n * (-1));
	return (n);
}
