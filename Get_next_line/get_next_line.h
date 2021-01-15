/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:40:33 by seyun             #+#    #+#             */
/*   Updated: 2021/01/15 11:37:24 by seyun            ###   ########.fr       */
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
#include <stdio.h>

int			get_next_line(int fd, char **line);
int			ft_strlen(char *ptr);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlcpy(char *dest, const char *src, int size);
int			ft_strlcat(char *dest, const char *src, int size);
char		*ft_strdup(char *ptr);

#endif
