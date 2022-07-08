#include "../../include/minishell.h"

int	export_endl_worker(char *str, int i)
{
	char	*tmp_str;
	char	*old_val;

	tmp_str = ft_strdupn(str, i);
	old_val = get_envp_by_name(g_sh.envp, tmp_str, i);
	if (old_val && *(old_val - 1) == '=')
	{
		free(tmp_str);
		return (0);
	}
	if (!set_envp_by_name(&g_sh.envp, tmp_str, NULL))
	{
		free(tmp_str);
		return (-1);
	}
	free(tmp_str);
	return (0);
}

int	export_equal_worker(char *str, int i)
{
	char	*tmp_str;

	tmp_str = ft_strdupn(str, i);
	i++;
	if (!set_envp_by_name(&g_sh.envp, tmp_str, str + i))
	{
		free(tmp_str);
		return (-1);
	}
	free(tmp_str);
	return (0);
}

int	export_plus_worker(char *str, int i)
{
	char	*tmp_str;
	char	*old_val;

	tmp_str = ft_strdupn(str, ++i - 2);
	if (!tmp_str)
		return (-1);
	old_val = get_envp_by_name(g_sh.envp, tmp_str, i - 2);
	if (old_val)
		old_val = ft_strjoin(old_val, str + i);
	else
		old_val = ft_strjoin("", str + i);
	if (!old_val)
	{
		free(tmp_str);
		return (-1);
	}
	if (!set_envp_by_name(&g_sh.envp, tmp_str, old_val))
	{
		free(old_val);
		free(tmp_str);
		return (-1);
	}
	free(old_val);
	free(tmp_str);
	return (0);
}
