/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:14:02 by thashimo          #+#    #+#             */
/*   Updated: 2024/02/17 22:33:54 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!new)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (j < n && s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	free(s1);
	return (new);
}

void	*gnl_memmove(void *dest, const void *src, int num)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	if (ptr1 == ptr2)
		return (dest);
	if (ptr1 < ptr2 || ptr1 >= ptr2 + num)
	{
		while (num--)
			*ptr1++ = *ptr2++;
	}
	else
	{
		ptr1 += num;
		ptr2 += num;
		while (num--)
			*(--ptr1) = *(--ptr2);
	}
	return (dest);
}

void	gnl_bzero(char *m, int size)
{
	if (!m)
		return ;
	while (size)
	{
		*m = '\0';
		m++;
		size--;
	}
}

char	*gnl_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			return (s);
		}
		s++;
	}
	if (*s == (unsigned char)c)
	{
		return (s);
	}
	return (NULL);
}
