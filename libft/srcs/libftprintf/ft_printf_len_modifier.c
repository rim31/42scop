/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len_modifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:35:58 by oseng             #+#    #+#             */
/*   Updated: 2016/03/14 15:40:37 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		len_modifier(t_flags *f, char *cmp, char *conv)
{
	int		i;

	i = 0;
	while (cmp[i] != '\0')
	{
		if (cmp[i] == 'h' || cmp[i] == 'l' || cmp[i] == 'j' || cmp[i] == 'z')
			f->len_modifier = cmp[i];
		if ((cmp[i] == 'h' || cmp[i] == 'l') && cmp[i + 1] == cmp[i])
			f->len_modifier2 = cmp[i];
		i++;
	}
	if (f->len_modifier == 'l' && f->len_modifier2 != f->len_modifier)
	{
		if (*conv == 'i')
			*conv = 'd';
		if (*conv == 's' || *conv == 'd' || *conv == 'o' || *conv == 'u'
			|| *conv == 'c')
			*conv -= 32;
	}
}
