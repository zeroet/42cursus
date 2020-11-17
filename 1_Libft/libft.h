/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:43:23 by seyun             #+#    #+#             */
/*   Updated: 2020/11/17 21:43:28 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	strlcpy(char *dest, const char *src, size_t size);
size_t	strlen(const char *s)
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);


#endif
