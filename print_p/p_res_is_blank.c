/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_res_is_blank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:31:57 by eriling           #+#    #+#             */
/*   Updated: 2021/01/22 14:25:34 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	p_res_is_blank_is_minus(int zero_precision
, int space, t_param_len *len_printf, t_param *param)
{
	if (zero_precision > 0)
	{
		ft_putstr("0x", len_printf);
		print_space(zero_precision, '0', len_printf);
		ft_putstr("0", len_printf);
		space -= zero_precision;
		print_space(space, ' ', len_printf);
	}
	else if (param->point == 0)
	{
		ft_putstr("0x", len_printf);
		print_space(space + 1, ' ', len_printf);
	}
	else
	{
		ft_putstr("0x0", len_printf);
		print_space(space, ' ', len_printf);
	}
}

void	p_res_is_blank(int zero_precision
, int space, t_param_len *len_printf, t_param *param)
{
	space -= 2;
	if (param->point == 0)
	{
		if (param->width > 0)
		{
			print_space(param->width - 2, ' ', len_printf);
		}
		ft_putstr("0x", len_printf);
	}
	else if (param->minus == 1)
		p_res_is_blank_is_minus(zero_precision, space, len_printf, param);
	else if (param->minus == 0)
	{
		space -= zero_precision;
		print_space(space, ' ', len_printf);
		ft_putstr("0x", len_printf);
		print_space(zero_precision, '0', len_printf);
		ft_putstr("0", len_printf);
	}
}
