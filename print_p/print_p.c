/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:34:25 by eriling           #+#    #+#             */
/*   Updated: 2021/01/19 10:35:46 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"


void 	print_p(t_param *param, va_list arg, t_param_len *len_printf)
{
	char	*res;
	int len;
	int space;
	int	zero_precision;

	res = ft_itoa_base((unsigned int)va_arg(arg, int),16, 'a');
	len = ft_strlen(res);
	var_init_int(param, &space, &zero_precision, len);
//	if (res[0] == '-' && (param->point >= len || (param->width > len && param->zero == 1)))
	//   	res_is_neg(zero_precision, space, res, len_printf, param);
	if (ft_strcmp("0",res) == 0)
	{
		p_res_is_blank(zero_precision,space,len_printf, param);
	}
	else if (param->point > 0)
	  p_precision_is_positive(zero_precision, space, res, len_printf, param);
	else
		p_is_else(space, res, len_printf, param);
}