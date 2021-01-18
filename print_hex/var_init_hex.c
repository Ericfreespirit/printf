/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_init_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:14:53 by eriling           #+#    #+#             */
/*   Updated: 2021/01/18 15:32:27 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void var_init_hex(t_param *param, int *space, int *zero_precision, int len)
{
	if (len > param->width)
		*space = 0;
	else
		*space = param->width + len;
	if (len > param->point)
		*zero_precision = 0;
	else
		*zero_precision = param->point + len;
}