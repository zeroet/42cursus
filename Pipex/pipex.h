/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:21:33 by seyun             #+#    #+#             */
/*   Updated: 2021/10/30 16:04:23 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h> // pipe
# include <sys/wait.h>
# define P_READ 0
# define P_WRITE 1

typedef struct s_input
{
	int argc;
	char **argv;
	char **envp;
}	t_input;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
static size_t	get_row(char const *s, char c);
int	ft_memcmp(const void *p1, const void *p2, size_t size);

#endif
