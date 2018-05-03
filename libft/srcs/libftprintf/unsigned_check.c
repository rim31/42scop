/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 14:31:46 by oseng             #+#    #+#             */
/*   Updated: 2016/03/15 16:39:38 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long			unsigned_check(va_list ap, t_flags f)
{
	unsigned long long		ret;

	if (f.len_modifier == 'l' && f.len_modifier2 != f.len_modifier)
		ret = va_arg(ap, unsigned long);
	else if (f.len_modifier == 'l' && f.len_modifier2 == f.len_modifier)
		ret = va_arg(ap, unsigned long long);
	else if (f.len_modifier == 'h' && f.len_modifier2 == f.len_modifier)
		ret = (unsigned char)va_arg(ap, unsigned int);
	else if (f.len_modifier == 'h' && f.len_modifier2 != f.len_modifier)
		ret = (unsigned short)va_arg(ap, unsigned int);
	else if (f.len_modifier == 'j')
		ret = va_arg(ap, uintmax_t);
	else if (f.len_modifier == 'z')
		ret = va_arg(ap, size_t);
	else
		ret = va_arg(ap, unsigned int);
	return (ret);
}
