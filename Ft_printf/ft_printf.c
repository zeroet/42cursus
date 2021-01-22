/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:06:28 by seyun             #+#    #+#             */
/*   Updated: 2021/01/22 15:18:40 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.f"

void		check_flag(char *format, t_info *info)
{
	if (*format == 0 || 
}

int			run_printf(va_list ap, char *format)
{
	int i;
	int res;
	t_info *info;

	i = 0;
	res = 0;
	info = 0;
	while (format[i] != '\0')
	{
		init_info(info);
		if (format[i] != '%')
			res += ft_putchar(format[i++]);
		while (format[++i] != '%' && format[i] != '\0')
			check_flag(format[i], info);

}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	va_start(ap, format);
	res = run_printf(ap, (char*)format);
	va_end(ap);
	return (res);
}
