/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_d.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:23:08 by oseng             #+#    #+#             */
/*   Updated: 2016/04/02 13:09:06 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print(t_print l, t_flags f, int len, char *nb)
{
	int		i;

	i = 0;
	if (l.nb_zero > 0 || f.precision > l.nb_len)
	{
		len += l.nb_zero + l.nb_len;
		while (i < l.nb_zero)
			i += ft_putchar('0');
		if (nb[0] == '-')
			write(1, &nb[1], l.nb_len);
		else
			write(1, nb, l.nb_len);
	}
	else
	{
		len += l.nb_len;
		if (f.precision == 0 && ft_strcmp("0", nb) == 0 && f.len_field > 0)
			write(1, " ", 1);
		else if (nb[0] == '-')
			write(1, &nb[1], l.nb_len);
		else
			write(1, nb, l.nb_len);
	}
	return (len);
}

static int		print_number(char *nb, t_flags f, long long int nbr, int field)
{
	int			len;
	t_print		l;

	len = 0;
	l.nb_len = ft_strlen(nb);
	if (nbr < 0)
		l.nb_len -= 1;
	else if (f.precision == 0 && ft_strcmp("0", nb) == 0 && f.len_field == 0)
		l.nb_len = 0;
	if (f.zero == 1 && field > f.precision && field > 0)
		l.nb_zero = field;
	else
		l.nb_zero = f.precision - l.nb_len;
	if (((f.plus == 1 || f.space == 1) && nbr >= 0) || nbr < 0)
	{
		if (nbr < 0)
			len += ft_putchar('-');
		else if (f.plus == 1)
			len += ft_putchar('+');
		else
			len += ft_putchar(' ');
	}
	len = print(l, f, len, nb);
	return (len);
}

static int		choice(t_len l, t_flags f, long long int nb, char *print)
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

int				ft_printf_d(va_list ap, t_flags f)
{
	t_len				l;
	long long int		nb;
	char				*print;
	int					sign;

	l.len = 0;
	sign = 0;
	nb = signed_check(ap, f);
	if (nb < 0)
		sign = 1;
	l.tmp_len = sign;
	print = ft_itoa(nb);
	if ((f.plus == 1 || f.space == 1) && nb >= 0)
		l.tmp_len += 1;
	if ((int)ft_strlen(&print[sign]) < f.precision)
		l.tmp_len += f.precision;
	else
		l.tmp_len += ft_strlen(&print[sign]);
	if (l.tmp_len >= (int)f.len_field)
		l.len += print_number(print, f, nb, f.precision);
	else
		l.len = choice(l, f, nb, print);
	free(print);
	return (l.len);
}
