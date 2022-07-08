#include "../include/libft.h"

int	ft_strchrpos(char *s, int c)
{
	char	*p;

	p = ft_strchr(s, c);
	if (p != NULL)
		return ((int)((char *)p - (char *)s));
	return (-1);
}
