#include "../../include/minishell.h"

void	free_all_globals(void)
{
	free_cmd_arr();
	char_array_free(g_sh.envp);
}
