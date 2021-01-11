/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:11:56 by eriling           #+#    #+#             */
/*   Updated: 2021/01/11 08:40:19 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void print_struct(t_param param)
{
	printf("== Struct param ==\n");
	printf("conv = %c\n", param.conv);
	printf("minus = %d\n", param.minus);
	printf("zero = %d\n", param.zero);
	printf("point = %d\n", param.point);
	printf("width = %d\n", param.width);	
}

t_param	param_default()
{
	t_param init_param;
// TODO malloc protection
	init_param = (t_param) {
		.conv = '0',
		.minus = 0,
		.zero = 0,
		.point = 0,
		.width = 0,
		.error = 0,
	};
	return (init_param);
}

void	format(const char *s, va_list arg)
{
	t_param param;

	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s != '\0' && is_check(*s))
			{
				param = param_default();
				handle_main(&param, &s, arg);
			  conversion(&param, arg);
			}
			print_struct(param);
		}
		if (*s != '%')
			write(1, s, 1);
		s++;
	}
}
