/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:40:33 by seyun             #+#    #+#             */
/*   Updated: 2021/01/07 21:12:14 by seyun            ###   ########.fr       */
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


#endif
