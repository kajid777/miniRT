# minilibx_test
NAME		=	miniRT
SRCS		=	main.c \
				end_exit.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \

OBJS 		=	$(SRCS:.c=.o)
# Compiler
CC			=	cc
CFLAGS       = -Wall -Wextra -Werror
LIBX_FLAGS	=	-L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm
FT_PRINTF	=	-L./ft_printf -lftprintf
# Rules
all:		$(NAME)

$(NAME):	$(OBJS)
			make -C ./ft_printf
			make -C ./minilibx-linux
			$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(LIBX_FLAGS) -o $(NAME)

clean:
			make -C ./ft_printf clean
			make -C ./minilibx-linux clean
			$(RM) $(OBJS)

fclean:		clean
			make -C ./ft_printf fclean
			make -C ./minilibx-linux clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
