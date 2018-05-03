/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_no_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:29:40 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 13:25:12 by oseng            ###   ########.fr       */
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

int				ft_printf_no_conv(const char *format, int end, int *p)
{
	int			i;
	char		*str;
	int			len;
	t_flags		f;

	i = end;
	len = 0;
	init(&f);
	while (ft_isdigit(format[i]) > 0 || format[i] == '-' || format[i] == '+'
		|| format[i] == 'h' || format[i] == 'l' || format[i] == 'j'
		|| format[i] == ' ' || format[i] == 'z' || format[i] == '.'
		|| format[i] == '#')
		i++;
	if (format[i] == '\0')
		return (0);
	str = ft_strsub(format, end, i - end);
	flags(&f, str, &str[end]);
	len += ft_printf_c(format[i], f);
	*p = i;
	free(str);
	return (len);
}
