/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:21:27 by eriling           #+#    #+#             */
/*   Updated: 2021/01/25 10:28:44 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	var_init_char(t_param *param, int *space, int len)
{
	if (len > param->width)
		*space = 0;
	else
		*space = param->width - len;
}

void	print_s(t_param *param, va_list arg, t_param_len *len_printf)
{
	char	*res;
	int		len;
	int		space;
	
	res = (char *)va_arg(arg, char *);
	if (!res)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(res);
	len = ft_strlen(res);
	var_init_char(param, &space, len);
	if (param->point < len)
		res[param->point] = '\0';
	if (param->point == 0)
		space += len;
	res_is_minus(space, res, len_printf, param);
	free(res);
}
