/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:11:56 by eriling           #+#    #+#             */
/*   Updated: 2021/01/20 09:53:25 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	format(const char *s, va_list arg, t_param_len *len_printf)
{
	t_param param;

	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s != '\0' && (is_check(*s) || *s == '%'))
			{
				param = *param_default();
				handle_main(&param, &s, arg);
			  conversion(&param, arg, len_printf);
			}
		}
		if (*s != '\0' && *s != '%')
			len_printf->len += write(1, s, 1);
		else if (*s == '%')
			continue;

		if (*s != '\0')
			s++;
	}
}
