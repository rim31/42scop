/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_ld.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:43:19 by oseng             #+#    #+#             */
/*   Updated: 2016/04/02 11:34:20 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		print(t_flags f, t_len lenf, char *nb, long int nbr)
{
	int		i;

	i = 0;
	if (f.precision > lenf.tmp_len)
	{
		lenf.len += f.precision;
		while (i < f.precision - lenf.tmp_len)
			i += ft_putchar('0');
		if (nbr < 0)
			write(1, &nb[1], lenf.tmp_len);
		else
			write(1, nb, lenf.tmp_len);
	}
	else
	{
		lenf.len += lenf.tmp_len;
		if (nbr < 0)
			write(1, &nb[1], lenf.tmp_len);
		else
			write(1, nb, lenf.tmp_len);
	}
	return (lenf.len);
}

static int		print_number(char *nb, t_flags f, long int nbr)
{
	t_len		lenf;
	int			i;

	lenf.len = 0;
	lenf.tmp_len = ft_strlen(nb);
	if (nbr < 0)
		lenf.tmp_len -= 1;
	i = 0;
	if (((f.plus == 1 || f.space == 1) && nbr > 0) || nbr < 0)
	{
		if (nbr < 0)
			lenf.len += ft_putchar('-');
		else if (f.plus == 1)
			lenf.len += ft_putchar('+');
		else
			lenf.len += ft_putchar(' ');
	}
	lenf.len = print(f, lenf, nb, nbr);
	return (lenf.len);
}

static int		minus(int len, char *print, t_flags f, long int nb)
{
	len += print_number(print, f, nb);
	while (len < (int)f.len_field)
		len += ft_putchar(' ');
	return (len);
}

int				ft_printf_d2(long int nb, t_flags f)
{
	int					len;
	char				*print;
	int					tmp_len;

	len = 0;
	tmp_len = 0;
	print = ft_itoa(nb);
	if (f.plus == 1 && nb > 0)
		tmp_len += 1;
	if ((int)ft_strlen(print) < f.precision)
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
