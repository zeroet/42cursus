#include <stdio.h>

int main()
{
	int	i = 42;
	float k = 3.424242;
	char str[4] = "abc";

	printf("%*p\n", 30, &i);
	printf("%06d\n", i);
	printf("%6d\n", i);
	printf("%0*d\n", 6, i);
	printf("%.3s\n", str);
	/*printf("%%");*/
	return (0);
}
