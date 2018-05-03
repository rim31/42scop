/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:46:01 by oseng             #+#    #+#             */
/*   Updated: 2015/12/09 19:40:01 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	new_str = (char *)malloc(sizeof(*new_str) * len + 1);
	if (new_str == NULL)
		return (NULL);
	while (i < start)
	{
		s++;
		i++;
	}
	ft_strncpy(new_str, s, len);
	new_str[len] = '\0';
	return (new_str);
}
