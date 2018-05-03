/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 13:58:44 by oseng             #+#    #+#             */
/*   Updated: 2016/04/03 12:40:59 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** for precision
*/

static int	len_char(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else
		return (4);
}

int			ft_nwstrlen(wchar_t *str, int len)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (str == NULL)
		return (6);
	while (str[i] && ret < len)
	{
		if (str[i] <= 0x7F)
			ret += 1;
		else if (str[i] <= 0x7FF)
			ret += 2;
		else if (str[i] <= 0xFFFF)
			ret += 3;
		else
			ret += 4;
		i++;
	}
	if (ret > len)
		ret -= len_char(str[i]);
	return (ret);
}

int			ft_wstrlen(wchar_t *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (str == NULL)
		return (6);
	while (str[i])
	{
		if (str[i] <= 0x7F)
			len += 1;
		else if (str[i] <= 0x7FF)
			len += 2;
		else if (str[i] <= 0xFFFF)
			len += 3;
		else
			len += 4;
		i++;
	}
	return (len);
}
