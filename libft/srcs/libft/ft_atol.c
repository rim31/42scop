/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 11:22:09 by oseng             #+#    #+#             */
/*   Updated: 2016/07/27 11:22:12 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atol(const char *str)
{
	long long	result;
	int			index;
	int			tmp;

	result = 0;
	index = 0;
	tmp = index;
	while (str[index] == '\t' || str[index] == ' ' || str[index] == '\n'
			|| str[index] == '\r' || str[index] == '\f' || str[index] == '\v')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		tmp = index;
		index++;
	}
	while (str[index] <= '9' && str[index] >= '0')
	{
		result *= 10;
		result += str[index] - 48;
		index++;
	}
	if (str[tmp] == '-')
		result *= -1;
	return (result);
}
