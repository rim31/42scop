/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:49:04 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 11:55:38 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		test(const char *format, int i)
{
	while (ft_isdigit(format[i]) > 0 || format[i] == '-' || format[i] == '+'
		|| format[i] == 'h' || format[i] == 'l' || format[i] == 'j'
		|| format[i] == ' ' || format[i] == 'z' || format[i] == '.'
		|| format[i] == '#')
		i++;
	if (ft_isconv(format[i]) == 0)
		return (1);
	else
		return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	int			i;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (test(format, i + 1) == 1)
				len += ft_printf_no_conv(format, i + 1, &i);
			else
				len += parser(format, ap, &i);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
