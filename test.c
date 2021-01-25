/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:31:17 by seyun             #+#    #+#             */
/*   Updated: 2021/01/25 20:07:46 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int		ft_test(int k, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, k);
	while(i < 4)
	{
		printf("%s\n", va_arg(ap, char*));
		i++;
	}
	va_end(ap);
	return (0);
}

int main()
{
	printf("%d\n", ft_test(5, "abc", "cde", "bcd", "asd"));
	printf("%0*.3f\n", 10, 1.4);
	return (0);
}
