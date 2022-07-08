#include "../../include/minishell.h"

int	error_free(int ret, const char *perror_str)
{
	print_perror(ret, perror_str);
	free_all_globals();
	return (ret);
}
