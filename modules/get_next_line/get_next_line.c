/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:32:00 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/06 21:13:39 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buff(int *ret, char *buff, char *str)
{
	int	i;
	int	l_nl;

	i = 0;
	l_nl = 0;
	while (buff[i] && 0 < *ret)
	{
		if (buff[i] == '\n')
		{
			str = ft_strnjoin(str, buff, i + 1);
			*ret = *ret - (i + 1);
			l_nl = gnl_strlen(buff + i + 1);
			gnl_memmove(buff, buff + i + 1, l_nl);
			gnl_bzero(buff + l_nl, gnl_strlen(buff + l_nl));
			return (str);
		}
		i++;
	}
	return (NULL);
}

static char	*read_line(int fd, int *ret, char *buff, char *str)
{
	*ret = read(fd, buff, BUFFER_SIZE);
	if (*ret == 0)
	{
		free(str);
		return (NULL);
	}
	while (0 < *ret)
	{
		if (gnl_strchr(buff, '\n'))
		{
			return (read_buff(ret, buff, str));
		}
		else
		{
			buff[*ret] = '\0';
			str = ft_strnjoin(str, buff, gnl_strlen(buff));
			*ret = read(fd, buff, BUFFER_SIZE);
		}
	}
	if (*ret == -1)
		return (free(str), NULL);
	if (!gnl_strchr(buff, '\n'))
		gnl_bzero(buff, gnl_strlen(buff));
	return (str);
}

static char	*read_nextline(int fd, int *ret, char *buff, char *str)
{
	if (*ret == 0)
	{
		free(str);
		return (NULL);
	}
	while (0 < *ret)
	{
		if (gnl_strchr(buff, '\n'))
		{
			return (read_buff(ret, buff, str));
		}
		else
		{
			buff[*ret] = '\0';
			str = ft_strnjoin(str, buff, gnl_strlen(buff));
			*ret = read(fd, buff, BUFFER_SIZE);
		}
	}
	if (*ret == -1)
		return (free(str), NULL);
	if (!gnl_strchr(buff, '\n'))
		gnl_bzero(buff, gnl_strlen(buff));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1UL];
	char		*str;
	static int	ret;

	if (fd < 0 || read(fd, buff, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(1);
	if (!str)
		return (NULL);
	gnl_bzero(str, 1);
	if (*buff)
		return (read_nextline(fd, &ret, buff, str));
	return (read_line(fd, &ret, buff, str));
}
