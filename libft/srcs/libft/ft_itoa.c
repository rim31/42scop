/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:37:35 by oseng             #+#    #+#             */
/*   Updated: 2016/03/17 11:10:28 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		nb_of_nb(long long int m)
{
	int		i;
	long	d;

	i = 1;
	d = 10;
	while ((m / d > 1) || (m / d < -1))
	{
		i++;
		d *= 10;
	}
	return (i);
}

static char		*if_zero(char *str)
{
	int		i;

	i = 0;
	str[i++] = '0';
	str[i] = '\0';
	return (str);
}

static char		*fill(long long int n, char *str)
{
	int		i;
	int		f_true;
	int		rem;

	i = 0;
	f_true = 0;
	rem = 0;
	if (n < 0)
	{
		f_true = 1;
		n = -n;
	}
	while (n != 0)
	{
		rem = n % 10;
		str[i++] = (rem > 9) ? (rem - 10) + '0' : rem + '0';
		n /= 10;
	}
	if (f_true == 1)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(long long int n)
{
	char	*str;
	int		i;

	i = 0;
	if ((-n - 1) == 9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
		str = (char *)malloc(sizeof(char) * nb_of_nb(n) + 2);
	else
		str = (char *)malloc(sizeof(char) * nb_of_nb(n) + 1);
	if (str == NULL)
		return (NULL);
	else if (n == 0)
		return (if_zero(str));
	else
	{
		str = fill(n, str);
		ft_reverse(str);
	}
	return (str);
}
