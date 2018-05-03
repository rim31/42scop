/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_o.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:29:21 by oseng             #+#    #+#             */
/*   Updated: 2016/04/02 11:47:25 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print(int len, char *nb, t_print l, t_flags f)
{
	int		i;

	i = 0;
	if (l.nb_zero > 0 || f.precision > l.nb_len)
	{
		len += l.nb_zero + l.nb_len;
		while (i < l.nb_zero)
			i += ft_putchar('0');
		write(1, nb, l.nb_len);
	}
	else
	{
		len += l.nb_len;
		if (f.precision == 0 && l.n == 0 && f.len_field > 0)
			write(1, " ", 1);
		else
			write(1, nb, l.nb_len);
	}
	return (len);
}

static int		print_number(char *nb, t_flags f, unsigned long long n, int fie)
{
	int			len;
	t_print		l;
	int			hashtag;

	if (f.hashtag == 1 && f.precision == 0 && n == 0)
		hashtag = 1;
	else
		hashtag = 0;
	len = 0;
	l.n = n;
	l.nb_len = ft_strlen(nb);
	if ((f.hashtag == 1 && n > 0 && f.precision < l.nb_len) || hashtag == 1)
		len += ft_putchar('0');
	if (f.precision == 0 && ft_strcmp("0", nb) == 0 && f.len_field == 0)
		l.nb_len = 0;
	if (f.zero == 1 && fie > f.precision && fie > 0)
		l.nb_zero = fie;
	else
		l.nb_zero = f.precision - l.nb_len;
	len = print(len, nb, l, f);
	return (len);
}

static int		choice(t_flags f, t_len l, char *print, unsigned long long nb)
{
	if (f.minus == 1)
	{
		l.len += print_number(print, f, nb, f.precision);
		while (l.len < (int)f.len_field)
			l.len += ft_putchar(' ');
	}
	else
	{
		while (l.len < (int)f.len_field - l.tmp_len && f.zero != 1)
			l.len += ft_putchar(' ');
		l.len += print_number(print, f, nb, (int)f.len_field - l.tmp_len);
	}
	return (l.len);
}

int				ft_printf_o(va_list ap, t_flags f)
{
	t_len				l;
	unsigned long long	nb;
	char				*print;

	l.len = 0;
	l.tmp_len = 0;
	nb = unsigned_check(ap, f);
	print = ft_itoa_base(nb, 8);
	if (f.hashtag == 1 && nb > 0 && f.precision < (int)ft_strlen(print))
		l.tmp_len += 1;
	if ((int)ft_strlen(print) < f.precision && f.precision >= 0)
		l.tmp_len += f.precision;
	else
		l.tmp_len += ft_strlen(print);
	if (l.tmp_len >= (int)f.len_field)
		l.len += print_number(print, f, nb, f.precision);
	else
		l.len = choice(f, l, print, nb);
	free(print);
	return (l.len);
}
