/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:51:23 by oseng             #+#    #+#             */
/*   Updated: 2016/04/02 15:14:20 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_putwstr(wchar_t *str, size_t len)
{
	size_t			i;
	int				ret;

	i = 0;
	ret = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i += 1;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else
			i += 4;
		if (i > len)
			break ;
		ret += ft_putwchar(*str++);
	}
	return (ret);
}
