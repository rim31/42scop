/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 14:12:23 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 14:34:25 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		nubm(t_flags f, t_print lenf, int len, char *nb)
{
	int		i;

	i = 0;
	if (lenf.nb_zero > 0 || f.precision > lenf.nb_len)
	{
		len += lenf.nb_zero + lenf.nb_len;
		while (i < lenf.nb_zero)
			i += ft_putchar('0');
		write(1, nb, lenf.nb_len);
	}
	else
	{
		len += lenf.nb_len;
		if (f.precision == 0 && lenf.n == 0 && f.len_field > 0)
			write(1, " ", 1);
		else
			write(1, nb, lenf.nb_len);
	}
	return (len);
}

static int		print_number(char *nb, t_flags f, unsigned long long n, int fie)
{
	int			len;
	t_print		lenf;

	len = 0;
	lenf.n = n;
	lenf.nb_len = ft_strlen(nb);
	if (f.precision == 0 && n == 0 && f.len_field == 0)
		lenf.nb_len = 0;
	if (f.hashtag == 1 && n > 0)
	{
		write(1, "0x", 2);
		len += 2;
	}
	if (f.zero == 1 && fie > f.precision && fie > 0)
		lenf.nb_zero = fie;
	else
		lenf.nb_zero = f.precision - lenf.nb_len;
	len = nubm(f, lenf, len, nb);
	return (len);
}

static int		minus(t_flags f, int len, unsigned long long nb, char *print)
{
	len += print_number(print, f, nb, f.precision);
	while (len < (int)f.len_field)
		len += ft_putchar(' ');
	return (len);
}

static int		free_ret(char *print, int len)
{
	free(print);
	return (len);
}

int				ft_printf_x(va_list ap, t_flags f)
{
	t_len				lenf;
	unsigned long long	nb;
	char				*print;

	lenf.len = 0;
	lenf.tmp_len = 0;
	nb = unsigned_check(ap, f);
	print = ft_itoa_base(nb, 16);
	if (f.hashtag == 1)
		lenf.tmp_len += 2;
	if ((int)ft_strlen(print) < f.precision)
		lenf.tmp_len += f.precision;
	else
		lenf.tmp_len += ft_strlen(print);
	if (lenf.tmp_len >= (int)f.len_field)
		lenf.len += print_number(print, f, nb, f.precision);
	else if (f.minus == 1)
		lenf.len = minus(f, lenf.len, nb, print);
	else
	{
		while (lenf.len < (int)f.len_field - lenf.tmp_len && f.zero != 1)
			lenf.len += ft_putchar(' ');
		lenf.len += print_number(print, f, nb, (int)f.len_field - lenf.tmp_len);
	}
	return (free_ret(print, lenf.len));
}
