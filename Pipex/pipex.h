/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:21:33 by seyun             #+#    #+#             */
/*   Updated: 2021/10/29 18:19:35 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h> // pipe
# include <sys/wait.h>
# define P_READ 0
# define P_WRITE 1

void	child_command();
void	proc_child();
char	*find_path(char **envp, char **args);
void	parent_command();
void	proc_parent(int pid, char **args, char **envp);

#endif
