/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:12:52 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/06/14 18:33:08 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s == 0)
		return (0);
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	char_size;

	i = 0;
	char_size = ft_strlen(s);
	while (i <= char_size)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return ((char *)(0));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t		*tmp_dest;
	size_t		malloc_size;
	void		*dest;

	if (count && size && count > (4294967295 / size))
		return (NULL);
	malloc_size = count * size;
	tmp_dest = (size_t *)malloc(malloc_size);
	if (tmp_dest == 0)
		return (0);
	ft_bzero(tmp_dest, malloc_size);
	dest = (void *)tmp_dest;
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
