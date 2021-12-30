#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char **line = {"hi \n my name \n is", "42 \n", "seyun\n"};
	char *res = NULL;

	res = get_next_line(line);
	printf("%s\n", res);
	return (0);
}
