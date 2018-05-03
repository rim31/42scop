/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:14:08 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 18:11:17 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		nubm(t_flags f, t_print lenf, int len, char *nb)
{
	int		i;

	i = 0;
	if (lenf.nb_zero > lenf.nb_len || f.precision > lenf.nb_len)
	{
		len += lenf.nb_zero + lenf.nb_len;
		while (i < lenf.nb_zero)
			i += ft_putchar('0');
		write(1, nb, lenf.nb_len);
	}
	else
	{
		len += lenf.nb_len;
		write(1, nb, lenf.nb_len);
	}
	return (len);
}

static int		print_number(char *nb, t_flags f, int field)
{
	int			len;
	t_print		lenf;

	len = 2;
	lenf.nb_len = ft_strlen(nb);
	if (f.precision == 0 && ft_strcmp("0", nb) == 0)
		lenf.nb_len = 0;
	if (f.zero == 1 && field > f.precision)
		lenf.nb_zero = field;
	else
		lenf.nb_zero = f.precision - lenf.nb_len;
	write(1, "0x", 2);
	len = nubm(f, lenf, len, nb);
	return (len);
}

static int		minus(t_flags f, int len, char *print)
{
	len += print_number(print, f, f.precision);
	while (len < (int)f.len_field)
		len += ft_putchar(' ');
	return (len);
}

int				ft_printf_p(unsigned long int nb, t_flags f)
{
	t_len				lenf;
	char				*print;
	char				prt;

	prt = ' ';
	lenf.len = 0;
	lenf.tmp_len = 2;
	print = ft_itoa_base(nb, 16);
	if ((int)ft_strlen(print) < f.precision)
		lenf.tmp_len += f.precision;
	else
		lenf.tmp_len += ft_strlen(print);
	if (lenf.tmp_len >= (int)f.len_field)
		lenf.len += print_number(print, f, (int)f.len_field - lenf.tmp_len);
	else if (f.minus == 1)
		lenf.len = minus(f, lenf.len, print);
	else
	{
		while (lenf.len < (int)f.len_field - lenf.tmp_len && f.zero != 1)
			lenf.len += ft_putchar(prt);
		lenf.len += print_number(print, f, (int)f.len_field - lenf.tmp_len);
	}
	free(print);
	return (lenf.len);
}
