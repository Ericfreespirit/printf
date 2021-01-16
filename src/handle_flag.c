/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:22:08 by eriling           #+#    #+#             */
/*   Updated: 2021/01/16 11:22:16 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int handle_conv(t_param *param, char c)
{
	if (c == 'c')
		param->conv = 'c';
	else if (c == 's')
		param->conv = 's';
	else if (c == 'p')
		param->conv = 'p';
	else if (c == 'd') 
		param->conv = 'd';
	else if (c == 'i')
		param->conv = 'i';
	else if (c == 'u')
		param->conv = 'u';
	else if (c == 'x')
		param->conv = 'x';
	else if (c == 'X')
		param->conv = 'X';
	else
		return (0);			
	return (1);
}

void handle_precision(t_param *param, char const **s, va_list arg)
{
	(*s)++;
		if (**s == '*')
		{
			param->point = (int) va_arg(arg, int);
			if (param->point < 0)
				return;
			(*s)++;
		}
		else if (is_digit(**s))
		{
			if (**s == '0')
				param->point = 0;
			else
			{
				param->point = 0;
				while(**s && is_digit(**s))
				{
					param->point *= 10;
					param->point += (**s - '0');
					(*s)++;
				}
			}
		}
		else
			param->point = 0;		
}

void handle_width_digit(t_param *param, char const **s)
{
	while(**s && is_digit(**s))
	{
		param->width *= 10;
		param->width += (**s - '0');
		(*s)++;
	}
}

void handle_width_star(t_param *param, va_list arg)
{
	param->width = (int) va_arg(arg,int);
	if (param->width < 0)
	{
		param->width *= -1;
		param->minus = 1;
	}
}

void handle_end(t_param *param, char const **s)
{
	if (param->zero == 1 && param->minus == 1)
		param->zero = 0;
	if (is_conv(**s))
	{
		handle_conv(param, **s);
		(*s)++;
		return ;
	}
	else if(**s == '%')
	{
		param->conv = '%';
		(*s)++;
		return ;
	}
}