/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:11:56 by eriling           #+#    #+#             */
/*   Updated: 2021/01/16 09:04:47 by eriling          ###   ########.fr       */
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

t_param	*param_default()
{
	t_param *init_param;
	init_param = malloc(sizeof(t_param));
	if (init_param == NULL)
		return(NULL);
	*init_param = (t_param) {
		.conv = '0',
		.minus = 0,
		.zero = 0,
		.point = -1,
		.width = 0,
		.error = 0,
	};
	return (init_param);
}

t_param_len	*param_count()
{
	t_param_len *param_len;
	param_len = malloc(sizeof(t_param_len));
	if (param_len == NULL)
		return(NULL);
 	*param_len = (t_param_len) {
		.len = 0,
	};
	return (param_len);
}


void	format(const char *s, va_list arg, t_param_len *len_printf)
{
	t_param param;

	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s != '\0' && is_check(*s))
			{
				param = *param_default();
				handle_main(&param, &s, arg);
			  conversion(&param, arg, len_printf);
			}
		}
		if (*s != '\0' && *s != '%')
			len_printf->len += write(1, s, 1);

		if (*s != '\0')
		s++;
	}
}
