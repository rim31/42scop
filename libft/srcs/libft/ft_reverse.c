/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 22:56:15 by oseng             #+#    #+#             */
/*   Updated: 2015/11/28 22:59:38 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse(char *str)
{
	int		i;
	int		j;
	int		mid;
	char	c;

	i = 0;
	j = ft_strlen(str) - 1;
	if ((j % 2) == 1)
		mid = (j - 1) / 2;
	else
		mid = j / 2;
	while (i <= mid)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		j--;
		i++;
	}
}
