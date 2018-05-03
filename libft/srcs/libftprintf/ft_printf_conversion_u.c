/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_u.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:24:08 by oseng             #+#    #+#             */
/*   Updated: 2016/04/02 11:22:16 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print(int nb_len, int nb_zero, char *nb, int len)
{
	int		i;

	i = 0;
	len += nb_zero + nb_len;
	while (i < nb_zero)
		i += ft_putchar('0');
	write(1, nb, nb_len);
	return (len);
}

static int		print_number(char *nb, t_flags f, int field)
{
	int			len;
	int			nb_len;
	int			nb_zero;

	len = 0;
	nb_len = ft_strlen(nb);
	if (f.precision == 0 && ft_strcmp("0", nb) == 0 && f.len_field == 0)
		nb_len = 0;
	if (f.zero == 1 && field > f.precision && field > 0)
		nb_zero = field;
	else
		nb_zero = f.precision - nb_len;
	if (nb_zero > 0 || f.precision > nb_len)
		len = print(nb_len, nb_zero, nb, len);
	else
	{
		len += nb_len;
		if (f.precision == 0 && ft_strcmp("0", nb) == 0 && f.len_field > 0)
			write(1, " ", 1);
		else
			write(1, nb, nb_len);
	}
	return (len);
}

static int		minus(char *print, t_flags f, int len)
{
	len += print_number(print, f, f.precision);
	while (len < (int)f.len_field)
		len += ft_putchar(' ');
	return (len);
}

int				ft_printf_u(va_list ap, t_flags f)
{
	int					len;
	unsigned long long	nb;
	char				*print;
	int					tmp_len;

	len = 0;
	tmp_len = 0;
	nb = unsigned_check(ap, f);
	print = ft_itoa_base(nb, 10);
	if ((int)ft_strlen(print) < f.precision)
		tmp_len += f.precision;
	else
		tmp_len += ft_strlen(print);
	if (tmp_len >= (int)f.len_field)
		len += print_number(print, f, f.precision);
	else if (f.minus == 1)
		len = minus(print, f, len);
	else
	{
		while (len < (int)f.len_field - tmp_len && f.zero != 1)
			len += ft_putchar(' ');
		len += print_number(print, f, (int)f.len_field - tmp_len);
	}
	free(print);
	return (len);
}
