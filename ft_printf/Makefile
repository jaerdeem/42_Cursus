# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalkan <andrespathway@hotmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:56:59 by aalkan            #+#    #+#              #
#    Updated: 2022/10/26 14:25:00 by aalkan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a
CC		:= gcc
CFLAGS  := -Wall -Wextra -Werror -I. -c
FILES   := i_hate_norm_rules.c printf.c
OBJ		:= $(FILES:%.c=%.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

norm:
	norminette *.[ch]

.PHONY: all clean fclean re