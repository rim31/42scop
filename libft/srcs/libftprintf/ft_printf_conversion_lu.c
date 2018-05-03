/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_lu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:43:03 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 13:37:19 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print_number(char *nb, t_flags f)
{
	int			len;
	int			i;
	int			nb_len;

	len = 0;
	nb_len = ft_strlen(nb);
	i = 0;
	if (f.precision > nb_len)
	{
		len += f.precision;
		while (i < f.precision - nb_len)
			i += ft_putchar('0');
		write(1, nb, nb_len);
	}
	else
	{
		len += nb_len;
		write(1, nb, nb_len);
	}
	return (len);
}

static int		minus(int len, t_flags f, char *print)
{
	len += print_number(print, f);
	while (len < (int)f.len_field)
		len += ft_putchar(' ');
	return (len);
}

int				ft_printf_u2(unsigned long long nb, t_flags f)
{
	int					len;
	char				*print;
	int					tmp_len;

	len = 0;
	tmp_len = 0;
	print = ft_itoa_base(nb, 10);
	if ((int)ft_strlen(print) < f.precision)
		tmp_len += f.precision;
	else
		tmp_len += ft_strlen(print);
	if (tmp_len >= (int)f.len_field)
		len += print_number(print, f);
	else if (f.minus == 1)
		len = minus(len, f, print);
	else
	{
		while (len < (int)f.len_field - tmp_len)
			len += ft_putchar(' ');
		len += print_number(print, f);
	}
	free(print);
	return (len);
}
