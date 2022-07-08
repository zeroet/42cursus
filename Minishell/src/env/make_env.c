#include "../../include/minishell.h"

char	**make_env(char *env[])
{
	char	**envp;
	int		i;
	int		len;

	i = 0;
	len = ptr_arr_len((void **)env);
	envp = (char **)malloc((sizeof(char *) * (len + 1)));
	if (!envp)
		return (NULL);
	while (i < len)
	{
		envp[i] = ft_strdup(env[i]);
		i++;
	}
	envp[i] = NULL;
	return (envp);
}
