/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:01:48 by seyun             #+#    #+#             */
/*   Updated: 2021/01/16 12:02:28 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
int			ft_strlen(char *s1);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlcpy(char *dest, const char *src, int size);
int			ft_strlcat(char *dest, const char *src, int size);
char		*ft_strdup(char *ptr);

#endif
