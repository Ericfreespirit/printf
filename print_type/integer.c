/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:19:39 by eriling           #+#    #+#             */
/*   Updated: 2021/01/15 14:59:33 by eriling          ###   ########.fr       */
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

void	precision_positive(int zero_precision, int space, char *res, t_param_len *len_printf, t_param *param)
{
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
	}
	else if (param->minus == 0)
	{
		space -= zero_precision;
		print_space(space, ' ',len_printf);
		print_space(zero_precision, '0',len_printf);
		ft_putstr(res,len_printf);
	}
}

void res_is_neg(int zero_precision, int space, char *res, t_param_len *len_printf, t_param *param)
{
	int	len;
	len = ft_strlen(res);
		if (param->point < len && param->point >= 0)
	{
		if (param->minus == 1)
		{
			ft_putstr(res, len_printf);
			print_space(space, ' ',len_printf);
		}
		else if (param->minus == 0)
		{
			print_space(space, ' ',len_printf);
			ft_putstr(res, len_printf);
		}
	}
	else if (param->minus == 1)
	{
		len_printf->len += write(1,"-",1);
		print_space(zero_precision + 1, '0',len_printf);
		ft_putstr(&res[1], len_printf);
		print_space((space - 1) - (zero_precision), ' ',len_printf);
	}
	else if(param->minus == 0)
	{
		print_space((space - 1) - (zero_precision), ' ',len_printf);
		len_printf->len += write(1,"-",1);
		print_space(zero_precision + 1, '0',len_printf);
		ft_putstr(&res[1], len_printf);
	}
}


void 	print_int(t_param *param, va_list arg, t_param_len *len_printf)
{
	char	*res;
	int len;
	int space;
	int	zero_precision;

	res = ft_itoa((int)va_arg(arg, int));
	len = ft_strlen(res);
	space = (len > param->width) ? 0 : param->width - len;
	zero_precision = (len > param->point) ? 0 : param->point - len;

	if (param->zero == 1 && param->minus == 1)
		param->zero = 0;
	// ==================== #1 =========================
	if (res[0] == '-' && (param->point >= len || (param->width > len && param->zero == 1)))
		res_is_neg(zero_precision, space, res, len_printf, param);
	// ==================== #2 =========================
	else if (param->point > 0)
	  precision_positive(zero_precision, space, res, len_printf, param);
	// ==================== #3 =========================
	else if (param->point == 0 && ft_strcmp("0",res) == 0)
	{
		if (param->width > 0)
		{
			print_space(space+1, ' ',len_printf);
			return;
		}
		print_space(space, ' ',len_printf);
		return;
	}
	// ==================== #4 =========================
	else
	{
		if (param->minus == 1)
		{
			ft_putstr(res,len_printf);
			print_space(space, ' ',len_printf);
		}
		else if (param->zero == 1 && param->point != 0)
		{
			print_space(space,'0',len_printf);
			ft_putstr(res,len_printf);
		}
		else
		{
			print_space(space, ' ',len_printf);
			ft_putstr(res,len_printf);
		}
	}
	return;
}