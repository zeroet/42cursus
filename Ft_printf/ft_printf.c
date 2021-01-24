/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:06:28 by seyun             #+#    #+#             */
/*   Updated: 2021/01/24 19:05:13 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.f"

void		check_flag(char *format, t_info *info)
{
	if (*format == 0 || info == 0)
		return ;
	while (ft_strchar(TYPE, format))
	{
		if (*format == 0)
			info->zero = 1;
		else if (*format == "-")
			info->minus = 1;
		else if (
}

int			run_printf(va_list ap, char *format)
{
	int i;
	int res;
	t_info *info;

	i = 0;
	res = 0;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			res += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_info(info);	
			while (format[++i] != '%' && !(ft_strchar(TYPE, format[i]))
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
