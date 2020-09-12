
/* strchr - Find the first occurrence of a char in a string
   @s : the string to be searched
   @c : the char to search for 
*/

char	*ft_strchr(const char *s, int c)
{
	if (*s == '\0')
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
