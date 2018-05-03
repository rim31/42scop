/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:56:33 by oseng             #+#    #+#             */
/*   Updated: 2015/12/26 17:03:31 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		index;
	int		tmp;

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
