/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:40:33 by seyun             #+#    #+#             */
/*   Updated: 2021/01/08 13:36:51 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef OPEN_MAX
# define OPEN_MAX 32
# endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(char *ptr);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strdup(const char *ptr);

#endif
