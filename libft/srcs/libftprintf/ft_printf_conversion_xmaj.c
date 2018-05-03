/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_xmaj.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:41:16 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 16:26:09 by oseng            ###   ########.fr       */
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
			i += write(1, "0", 1);
		write(1, nb, lenf.nb_len);
	}
	else
	{
		len += lenf.nb_len;
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
	if (f.precision == 0 && n == 0)
		lenf.nb_len = 0;
	if (f.hashtag == 1 && n > 0)
	{
		write(1, "0X", 2);
		len += 2;
	}
	if (f.zero == 1 && fie > f.precision && fie > 0)
		lenf.nb_zero = fie;
	else
		lenf.nb_zero = f.precision - lenf.nb_len;
	len = nubm(f, lenf, len, nb);
	return (len);
}

static int		utilities(t_flags f, t_len l, char *print, unsigned long long n)
{
	if (f.minus == 1)
	{
		l.len += print_number(print, f, n, f.precision);
		while (l.len < (int)f.len_field)
			l.len += ft_putchar(' ');
	}
	else
	{
		while (l.len < (int)f.len_field - l.tmp_len && f.zero != 1)
			l.len += ft_putchar(' ');
		l.len += print_number(print, f, n, (int)f.len_field - l.tmp_len);
	}
	return (l.len);
}

static void		capitalize(char *print)
{
	int		i;

	i = 0;
	while (print[i] != '\0')
	{
		print[i] = ft_toupper(print[i]);
		i++;
	}
}

int				ft_printf_x2(va_list ap, t_flags f)
{
	t_len				lenf;
	unsigned long long	nb;
	char				*print;

	lenf.len = 0;
	lenf.tmp_len = 0;
	nb = unsigned_check(ap, f);
	print = ft_itoa_base(nb, 16);
	capitalize(print);
	if (f.hashtag == 1)
		lenf.tmp_len += 2;
	if ((int)ft_strlen(print) < f.precision)
		lenf.tmp_len += f.precision;
	else
		lenf.tmp_len += ft_strlen(print);
	if (lenf.tmp_len >= (int)f.len_field)
		lenf.len += print_number(print, f, nb, f.precision);
	else
		lenf.len = utilities(f, lenf, print, nb);
	free(print);
	return (lenf.len);
}
