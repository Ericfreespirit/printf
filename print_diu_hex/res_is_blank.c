/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_is_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:31:57 by eriling           #+#    #+#             */
/*   Updated: 2021/01/15 15:44:52 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void res_is_blank(int space, t_param_len *len_printf, t_param *param)
{
	if (param->width > 0)
	{
		print_space(space + 1, ' ',len_printf);
		return;
	}
	print_space(space, ' ',len_printf);
	return;
}