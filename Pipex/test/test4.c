#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	int i;

	i = 0;
	while (*envp)
	{
		printf("%s\n", *envp++);
	}
	return (0);
}
