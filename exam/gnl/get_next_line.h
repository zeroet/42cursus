/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:47:23 by seyun             #+#    #+#             */
/*   Updated: 2022/02/08 16:48:30 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_chr_newline(char *buf);
char	*ft_put_line(char *buf);
char	*ft_return_left(char *buf, int index_r);
int		ft_strlen(char *s);
char	*ft_strjoin(char *left, char *buf);
char	*ft_strdup(char *s);
char	*ft_clean(char **left, char *buf);
char	*ft_joinleft(char **left, int fd);

#endif

