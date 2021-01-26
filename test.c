/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:31:17 by seyun             #+#    #+#             */
/*   Updated: 2021/01/26 13:25:49 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int		ft_test(char *format, ...)
{
	va_list ap;
	char c; 
	int i;
	int j;

	va_start(ap, format);
	c  = va_arg(ap, int);
	i = va_arg(ap, int);
	j = va_arg(ap, int);	
	printf("%c %d %d\n", c, i, j);
	va_end(ap);
	return (0);
}

int main()
{
	int i = 10;

	ft_test("abc", 'c', 42, &i);
	return (0);
}
