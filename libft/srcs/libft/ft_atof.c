/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:48:35 by oseng             #+#    #+#             */
/*   Updated: 2017/11/25 14:13:54 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(const char *str)
{
	double		result;
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
	if (str[index] == '.')
	{
		index++;
		int indice = 10;
		while (str[index] <= '9' && str[index] >= '0')
		{
			result += (double)(str[index] - 48) / indice;
			indice *= 10;
			index++;
		}
	}
	if (str[tmp] == '-')
		result *= -1;
	return (result);
}
