/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:34 by eriling           #+#    #+#             */
/*   Updated: 2021/01/19 08:49:04 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	conversion(t_param *param, va_list arg, t_param_len *len_printf)
{
	int num;
	if (param->conv == 'd' || param->conv == 'i')
		print_int(param, arg, len_printf);
	else if (param->conv == 'x' || param->conv == 'X')
	{
		print_hex(param, arg, len_printf);
	}
	else if (param->conv == 'u')
	{
		print_unsigned_int(param, arg, len_printf);
	}
	else
	{
		num = (unsigned int)va_arg(arg, int);
	}
	
}