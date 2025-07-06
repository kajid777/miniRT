/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:26:19 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/06 20:37:16 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	gnl_strlen(char *s);
char	*ft_strnjoin(char *s1, char *s2, int n);
void	*gnl_memmove(void *dest, const void *src, int num);
void	gnl_bzero(char *m, int size);
char	*gnl_strchr(char *s, int c);

#endif