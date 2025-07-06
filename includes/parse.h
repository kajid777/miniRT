/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:51:14 by hthomas           #+#    #+#             */
/*   Updated: 2025/07/06 19:21:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "types.h"

# define WHITE_SPACES " \t"
# define NB_ELEM_RESOLUTION 3
# define NB_ELEM_AL 3
# define NB_ELEM_CAMERA 4
# define NB_ELEM_LIGHT 4
# define NB_ELEM_SPHERE 4
# define NB_ELEM_PLANE 4
# define NB_ELEM_SQUARE 5
# define NB_ELEM_CYLINDER 6
# define NB_ELEM_TRIANGLE 5

/* ft_atod.c */
double		ten_to(int pow);
double		dot_part(const char *str, int *len);
double		ft_atod(const char *str);

/* parse_1.c */
int			ft_strcmp(const char *s1, const char *s2);
int			ft_tab_size(char **tab);
bool		ft_is_from_charset(const char *str, const char *charset);

/* parse_2.c */
void		*init_world(t_world *world);
bool		check_line(const char *line, char **data, const char *type,
				const int nb_elements);
t_world		*parse(int fd);
t_world		*get_world(const int argc, char *argv[]);

/* ft_split_set.c */
void		ft_free_tab(char **tab);
int			is_in_charset(char c, const char *charset);
int			count_segments_set(const char *str, const char *charset);

/* ft_split_set_2.c */
char		**ft_split_set(const char *str, const char *charset);

/* ray.c */
t_vec3		set_vect(char **tab);
t_vec3		str_to_vect(const char *str, t_world *world);
t_fcolor	str_to_rgb(const char *str, t_world *world);
t_fcolor	char_to_rgb(const char *r, const char *g, const char *b,
				t_world *world);

/* set_elements.c */
void		set_ambient_light(t_world *world, t_parse_ctx *ctx);
void		set_camera(t_world *world, t_parse_ctx *ctx);
void		set_light(t_world *world, t_parse_ctx *ctx);
t_fcolor	*mult_rgb_rgb(const t_fcolor rgb, const t_fcolor mult);

/* set_elements2.c */
void		set_sphere(t_world *world, t_parse_ctx *ctx);
void		set_plane(t_world *world, t_parse_ctx *ctx);
void		set_cylinder(t_world *world, t_parse_ctx *ctx);

#endif
