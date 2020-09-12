
char	*ft_strrchr(const char *s, int c)
{
	const char *res;

	if (*s == '\0')
		return (0);
	res = 0;
	while (*s)
	{
		if (*s == (char)c)
			res = s;
		s++;
	}
	return ((char*)res);
}
