/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_c.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:22:48 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 13:17:24 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_c(char c, t_flags f)
{
	unsigned int		len;
	char				print;

	len = 0;
	print = ' ';
	if (f.len_field <= 1)
		return (ft_putchar(c));
	if (f.minus == 1)
	{
		len += ft_putchar(c);
		while (len < f.len_field)
			len += ft_putchar(print);
	}
	else
	{
		if (f.zero == 1)
			print = '0';
		while (len < f.len_field - 1)
			len += ft_putchar(print);
		len += ft_putchar(c);
	}
	return (len);
}
