/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:52:08 by oseng             #+#    #+#             */
/*   Updated: 2016/03/30 18:25:02 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		init_field(t_flags *f, char *comp, int i)
{
	if (i == 0 && ft_isdigit(comp[i]) > 0 && comp[i] != '0')
	{
		while (ft_isdigit(comp[i]) > 0)
		{
			f->len_field *= 10;
			f->len_field += comp[i] - 48;
			i++;
		}
		return (-1);
	}
	else if (ft_isdigit(comp[i]) > 0 && comp[i] != '0')
	{
		if ((comp[i - 1] <= '0' || comp[i - 1] > '9') && comp[i - 1] != '.')
		{
			while (ft_isdigit(comp[i]) > 0)
			{
				f->len_field *= 10;
				f->len_field += comp[i] - 48;
				i++;
			}
			return (-1);
		}
	}
	return (i);
}

static void		len_field(t_flags *f, char *comp)
{
	int		i;

	i = 0;
	while (comp[i] != '\0')
	{
		i = init_field(f, comp, i);
		if (i == -1)
			return ;
		i++;
	}
}

static void		zero(t_flags *f, char *comp, char conv)
{
	int		i;

	i = 0;
	if (f->precision >= 0 && (conv == 'd' || conv == 'i' || conv == 'x'
		|| conv == 'X' || conv == 'u' || conv == 'o'))
		f->zero = 0;
	else
		while (comp[i] != '\0')
		{
			if (comp[i] == '0')
			{
				if (i == 0)
				{
					f->zero = 1;
					return ;
				}
				else if (i > 0)
					if (ft_isdigit(comp[i - 1]) == 0)
					{
						f->zero = 1;
						return ;
					}
			}
			i++;
		}
}

static void		init(t_flags *f, char *comp)
{
	if (ft_strchr(comp, '-') != NULL)
		f->minus = 1;
	if (ft_strchr(comp, '#') != NULL)
		f->hashtag = 1;
	if (ft_strchr(comp, '+') != NULL)
		f->plus = 1;
	if (ft_strchr(comp, ' ') != NULL && f->plus == 0)
		f->space = 1;
}

void			flags(t_flags *f, char *comp, char *conv)
{
	char	*tmp;
	int		i;

	i = 1;
	init(f, comp);
	if ((tmp = ft_strchr(comp, '.')) != NULL)
	{
		if (ft_isdigit(tmp[i]) == 0
			|| (tmp[i - 1] == '.' && ft_isdigit(tmp[i]) == 0))
			f->precision = 0;
		else
		{
			f->precision = 0;
			while (ft_isdigit(tmp[i]) > 0)
			{
				f->precision *= 10;
				f->precision += tmp[i] - 48;
				i++;
			}
		}
	}
	zero(f, comp, *conv);
	len_field(f, comp);
	len_modifier(f, comp, conv);
}
