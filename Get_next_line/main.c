#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	char *line[200];
	int i;

	if (0 > (fd = open("txt.txt", O_RDONLY)))
		return (0);
	while (1)	
	{
		i = get_next_line(fd, line);
		printf("%s\n", *line);
		if (i == 0 || i == -1)
			break ;
	}
	return (0);
}
