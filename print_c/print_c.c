/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:04:44 by eriling           #+#    #+#             */
/*   Updated: 2021/01/19 15:11:35 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void 	print_c(t_param *param, va_list arg, t_param_len *len_printf)
{
	char res;
	int space;
	
	space = param->width -1;
	res = (char)va_arg(arg, int);
	if (param->minus == 1)
	{
		len_printf->len += write(1, &res, 1);
		print_space(space,' ',len_printf);
	}
	else if (param->minus == 0)
	{
		print_space(space, ' ',len_printf);
		len_printf->len += write(1, &res, 1);
	}
}