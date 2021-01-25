/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:06:28 by seyun             #+#    #+#             */
/*   Updated: 2021/01/25 20:33:08 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.f"

void		check_width_prec(va_list ap, char *format,
		t_info *info, int i)
{


void		check_flag(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == 0)/*if width and prec is 1, '0' isn't flag zero */
		info->zero = 1;
	else if(format[i] == '-')
		info->minus = 1;
	else if(foramt[i] == '.')
		info->prec = 1;
	else if(ft_isdigit(format[i]) || format[i] == '*')
		check_width_prec(ap, foramt, info, i);
}

int			run_printf(va_list ap, char *format)
{
	int i;
	int ret;
	t_info *info;

	i = 0;
	res = 0;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			ret += ft_putchar(format[i++]);/*retrun value of printf is number of the char in screen.*/
		if (format[i] == '%')
		{
			init_info(info);	
			while (format[++i] != '%' && !(ft_strchar(TYPE, format[i]))
				check_flag(ap, format, info, i);
			info->type = format[i++];
			if ((info->minus == 1 || info->prec > 0) && info->type != '%')
				info->zero = 0;
			ret += print_type(ap, info);
		}
	}
	free(info);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	res = run_printf(ap, (char*)format);
	va_end(ap);
	return (ret);
}
