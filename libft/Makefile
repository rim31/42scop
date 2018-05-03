# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseng    <oseng   @student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 14:59:47 by oseng             #+#    #+#              #
#    Updated: 2017/11/25 11:03:30 by oseng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

CPFLAGS = -I ./includes

NAME = libft.a

SRC_PATH = srcs

OBJ_PATH = obj

SRC_NAME = libft/ft_isdigit.c \
		   libft/ft_memcmp.c \
		   libft/ft_putchar_fd.c \
		   libft/ft_putstr_fd.c \
		   libft/ft_strdel.c \
		   libft/ft_strlcat.c \
		   libft/ft_strncpy.c \
		   libft/ft_strstr.c \
		   libft/ft_atoi.c \
		   libft/ft_atol.c \
		   libft/ft_atof.c \
		   libft/ft_isprint.c \
		   libft/ft_memcpy.c \
		   libft/ft_putendl.c \
		   libft/ft_strcat.c \
		   libft/ft_strdup.c \
		   libft/ft_strlen.c \
		   libft/ft_strnequ.c \
		   libft/ft_strsub.c \
		   libft/ft_bzero.c \
		   libft/ft_itoa.c \
		   libft/ft_itoa_base.c \
		   libft/ft_memdel.c \
		   libft/ft_putendl_fd.c \
		   libft/ft_strchr.c \
		   libft/ft_strequ.c \
		   libft/ft_strmap.c \
		   libft/ft_strnew.c \
		   libft/ft_strtrim.c \
		   libft/ft_isalnum.c \
		   libft/ft_memalloc.c \
		   libft/ft_memmove.c \
		   libft/ft_putnbr.c \
		   libft/ft_strclr.c \
		   libft/ft_striter.c \
		   libft/ft_strmapi.c \
		   libft/ft_strnstr.c \
		   libft/ft_tolower.c \
		   libft/ft_isalpha.c \
		   libft/ft_memccpy.c \
		   libft/ft_memset.c \
		   libft/ft_putnbr_fd.c \
		   libft/ft_strcmp.c \
		   libft/ft_striteri.c \
		   libft/ft_strncat.c \
		   libft/ft_strrchr.c \
		   libft/ft_toupper.c \
		   libft/ft_isascii.c \
		   libft/ft_memchr.c \
		   libft/ft_putchar.c \
		   libft/ft_putstr.c \
		   libft/ft_strcpy.c \
		   libft/ft_strjoin.c \
		   libft/ft_strncmp.c \
		   libft/ft_strsplit.c \
		   libft/ft_reverse.c \
		   libft/ft_lstdelone.c \
		   libft/ft_lstdel.c \
		   libft/ft_lstnew.c \
		   libft/ft_lstiter.c \
		   libft/ft_lstadd.c \
		   libft/get_next_line.c \
		   libftprintf/ft_printf.c \
		   libftprintf/ft_printf_conversion_s.c \
		   libftprintf/ft_printf_conversion_ls.c \
		   libftprintf/ft_printf_conversion_c.c \
		   libftprintf/ft_printf_conversion_lc.c \
		   libftprintf/ft_printf_conversion_d.c \
		   libftprintf/ft_printf_conversion_ld.c \
		   libftprintf/ft_printf_conversion_x.c \
		   libftprintf/ft_printf_conversion_o.c \
		   libftprintf/ft_printf_conversion_lo.c \
		   libftprintf/ft_printf_conversion_u.c \
		   libftprintf/ft_printf_conversion_lu.c \
		   libftprintf/ft_printf_conversion_xmaj.c \
		   libftprintf/ft_printf_conversion_p.c \
		   libftprintf/ft_printf_flags.c \
		   libftprintf/ft_printf_percentage.c \
		   libftprintf/parser.c \
		   libftprintf/ft_printf_len_modifier.c \
		   libftprintf/unsigned_check.c\
		   libftprintf/signed_check.c\
		   libftprintf/ft_putwchar.c \
		   libftprintf/ft_putwstr.c \
		   libftprintf/ft_wstrlen.c \
		   libftprintf/ft_isconv.c \
		   libftprintf/ft_printf_no_conv.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)/libft 2> /dev/null || true
	@mkdir $(OBJ_PATH)/libftprintf 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
