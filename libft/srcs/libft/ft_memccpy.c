/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:55:42 by oseng             #+#    #+#             */
/*   Updated: 2015/12/08 14:10:37 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*s1;
	const unsigned char		*s2 = src;
	size_t					i;
	unsigned char			ch;

	ch = c;
	i = 0;
	s1 = dst;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == ch)
		{
			i++;
			return ((void *)dst + i);
		}
		i++;
	}
	return (NULL);
}
