#include <unistd.h>

int main(void)
{
	char str[4] = {"cub"};
	char *ptr;

	ptr = str;
	write(1, ptr, 4);
	write(1, "\n", 1);
	return (0);
}
