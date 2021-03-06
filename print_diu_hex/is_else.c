/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_else.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:35:58 by eriling           #+#    #+#             */
/*   Updated: 2021/01/20 14:43:37 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	is_else(int space, char *res, t_param_len *len_printf, t_param *param)
{
	if (param->minus == 1)
	{
		ft_putstr(res, len_printf);
		print_space(space, ' ', len_printf);
	}
	else if (param->zero == 1 && param->point != 0)
	{
		print_space(space, '0', len_printf);
		ft_putstr(res, len_printf);
	}
	else
	{
		print_space(space, ' ', len_printf);
		ft_putstr(res, len_printf);
	}
}
