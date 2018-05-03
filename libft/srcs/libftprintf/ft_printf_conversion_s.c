/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_s.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:23:36 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 13:13:04 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		normal(char *str, t_flags f, t_param p)
{
	if (f.zero == 1)
		p.print = '0';
	while (p.len < f.len_field - p.nb_print)
		p.len += ft_putchar(p.print);
	if (p.nb_print > 0)
		write(1, str, p.nb_print);
	p.len += p.nb_print;
	return (p.len);
}

static int		minus(char *str, t_flags f, t_param p)
{
	write(1, str, p.nb_print);
	p.len += p.nb_print;
	while (p.len < f.len_field)
		p.len += ft_putchar(p.print);
	return (p.len);
}

static int		base(char *str, t_param p, int all)
{
	write(1, str, p.nb_print);
	if (all == 1)
		free(str);
	return (p.nb_print);
}

int				ft_printf_s(char *str, t_flags f)
{
	t_param			p;
	int				all;

	all = 0;
	p.print = ' ';
	if (str == NULL)
	{
		all = 1;
		str = ft_strdup("(null)");
	}
	if ((int)ft_strlen(str) > f.precision && f.precision >= 0)
		p.nb_print = f.precision;
	else
		p.nb_print = ft_strlen(str);
	p.len = 0;
	if (p.nb_print >= f.len_field)
		return (base(str, p, all));
	if (f.minus == 1)
		p.len = minus(str, f, p);
	else
		p.len = normal(str, f, p);
	if (all == 1)
		free(str);
	return (p.len);
}
