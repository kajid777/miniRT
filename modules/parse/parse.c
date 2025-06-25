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

#include "../../includes/miniRT.h"

// ft_strcmp関数 - 2つの文字列を比較する
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// ft_tab_size関数 - 文字列配列のサイズを返す
int	ft_tab_size(char **tab)
{
	int	size;

	size = 0;
	if (!tab)
		return (0);
	while (tab[size])
		size++;
	return (size);
}

// 文字列配列の全要素をfreeする関数
void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// 文字列が指定された文字セットの文字のみで構成されているかを判定する関数
bool	ft_is_from_charset(const char *str, const char *charset)
{
	int	i;
	int	j;
	bool	found;

	if (!str || !charset)
		return (false);
	i = 0;
	while (str[i])
	{
		found = false;
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				found = true;
				break;
			}
			j++;
		}
		if (!found)
			return (false);
		i++;
	}
	return (true);
}

// シーン構造体の各要素を初期化する関数
void *init_world(t_world *world)
{
    // Initialize ambient lighting
    world->ambient = NULL;
    // Initialize camera
    world->camera = NULL;
    // Initialize light
    world->light = NULL;
    // Initialize new geometry lists
    world->spheres = NULL;
    world->planes = NULL;
    world->cylinders = NULL;
    
    // Initialize MLX related members
    world->mlx = NULL;
    world->win = NULL;    
    return (world);
}

// 指定された行が特定の型・要素数かどうかを判定する関数
bool	check_line(const char *line, char **data, const char *type, const int nb_elements)
{
	if (!line)
		return (false);
	if (!data)
		return (false);
	if (!ft_strcmp(data[0], type))
	{
		// if (ft_in_charset(line[ft_strlen(type)], WHITE_SPACES))
		if (ft_tab_size(data) == nb_elements)
			return (true);
			// return (ft_tab_size(data) == nb_elements);
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
	char	**data;

	if (!(world = malloc(sizeof(*world))))
		exit(0);
	if (!(init_world(world)))
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		data = ft_split_set(line, WHITE_SPACES);//いわゆるスプリット
		if (check_line(line, data, "A", NB_ELEM_AL))
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
			ft_free_tab(data);//文字列配列の全要素をfree
			exit(0);
			// print_err_and_exit("Parse error", PARSE_ERROR);
		}
		free(line);
		ft_free_tab(data);//文字列配列の全要素をfree
		line = get_next_line(fd);
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
