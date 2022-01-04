#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int fd;
	char *res;

	res = NULL;
	fd = open("test.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s\n", res);
	return (0);
}
