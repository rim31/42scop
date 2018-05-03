/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_lo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:43:12 by oseng             #+#    #+#             */
/*   Updated: 2016/04/02 10:55:40 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print(int len, char *nb, int nb_len)
{
	len += nb_len;
	write(1, nb, nb_len);
	return (len);
}

static int		print_number(char *nb, t_flags f, unsigned long long n)
{
	int			len;
	int			i;
	int			nb_len;
	int			hashtag;

	hashtag = 0;
	if (f.hashtag == 1 && f.precision == 0 && n == 0)
		hashtag = 1;
	len = 0;
	nb_len = ft_strlen(nb);
	i = 0;
	if ((f.hashtag == 1 && n > 0 && f.precision < nb_len) || hashtag == 1)
		len += ft_putchar('0');
	if (f.precision == 0 && ft_strcmp("0", nb) == 0)
		nb_len = 0;
	if (f.precision > nb_len)
	{
		len += f.precision;
		while (i < f.precision - nb_len)
			i += ft_putchar('0');
		write(1, nb, nb_len);
	}
	else
		len = print(len, nb, nb_len);
	return (len);
}

static int		minus(int len, char *print, t_flags f, unsigned long nb)
{
	len += print_number(print, f, nb);
	while (len < (int)f.len_field)
		len += ft_putchar(' ');
	return (len);
}

int				ft_printf_o2(unsigned long nb, t_flags f)
{
	int					len;
	char				*print;
	int					tmp_len;

	len = 0;
	tmp_len = 0;
	print = ft_itoa_base(nb, 8);
	if (f.hashtag == 1 && nb > 0 && f.precision < (int)ft_strlen(print))
		tmp_len += 1;
	if ((int)ft_strlen(print) < f.precision && f.precision >= 0)
		tmp_len += f.precision;
	else
		tmp_len += ft_strlen(print);
	if (tmp_len >= (int)f.len_field)
		len += print_number(print, f, nb);
	else if (f.minus == 1)
		len = minus(len, print, f, nb);
	else
	{
		while (len < (int)f.len_field - tmp_len)
			len += ft_putchar(' ');
		len += print_number(print, f, nb);
	}
	free(print);
	return (len);
}
