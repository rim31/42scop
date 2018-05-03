/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:54:47 by oseng             #+#    #+#             */
/*   Updated: 2016/06/12 12:11:52 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "get_next_line.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct			s_flags
{
	int					hashtag;
	int					plus;
	int					minus;
	int					zero;
	int					space;
	int					precision;
	unsigned int		len_field;
	char				len_modifier;
	char				len_modifier2;
}						t_flags;

typedef struct			s_param
{
	unsigned int		len;
	unsigned int		nb_print;
	char				print;
}						t_param;

typedef struct			s_print
{
	int					nb_len;
	int					nb_zero;
	unsigned long long	n;
}						t_print;

typedef struct			s_len
{
	int					len;
	int					tmp_len;
}						t_len;

int						ft_printf(const char *format, ...);
int						ft_printf_c(char c, t_flags f);
int						ft_printf_c2(wchar_t c, t_flags f);
int						ft_printf_d(va_list ap, t_flags f);
int						ft_printf_d2(long int nb, t_flags f);
int						ft_printf_x(va_list ap, t_flags f);
int						ft_printf_x2(va_list ap, t_flags f);
int						ft_printf_o(va_list	ap, t_flags f);
int						ft_printf_o2(unsigned long nb, t_flags f);
int						ft_printf_u(va_list	ap, t_flags f);
int						ft_printf_u2(unsigned long long nb, t_flags f);
int						ft_printf_s(char *str, t_flags f);
int						ft_printf_s2(wchar_t *str, t_flags f);
int						ft_printf_p(unsigned long nb, t_flags f);
int						ft_printf_percentage(t_flags f);
int						ft_putwchar(wchar_t n);
int						ft_putwstr(wchar_t *str, size_t len);
int						ft_wstrlen(wchar_t *str);
int						ft_nwstrlen(wchar_t *str, int len);
int						parser(const char *format, va_list ap, int *i);
int						ft_isconv(int c);
int						ft_printf_no_conv(const char *format, int end, int *p);
void					flags(t_flags *f, char *comp, char *conv);
void					len_modifier(t_flags *f, char *comp, char *conv);
unsigned long long		unsigned_check(va_list ap, t_flags f);
long long int			signed_check(va_list ap, t_flags f);

#endif
