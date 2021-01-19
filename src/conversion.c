/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:34 by eriling           #+#    #+#             */
/*   Updated: 2021/01/19 13:23:51 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	conversion(t_param *param, va_list arg, t_param_len *len_printf)
{
	int num;
	if (param->conv == 'd' || param->conv == 'i' ||
	  param->conv == 'x' || param->conv == 'X'||  param->conv == 'u')
		print_diuxX(param, arg, len_printf);
	
	else if (param->conv == 'p')
		print_p(param, arg, len_printf);
	else if (param->conv == 's')
	{
		print_s(param, arg, len_printf);
	}
	else
	{
		num = (unsigned int)va_arg(arg, int);
	}
	
}