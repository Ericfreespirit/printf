/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_precision_is_positive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:21:15 by eriling           #+#    #+#             */
/*   Updated: 2021/01/20 15:12:23 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	p_precision_is_positive(char *res, t_param_len *len_printf, t_param *param)
{
	int	zero_precision;
	int space;
	int len;

	len = ft_strlen(res);
	var_init_int(param, &space, &zero_precision, len);
	space -= 2;
	if (param->minus == 1)
	{
		if (zero_precision > 0)
		{
			ft_putstr("0x", len_printf);
			print_space(zero_precision - 2, '0', len_printf);
			ft_putstr(res, len_printf);
			space -= zero_precision;
			print_space(space, ' ', len_printf);
		}
		else
		{
			ft_putstr(res, len_printf);
			print_space(space,' ', len_printf);
		}
	}
	else if (param->minus == 0)
	{
		space -= zero_precision;
		print_space(space, ' ', len_printf);
		ft_putstr("0x", len_printf);
		print_space(zero_precision - 2, '0', len_printf);
		ft_putstr(res, len_printf);
	}
}
