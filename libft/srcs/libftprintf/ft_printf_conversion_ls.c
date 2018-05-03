/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_ls.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:39:18 by oseng             #+#    #+#             */
/*   Updated: 2016/04/03 12:35:07 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		normal(t_param p, t_flags f, wchar_t *str)
{
	if (f.zero == 1)
		p.print = '0';
	if ((int)ft_wstrlen(str) > f.precision && f.precision > 0)
		p.nb_print = ft_nwstrlen(str, f.precision);
	while (p.len < f.len_field - p.nb_print)
		p.len += ft_putchar(p.print);
	if (p.nb_print > 0)
	{
		if (str == NULL)
		{
			write(1, "(null)", p.nb_print);
			p.len += p.nb_print;
		}
		else
			p.len += ft_putwstr(str, p.nb_print);
	}
	return (p.len);
}

static int		minus(t_param p, t_flags f, wchar_t *str)
{
	if (str == NULL)
	{
		write(1, "(null)", p.nb_print);
		p.len += p.nb_print;
	}
	else
		p.len += ft_putwstr(str, p.nb_print);
	while (p.len < f.len_field)
		p.len += ft_putchar(p.print);
	return (p.len);
}

int				ft_printf_s2(wchar_t *str, t_flags f)
{
	t_param		p;

	p.print = ' ';
	if ((int)ft_wstrlen(str) > f.precision && f.precision >= 0)
		p.nb_print = f.precision;
	else
		p.nb_print = ft_wstrlen(str);
	p.len = 0;
	if (p.nb_print >= f.len_field)
	{
		if (str == NULL)
		{
			write(1, "(null)", p.nb_print);
			p.len += p.nb_print;
		}
		else
			p.len += ft_putwstr(str, p.nb_print);
		return (p.len);
	}
	else if (f.minus == 1)
		p.len = minus(p, f, str);
	else
		p.len = normal(p, f, str);
	return (p.len);
}
