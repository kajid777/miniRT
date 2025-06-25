/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:21:27 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/27 10:41:13 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

// シーン構造体の各要素を初期化する関数
void *init_world(t_world *world)
{
	world->al.ratio = 0;
	world->al.color.r = 0;
	world->al.color.g = 0;
	world->al.color.b = 0;
	world->cameras = ft_lstnew(NULL);
	world->lights = ft_lstnew(NULL);
	world->spheres = ft_lstnew(NULL);
	world->planes = ft_lstnew(NULL);
	world->squares = ft_lstnew(NULL);
	world->cylinders = ft_lstnew(NULL);
	world->triangles = ft_lstnew(NULL);
	return (world);
}

// 指定された行が特定の型・要素数かどうかを判定する関数
bool	check_line(const char *line, char **data, const char *type, const int nb_elements)
{
	if (!ft_strcmp(data[0], type))
	{
		if (ft_in_charset(line[ft_strlen(type)], WHITE_SPACES))
			return (ft_tab_size(data) == nb_elements);
	}
	return (0);
}

// ファイルディスクリプタからシーン情報をパースしてt_world構造体に格納する関数
// 各行ごとに要素タイプを判定し、対応するセット関数を呼び出す
// パースエラー時はエラー終了する
t_world	*parse(int fd)
{
	t_world	*world;
	char	*line;
	int		ret;
	char	**data;

	if (!(world = malloc(sizeof(*world))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	if (!(init_world(world)))
		return (NULL);
	while ((ret = get_next_line(&line, fd)) == 1)
	{
		data = ft_split_set(line, ' ');//いわゆるスプリット
		if (check_line(line, data, "A", NB_ELEM_AL) && !world->al.ratio)
			set_ambient_light(world, data);
		else if (check_line(line, data, "C", NB_ELEM_CAMERA))
			set_camera(world, data);
		else if (check_line(line, data, "L", NB_ELEM_LIGHT))
			set_light(world, data);
		else if (check_line(line, data, "sp", NB_ELEM_SPHERE))
			set_sphere(world, data);
		else if (check_line(line, data, "pl", NB_ELEM_PLANE))
			set_plane(world, data);
		else if (check_line(line, data, "cy", NB_ELEM_CYLINDER))
			set_cylinder(world, data);
		else if (!ft_is_from_charset(line, WHITE_SPACES))//何も書かれていない行から始まる場合
		{
			free(line);
			free(data);//ここはリークしてしまう、dataは文字列の列だから一個一個freeしないといけない
			print_err_and_exit("Parse error", PARSE_ERROR);
		}
		free(line);
		free(data);
	}
	return (world);
}

// コマンドライン引数を検証し、シーンファイルを開いてパースする関数
// パース後のt_world構造体を返す
t_world	*get_world(const int argc, char *argv[])
{
	int			fd;
	t_world		*world;

	if (argc < 2)
		print_err_and_exit("Error: expecting a '.rt'file", 1);
	if (argc > 3)
		print_err_and_exit("Error: expecting a 2 arguments maximum", 1);
	if (argc == 2 && ft_strncmp_rev(argv[1], ".rt", 3))
		print_err_and_exit("First argument must be a '.rt' file", 1);//終わりの文字がrtでない場合
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		print_err_and_exit(strerror(errno), errno);
	if (!(world = parse(fd)))
		print_err_and_exit("Parsing error", PARSE_ERROR);
	if (close(fd) == -1)
		print_err_and_exit(strerror(errno), errno);
	return (world);
}
