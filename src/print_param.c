/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:08:34 by eriling           #+#    #+#             */
/*   Updated: 2021/01/06 10:32:07 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void ft_putnbr(int nb)
{
	(void)nb;
}


int	len_int_arg(int nb)
{
	int	i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}


void	print_param(t_param *param, va_list arg)
{
	(void)arg;

	int	int_arg;
	int int_len;
	//int	width;
	//int	precision;
	
	if (param->conv == 'd' || param->conv == 'i')
	{
		/*
			if (param->width > 0)
				width = (int) va_arg(arg, int);
			else if (param->width < 0)
			{
				width = (int)va_arg(arg, int) * -1;
				param->minus = 1;
			}
		*/

		/*
			if (param->point > 0)
				precision = (int) va_arg(arg, int);
			else if (param->point < 0) 
			{
				precision = (int)va_arg(arg, int) * -1;
				param->minus = 1;
			}
		*/

		/*	
			

		*/
		int_arg = (int) va_arg(arg, int);
		int_len = len_int_arg(int_arg);

			
	}
}