/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:30:08 by oseng             #+#    #+#             */
/*   Updated: 2015/12/09 20:03:16 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	if (!s)
		return (ft_strdup("\0"));
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j >= i)
		j--;
	new_str = (char *)malloc(sizeof(char) * (j - i));
	if (new_str == NULL)
		return (NULL);
	if (j > i)
	{
		while (i <= j)
			new_str[n++] = s[i++];
	}
	new_str[n] = '\0';
	return (new_str);
}
