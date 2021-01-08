/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:19:39 by eriling           #+#    #+#             */
/*   Updated: 2021/01/08 09:58:52 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void print_space(int nb, char c)
{
	while (nb > 0)
	{
		write(1,&c,1);
		nb--;
	}
}

void 	parse_int(t_param *param, va_list arg)
{
	
	char	*res;
	int len;
	int space;
	res = ft_itoa((int)va_arg(arg, int));
	
	len = ft_strlen(res);
	
	space = param->width - len;
	if (param->minus == 1)
	{
		if (param->point > 0)
		{
			// 1) display zero
			// 2) display nbr
			// 3) display space
		}
		ft_putstr(res);
		print_space(space, ' ');
		return ;
	}
	else if (param->zero == 1)
	{
		print_space(space, '0');
		ft_putstr(res);
		return;
	}
	print_space(space, ' ');
	ft_putstr(res);
	
}