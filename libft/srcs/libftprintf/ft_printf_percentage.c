/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:59:11 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 13:44:24 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf_percentage(t_flags f)
{
	unsigned int		len;
	char				print;

	len = 0;
	print = ' ';
	if (f.len_field <= 1)
		return (ft_putchar('%'));
	if (f.minus == 1)
	{
		len += ft_putchar('%');
		while (len < f.len_field)
			len += ft_putchar(print);
	}
	else
	{
		if (f.zero == 1)
			print = '0';
		while (len < f.len_field - 1)
			len += ft_putchar(print);
		len += ft_putchar('%');
	}
	return (len);
}
