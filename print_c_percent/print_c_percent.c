/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:04:44 by eriling           #+#    #+#             */
/*   Updated: 2021/01/20 14:39:47 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	print_c_percent(t_param *param, va_list arg, t_param_len *len_printf)
{
	char	res;
	int		space;

	space = param->width - 1;
	if (param->conv == 'c')
		res = (char)va_arg(arg, int);
	if (param->minus == 1)
	{
		if (param->conv == 'c')
			len_printf->len += write(1, &res, 1);
		else if (param->conv == '%')
			len_printf->len += write(1, "%", 1);
		print_space(space, ' ', len_printf);
	}
	else if (param->minus == 0)
	{
		print_space(space, ' ', len_printf);
		if (param->conv == 'c')
			len_printf->len += write(1, &res, 1);
		else if (param->conv == '%')
			len_printf->len += write(1, "%", 1);
	}
}