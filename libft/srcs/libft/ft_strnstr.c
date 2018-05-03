/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:40:19 by oseng             #+#    #+#             */
/*   Updated: 2015/12/03 21:43:27 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *need, int n)
{
	char	*cpy;
	int		j;
	int		i;

	i = 0;
	j = 0;
	cpy = (char*)malloc(sizeof(*cpy) * n + 1);
	if (cpy == NULL)
		return (NULL);
	ft_strncpy(cpy, haystack, n);
	while (cpy[i])
	{
		j = 0;
		while (need[j] == cpy[i + j] && need[j])
			j++;
		if (!need[j])
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
