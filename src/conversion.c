/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:34 by eriling           #+#    #+#             */
/*   Updated: 2021/01/16 09:29:33 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	conversion(t_param *param, va_list arg, t_param_len *len_printf)
{
	if (param->conv == 'd' || param->conv == 'i')
	{
		print_int(param, arg, len_printf);
	}
}