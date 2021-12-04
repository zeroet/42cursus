/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytak <ytak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:58:47 by ytak              #+#    #+#             */
/*   Updated: 2021/08/23 16:52:20 by ytak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
int		write_null(void);
int		print_s(const char **str, va_list ap);
int		print_c(const char **str, va_list ap);
int		ft_putnbr(long long nbr, char *base, int *len_i);
int		ft_putnbr_per(size_t nbr, char *base, int *len_i);
int		print_diu(const char **str, va_list ap);
//int		print_u(const char **str, va_list ap);
int		print_x(const char **str, va_list ap);
int		print_X(const char **str, va_list ap);
int		print_p(const char **str, va_list ap);
int		printpercent(const char **str);
int		print_char(const char **str, va_list ap);
int		ft_printf(const char *str, ...);

#endif
