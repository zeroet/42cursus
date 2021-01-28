/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:07:54 by seyun             #+#    #+#             */
/*   Updated: 2021/01/28 19:47:14 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TYPE "csdiupxX%"

# include <stdarg.h>
# include <stdlib.h>

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
