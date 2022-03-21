/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkan <aalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:22:26 by aalkan            #+#    #+#             */
/*   Updated: 2022/03/09 13:32:12 by aalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = libft.a
list=ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_memcpy.c \
        ft_memset.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_tolower.c \
        ft_toupper.c \
        ft_strncmp.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_strnstr.c \
        ft_strlen.c \
        ft_bzero.c \
        ft_strdup.c \
        ft_atoi.c \
        ft_calloc.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_substr.c \
        ft_strjoin.c \
        ft_strtrim.c \
        ft_memmove.c \
        ft_putchar_fd.c \
        ft_putstr_fd.c \
        ft_split.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        ft_itoa.c \
        ft_strmapi.c \
        ft_striteri.c

OBJS = $(list:.c=.o)
bonusobj = $(bonuslist:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME)

.c.o:
    $(CC) -c $(CFLAGS) $<

$(NAME): $(OBJS)
    ar -rcs $(NAME) $(OBJS)

clean:
    rm -f $(OBJS) $(bonusobj)

fclean: clean
    rm -f $(NAME)

re:fclean $(NAME)

bonus:  $(bonusobj) $(OBJS)
    ar -rcs $(NAME) $(bonusobj) $(OBJS)

norm:
    norminette *.[ch]
.PHONY: clean fclean all re bonus norm
