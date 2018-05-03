/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:51:06 by oseng             #+#    #+#             */
/*   Updated: 2016/03/20 14:00:28 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putchar_long(wchar_t chr)
{
	write(1, &chr, 1);
	return (1);
}

int			ft_putwchar(wchar_t n)
{
	int		i;

	i = 0;
	if (n <= 0x7F)
		i += ft_putchar_long(n);
	else if (n <= 0x7FF)
	{
		i += ft_putchar_long(((n >> 6) + 0xC0));
		i += ft_putchar_long(((n & 0x3F) + 0x80));
	}
	else if (n <= 0xFFFF)
	{
		i += ft_putchar_long(((n >> 12) + 0xE0));
		i += ft_putchar_long((((n >> 6) & 0x3F) + 0x80));
		i += ft_putchar_long(((n & 0x3F) + 0x80));
	}
	else
	{
		i += ft_putchar_long(((n >> 18) + 0xF0));
		i += ft_putchar_long((((n >> 12) & 0x3F) + 0x80));
		i += ft_putchar_long((((n >> 6) & 0x3F) + 0x80));
		i += ft_putchar_long(((n & 0x3F) + 0x80));
	}
	return (i);
}
