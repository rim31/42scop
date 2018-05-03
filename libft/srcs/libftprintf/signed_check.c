/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:54:15 by oseng             #+#    #+#             */
/*   Updated: 2016/03/15 15:59:01 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int			signed_check(va_list ap, t_flags f)
{
	long long int		ret;

	if (f.len_modifier == 'l' && f.len_modifier2 != f.len_modifier)
		ret = va_arg(ap, long);
	else if (f.len_modifier == 'l' && f.len_modifier2 == f.len_modifier)
		ret = va_arg(ap, long long);
	else if (f.len_modifier == 'h' && f.len_modifier2 == f.len_modifier)
		ret = (signed char)va_arg(ap, int);
	else if (f.len_modifier == 'h' && f.len_modifier2 != f.len_modifier)
		ret = (short)va_arg(ap, int);
	else if (f.len_modifier == 'j')
		ret = va_arg(ap, intmax_t);
	else if (f.len_modifier == 'z')
		ret = va_arg(ap, ssize_t);
	else
		ret = va_arg(ap, int);
	return (ret);
}
