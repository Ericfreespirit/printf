/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:40:04 by eriling           #+#    #+#             */
/*   Updated: 2021/01/16 11:22:06 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void handle_main(t_param *param, char const **s, va_list arg)
{
	while(**s && is_check(**s))
	{		
		if(**s == '-')
			param->minus = 1;
		else if(**s == '0')
			param->zero = 1;
		else if(is_digit(**s))
			handle_width_digit(param, s);
		else if(**s == '*')
			handle_width_star(param, arg);
		if(**s == '.')
			handle_precision(param, s, arg);
		if (is_conv(**s) || **s == '%')
		{
			handle_end(param, s);
			return;
		}
		(*s)++;
	}
}
