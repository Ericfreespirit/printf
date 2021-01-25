/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:34 by eriling           #+#    #+#             */
/*   Updated: 2021/01/25 09:25:11 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	conversion(t_param *param, va_list arg, t_param_len *len_printf)
{
	if (param->conv == 'd' || param->conv == 'i' ||
	param->conv == 'x' || param->conv == 'X' || param->conv == 'u')
		print_diu_hex(param, arg, len_printf);
	else if (param->conv == 'p')
		print_p(param, arg, len_printf);
	else if (param->conv == 's')
		print_s(param, arg, len_printf);
	else if (param->conv == 'c' || param->conv == '%')
		print_c_percent(param, arg, len_printf);
}
