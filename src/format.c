/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:11:56 by eriling           #+#    #+#             */
/*   Updated: 2020/12/30 11:13:27 by eriling          ###   ########.fr       */
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
	printf("star = %d\n", param.star);
	printf("width = %d\n", param.width);	
}

t_param	param_default()
{
	t_param init_param;

	init_param = (t_param) {
		.conv = '0',
		.minus = 0,
		.zero = 0,
		.point = 0,
		.star = 0,
		.width = 0,
		.error = 0,
	};
	return (init_param);
}

void	format(const char *s, va_list arg)
{
	int		i;
	t_param param;

	(void)arg;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			// If double %
			if (s[i] == '%')
			{
				write(1,"%",1);
				i++;
			}
			if (s[i] != '\0' && is_check(s[i]))
				param = param_default();
			while (s[i] && is_check(s[i]))
			{
				handle_main(&param, s, i);
				/*
				if (is_conv)
					display space;
					break it
				*/
				i++;
			}			
		}
		if (s[i] != '%')
		{
			/*
				if(something in struct)
					display space;
			*/
			write(1, &s[i], 1);
			i++;
		}
	}
}
