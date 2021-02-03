/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:07:54 by seyun             #+#    #+#             */
/*   Updated: 2021/02/03 15:12:43 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./Libft/libft.h"
# include <stdio.h>

# define TYPE "csdiupxX%"

typedef struct s_info
{
	int	minus;
	int zero;
	int prec;
	int width;
	char type;
	int nbr_sign;
	int nbr_base;
}				t_info;

/*
 *********** main fonctions *********/
int			ft_printf(const char *format, ...);
int			run_printf(va_list ap, char *format);
void		check_info(va_list ap, char *format, t_info *info, int i);
void		check_width_and_prec(va_list ap, char *format, t_info *info, int i);
int			print_type(va_list ap, t_info *info);
/*
 * ******** print fonctions *********/
int			put_width(int width, int len, int zero);
int			print_char(int c, t_info *info);
int		print_nbr(unsigned long long nbr, t_info *info);
int		put_prec_str(unsigned long long nbr, t_info *info, char **buf);
int		put_minus2(int buf_len, t_info *info, char **buf);
int		put_minus(t_info *info, char **buf);
int		put_pointer_prefix(char **buf);
int		print_string(char *str, t_info * info);
int			width_string(char **buf, t_info *info);
char		*parse_str(char *str, int end, int len);
/*
 * ********* utils fonctions ********/
char	*ft_baseset(char type);
int		ft_nbrlen(unsigned long long nbr, t_info *info);
void	init_info(t_info *info);

# endif




