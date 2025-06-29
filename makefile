# minilibx_test
NAME		=	miniRT

# Source files
SRCS		=	main.c \
				modules/end_exit.c \
				modules/get_next_line/get_next_line.c \
				modules/get_next_line/get_next_line_utils.c \
				modules/parse/parse.c \
				modules/parse/parse_utils.c \
				modules/parse/ray.c \
				modules/parse/set_elements.c \
				modules/parse/set_elements2.c \
				modules/parse/ft_atod.c \
				modules/generate_rays/generate_rays.c \
				# modules/intersect_sphere/intersect_sphere.c \
				modules/vector_cal/vector_cal.c

OBJS		=	$(SRCS:.c=.o)

# Compiler
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iincludes -Iminilibx-linux -Ift_printf

# Libraries
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
