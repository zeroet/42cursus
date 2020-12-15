/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:43:23 by seyun             #+#    #+#             */
/*   Updated: 2020/12/15 12:53:22 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				ft_bzero(void *dest, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				ft_memset(void *dest, int val, size_t size);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t size, size_t count);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t size);
void				*ft_memchr(const void *ptr, int value, size_t size);
int					ft_memcmp(const void *p1, const void *p2, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *ptr);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				strlcpy(char *dest, const char *src, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif
