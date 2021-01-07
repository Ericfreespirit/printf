/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:19:39 by eriling           #+#    #+#             */
/*   Updated: 2021/01/07 12:53:50 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"


int	len_int_arg(int nb)
{
	int	i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

void ft_putnbr(int nb)
{
	long nbr;

	nbr = (long)nb;
	if (nb < 0)
	{
		write(1,"-",1);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr(nbr/10);
	nbr %= 10;
	nbr += '0';
	write(1,&nbr, 1);	
}

void print_space(int nb, char c)
{
	while (nb > 0)
	{
		write(1,&c,1);
		nb--;
	}
}

int	clean_int(int nb)
{

}


void 	parse_int(t_param *param, va_list arg)
{
	int	int_arg;
	int int_len;
	int space;

	
	int_arg = (int) va_arg(arg, int);
	int_arg = clean_int(int_arg);
	int_len = len_int_arg(int_arg);
	
	space = param->width - int_len;
	if (param->minus == 1)
	{
		if (param->point > 0)
		{
			// 1) display zero
			// 2) display nbr
			// 3) display space
		}
		ft_putnbr(int_arg);
		print_space(space, ' ');
		return ;
	}
	else if (param->zero == 1)
	{
		print_space(space, '0');
		ft_putnbr(int_arg);
		return;
	}
	print_space(space, ' ');
	ft_putnbr(int_arg);
}