#include "../../include/minishell.h"

void	free_cmd_arr(void)
{
	int	i;

	if (!g_sh.cmd)
		return ;
	i = 0;
	while (g_sh.cmd[i])
	{
		close_redirects(g_sh.cmd[i]->redirects);
		ft_lstclear(&g_sh.cmd[i]->redirects, free_redirect_data);
		char_array_free(g_sh.cmd[i]->argv);
		free(g_sh.cmd[i]);
		i++;
	}
	free(g_sh.cmd);
	g_sh.cmd = NULL;
}
