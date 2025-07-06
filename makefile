# minilibx_test
NAME		=	miniRT

# Source files
SRCS		=	main.c \
				modules/errors/end_exit.c \
				modules/errors/free_world.c \
				modules/get_next_line/get_next_line.c \
				modules/get_next_line/get_next_line_utils.c \
				modules/parse/parse_1.c \
				modules/parse/parse_2.c \
				modules/parse/ft_split_set.c \
				modules/parse/ft_split_set_2.c \
				modules/parse/ft_split_set_3.c \
				modules/parse/ray.c \
				modules/parse/set_colors.c \
				modules/parse/set_validation.c \
				modules/parse/set_basic_elements.c \
				modules/parse/set_spheres.c \
				modules/parse/set_planes.c \
				modules/parse/set_cylinders.c \
				modules/parse/ft_atod.c \
				modules/generate_rays/generate_rays.c \
				modules/generate_rays/camera_prepare.c \
				modules/generate_rays/ray_generation.c \
				modules/generate_rays/ray_intersection.c \
				modules/generate_rays/ray_lighting.c \
				modules/generate_rays/rendering.c \
				modules/intersect_sphere/intersect_sphere.c \
				modules/intersect_plane/intersect_plane.c \
				modules/intersect_cylinder/intersect_cylinder.c \
				modules/intersect_cylinder/cylinder_calc.c \
				modules/intersect_cylinder/cylinder_utils.c \
				modules/intersect_utils.c \
				modules/intersect_utils_basic.c \
				modules/vector_cal/vector_cal.c \
				modules/vector_cal/vector_basic.c \
				modules/vector_cal/vector_ops.c \
				modules/color_cal/color.c \

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
