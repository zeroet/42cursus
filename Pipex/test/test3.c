#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int i;
	char **cmd;

	i = 0;
	cmd = (char **)malloc(5 * sizeof(char *));
	if (!cmd)
		exit(1);
	cmd[0] = "/usr/local/bin";
	cmd[1] = "/usr/bin/";
	cmd[2] = "/usr/bin/sbin";
	cmd[3] = "/usr/local/go/bin";
	cmd[4] = "/usr/local/munki";
	while(i < 5)
	{
		printf("%s\n", cmd[i]);
		i++;
	}
	return (0);
}
