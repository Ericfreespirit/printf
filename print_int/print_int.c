/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:19:39 by eriling           #+#    #+#             */
/*   Updated: 2021/01/15 15:44:48 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void 	print_int(t_param *param, va_list arg, t_param_len *len_printf)
{
	char	*res;
	int len;
	int space;
	int	zero_precision;

	//TODO create a function for init (use pointer)
	res = ft_itoa((int)va_arg(arg, int));
	len = ft_strlen(res);
	space = (len > param->width) ? 0 : param->width - len;
	zero_precision = (len > param->point) ? 0 : param->point - len;

	if (param->zero == 1 && param->minus == 1)
		param->zero = 0;
	if (res[0] == '-' && (param->point >= len || (param->width > len && param->zero == 1)))
		res_is_neg(zero_precision, space, res, len_printf, param);
	else if (param->point > 0)
	  precision_is_positive(zero_precision, space, res, len_printf, param);
	else if (param->point == 0 && ft_strcmp("0",res) == 0)
		res_is_blank(space,len_printf, param);
	else
		is_else(space, res, len_printf, param);
}