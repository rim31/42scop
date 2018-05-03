/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:06:51 by oseng             #+#    #+#             */
/*   Updated: 2015/12/04 11:40:18 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_;
	const char	*src_;
	char		tmp[n];
	int			i;

	i = 0;
	dest_ = dest;
	src_ = src;
	while (i < (int)n)
	{
		tmp[i] = src_[i];
		i++;
	}
	i = 0;
	while (i < (int)n)
	{
		dest_[i] = tmp[i];
		i++;
	}
	return (dest);
}
