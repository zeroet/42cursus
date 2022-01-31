/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:16:39 by jseo              #+#    #+#             */
/*   Updated: 2022/01/01 15:52:27 by jseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** builtin_pwd ()		- Pwd Command in Shell
**
** return				- Exit Code (Such as Value from Exec Function)
** path					- Absolute Path to Print
*/

int	builtin_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		return (BUILTIN);
	jputendl(path, STDOUT_FILENO);
	jfree((void **)(&path));
	return (VALID);
}
