# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 17:53:15 by dkajiwar          #+#    #+#              #
#    Updated: 2024/09/02 23:12:43 by dkajiwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEAD = ft_printf.h
SRCS = ft_printf.c ft_printf_utils.c ft_print_ptr.c ft_print_hex.c ft_print_unsigned.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft_srcs
	cp ./libft_srcs/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
	make clean -C libft_srcs/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft_srcs/

re: fclean all