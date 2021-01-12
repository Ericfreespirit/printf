/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:19:39 by eriling           #+#    #+#             */
/*   Updated: 2021/01/12 11:07:38 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void print_space(int nb, char c, t_param_len *len_printf)
{
	if (nb <= 0)
		return;
	while (nb > 0)
	{
		len_printf->len += write(1,&c,1);
		nb--;
	}
}

void 	parse_int(t_param *param, va_list arg, t_param_len *len_printf)
{
	char	*res;
	int len;
	int space;
	int	zero_precision;

	res = ft_itoa((int)va_arg(arg, int));
	len = ft_strlen(res);
	space = (len > param->width) ? 0 : param->width - len;
	if (param->point > 0)
	{
		zero_precision = (len > param->point) ? 0 : param->point - len;
		if (param->minus == 1)
		{
			if (zero_precision > 0)
			{
				print_space(zero_precision, '0',len_printf);
				ft_putstr(res,len_printf);
				space -= zero_precision;
				print_space(space, ' ',len_printf);
			}
			else
			{
				ft_putstr(res,len_printf);
				print_space(space,' ',len_printf);
			}
			return;
		}
		else if (param->minus == 0)
		{
			space -= zero_precision;
			print_space(space, ' ',len_printf);
			print_space(zero_precision, '0',len_printf);
			ft_putstr(res,len_printf);
			return;
		}

	}
	else if (param->point == -1 && ft_strcmp("0",res) == 0)
	{
		return;
	}

	if (param->minus == 1)
	{
		ft_putstr(res,len_printf);
		print_space(space, ' ',len_printf);
		return ;
	}
	else if (param->zero == 1)
	{
		print_space(space, '0',len_printf);
		ft_putstr(res,len_printf);
		return;
	}
	else
	{
		print_space(space, ' ',len_printf);
		ft_putstr(res,len_printf);
	}
}