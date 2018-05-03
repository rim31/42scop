/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:30:17 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 13:23:03 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		init(t_flags *f)
{
	f->hashtag = 0;
	f->plus = 0;
	f->minus = 0;
	f->zero = 0;
	f->space = 0;
	f->precision = -1;
	f->len_field = 0;
	f->len_modifier = 0;
	f->len_modifier2 = 0;
}

static int		selection2(char c, va_list ap, t_flags f)
{
	if (c == 'u')
		return (ft_printf_u(ap, f));
	else if (c == 'U')
		return (ft_printf_u2(va_arg(ap, unsigned long), f));
	else if (c == 'x')
		return (ft_printf_x(ap, f));
	else if (c == 'X')
		return (ft_printf_x2(ap, f));
	else
		return (-1);
}

static int		selection(char c, va_list ap, t_flags f)
{
	if (c == 'p')
		return (ft_printf_p(va_arg(ap, unsigned long int), f));
	else if (c == '%')
		return (ft_printf_percentage(f));
	else if (c == 'd' || c == 'i')
		return (ft_printf_d(ap, f));
	else if (c == 'c')
		return (ft_printf_c(va_arg(ap, int), f));
	else if (c == 'C')
		return (ft_printf_c2(va_arg(ap, wchar_t), f));
	else if (c == 's')
		return (ft_printf_s(va_arg(ap, char *), f));
	else if (c == 'S')
		return (ft_printf_s2(va_arg(ap, wchar_t *), f));
	else if (c == 'D')
		return (ft_printf_d2(va_arg(ap, long), f));
	else if (c == 'o')
		return (ft_printf_o(ap, f));
	else if (c == 'O')
		return (ft_printf_o2(va_arg(ap, unsigned long), f));
	else
		return (selection2(c, ap, f));
}

int				parser(const char *format, va_list ap, int *i)
{
	t_flags		f;
	int			len;
	int			end;
	char		*sub;
	char		conv;

	*i += 1;
	end = *i;
	conv = 0;
	init(&f);
	while ((len = selection(conv, ap, f)) == -1)
	{
		while (format[end] != 's' && format[end] != 'S' && format[end] != 'p'
			&& format[end] != 'd' && format[end] != 'D' && format[end] != 'o'
			&& format[end] != 'O' && format[end] != 'u' && format[end] != 'U'
			&& format[end] != 'x' && format[end] != 'X' && format[end] != 'c'
			&& format[end] != 'C' && format[end] != 'i' && format[end] != '%')
			end++;
		sub = ft_strsub(format, *i, end - *i);
		conv = format[end];
		flags(&f, sub, &conv);
		*i = end;
	}
	free(sub);
	return (len);
}
