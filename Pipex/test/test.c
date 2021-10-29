/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:51:26 by seyun             #+#    #+#             */
/*   Updated: 2021/10/28 19:12:14 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char	**args;
	int		i;

	i = -1;
	args = (char **)malloc(argc * sizeof(char *));
	args[argc] = NULL;
	if (!args)
		return (0);
	while (++i < argc - 1)
		args[i] = argv[i + 1];
	execv("./test2", args);
	printf("hi");
	return (0);
}
