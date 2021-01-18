/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:36:21 by eriling           #+#    #+#             */
/*   Updated: 2021/01/18 10:45:27 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void var_init_maj(t_param *param, char *maj)
{
	if (param->conv == 'x')
		*maj = 'a';
	else
		*maj = 'A';
}

void print_hex(t_param *param, va_list arg, t_param_len *len_printf)
{
	char	*res;
	int len;
	int space;
	int	zero_precision;
	char maj;

	var_init_maj(param, &maj);
	res = ft_itoa_base((unsigned int)va_arg(arg, unsigned int),16, maj);
	len = ft_strlen(res);
	var_init(param, &space, &zero_precision, len);
	if (res[0] == '-' && (param->point >= len || (param->width > len && param->zero == 1)))
		res_is_neg(zero_precision, space, res, len_printf, param);
	else if (param->point > 0)
	  precision_is_positive(zero_precision, space, res, len_printf, param);
	else if (param->point == 0 && ft_strcmp("0",res) == 0)
		res_is_blank(space,len_printf, param);
	else
		is_else(space, res, len_printf, param);
}