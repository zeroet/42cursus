#include "../../include/minishell.h"

int	print_perror(int ret, const char *perror_str)
{
	ft_putstr_fd("minishell: ", 2);
	perror(perror_str);
	return (ret);
}
