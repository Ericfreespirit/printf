/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_is_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:21:15 by eriling           #+#    #+#             */
/*   Updated: 2021/01/25 13:03:32 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	res_is_minus(int space, char *res
, t_param_len *len_printf, t_param *param)
{
	int len;

	len = param->point;
	var_init_char(param, &space, len);

	if (param->minus == 1)
	{
		len_printf->len += write(1, res, param->point);
		print_space(space, ' ', len_printf);
	}
	else if (param->minus == 0)
	{
		print_space(space, ' ', len_printf);
		len_printf->len += write(1, res, param->point);
	}
}
