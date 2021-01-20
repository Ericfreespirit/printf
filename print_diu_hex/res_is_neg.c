/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_is_neg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:25:28 by eriling           #+#    #+#             */
/*   Updated: 2021/01/20 15:08:36 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"


void	res_is_neg(char *res, t_param_len *len_printf, t_param *param)
{
	int	zero_precision;
	int space;
	int len;
	
	len = ft_strlen(res);
	var_init_int(param, &space, &zero_precision, len);
	if (param->point < len && param->point >= 0)
	{
		if (param->minus == 1)
		{
			ft_putstr(res, len_printf);
			print_space(space, ' ', len_printf);
		}
		else if (param->minus == 0)
		{
			print_space(space, ' ', len_printf);
			ft_putstr(res, len_printf);
		}
	}
	else if (param->minus == 1)
	{
		len_printf->len += write(1, "-", 1);
		print_space(zero_precision + 1, '0', len_printf);
		ft_putstr(&res[1], len_printf);
		print_space((space - 1) - (zero_precision), ' ', len_printf);
	}
	else if(param->minus == 0 )
	{
		print_space((space - 1) - (zero_precision), ' ', len_printf);
		len_printf->len += write(1, "-", 1);
		print_space(zero_precision + 1, '0', len_printf);
		ft_putstr(&res[1], len_printf);
	}
}
