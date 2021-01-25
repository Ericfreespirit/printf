/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:19:39 by eriling           #+#    #+#             */
/*   Updated: 2021/01/25 09:56:44 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	var_init_maj(t_param *param, char *maj)
{
	if (param->conv == 'x')
		*maj = 'a';
	else
		*maj = 'A';
}

void	res_base(t_param *param, va_list arg, char **res)
{
	char	maj;

	if (param->conv == 'x' || param->conv == 'X')
	{
		var_init_maj(param, &maj);
		*res = ft_itoa_base((unsigned int)va_arg(arg, int), 16, maj);
	}
	else if (param->conv == 'i' || param->conv == 'd')
		*res = ft_itoa_base((int)va_arg(arg, int), 10, 'a');
	else if (param->conv == 'u')
		*res = ft_itoa_base((unsigned int)va_arg(arg, unsigned int), 10, 'a');
}

void	print_diu_hex(t_param *param, va_list arg, t_param_len *len_printf)
{
	char	*res;
	int		len;
	int		space;
	int		zero_precision;

	res_base(param, arg, &res);
	len = ft_strlen(res);
	var_init_int(param, &space, &zero_precision, len);
	if (res[0] == '-' && (param->point >= len
	|| (param->width > len && param->zero == 1)))
		res_is_neg(res, len_printf, param);
	else if (param->point > 0)
		precision_is_positive(res, len_printf, param);
	else if (param->point == 0 && ft_strcmp("0", res) == 0)
		res_is_blank(space, len_printf, param);
	else
		is_else(space, res, len_printf, param);
	free(res);
}
