/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flegg <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:50:15 by flegg             #+#    #+#             */
/*   Updated: 2020/11/18 17:54:08 by flegg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	ft_count_words(char const *s, char c)
{
	size_t	res;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static	void	*ft_freemem(char **res, size_t k)
{
	while (k > 0)
	{
		free(res[k - 1]);
		k--;
	}
	free(res);
	return ((void *)0);
}

static	void	ft_setword(char **wstart, char **wend, char c)
{
	while (**wstart == c && **wstart != 0)
		(*wstart)++;
	*wend = *wstart;
	while (**wend != c && **wend != 0)
		(*wend)++;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*wstart;
	char	*wend;
	size_t	k;

	if (!s)
		return ((void *)0);
	res = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return ((void *)0);
	wend = (char *)s;
	k = 0;
	while (k < ft_count_words(s, c))
	{
		wstart = wend;
		ft_setword(&wstart, &wend, c);
		res[k] = (char *)malloc(wend - wstart + sizeof(char));
		if (!res[k])
			return (ft_freemem(res, k));
		ft_memmove(res[k], wstart, (wend - wstart));
		res[k][(wend - wstart) / sizeof(char)] = 0;
		k++;
	}
	res[k] = (void *)0;
	return (res);
}
