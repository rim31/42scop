/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng    <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:57:54 by oseng             #+#    #+#             */
/*   Updated: 2015/12/04 14:05:56 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_words(char const *s, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			if (i == 0 || s[i - 1] == c)
				words++;
			i++;
		}
	}
	return (words);
}

static void		fill_tab(const char *str, int *i, char c, char *s2)
{
	size_t	sizestr;
	int		tmp;
	int		j;

	j = 0;
	sizestr = 0;
	while (str[*i] == c)
		*i += 1;
	tmp = *i;
	while (str[*i] != c && str[*i] != '\0')
	{
		sizestr++;
		*i += 1;
	}
	*i = tmp;
	while (str[*i] != c && str[*i] != '\0')
	{
		s2[j] = str[*i];
		j++;
		*i += 1;
	}
	s2[j] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	char	**full_tab;
	int		j;
	int		*i_;
	int		i;

	i = 0;
	j = 0;
	i_ = &j;
	full_tab = (char **)malloc(nb_words(s, c) * sizeof(char **) + 1);
	if (full_tab == NULL)
		return (NULL);
	while (i < nb_words(s, c))
	{
		full_tab[i] = (char*)malloc(sizeof(char *) * ft_strlen(s));
		if (full_tab[i] == NULL)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < nb_words(s, c))
		fill_tab(s, i_, c, full_tab[i++]);
	full_tab[i] = 0;
	return (full_tab);
}
