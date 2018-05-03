/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:49:24 by oseng             #+#    #+#             */
/*   Updated: 2016/03/29 15:29:52 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*if_zero(char *str)
{
	int		i;

	i = 0;
	str[i++] = '0';
	str[i] = '\0';
	return (str);
}

static char		*fill(unsigned long long n, char *str, int base)
{
	int		i;
	int		rem;

	i = 0;
	rem = 0;
	while (n != 0)
	{
		rem = n % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		n = n / base;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa_base(unsigned long long n, int base)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * 256 + 1)))
		return (NULL);
	else if (n == 0)
		return (if_zero(str));
	else
	{
		str = fill(n, str, base);
		ft_reverse(str);
	}
	return (str);
}
