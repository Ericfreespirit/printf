/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:22:13 by eriling           #+#    #+#             */
/*   Updated: 2021/01/25 11:09:34 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		lst_arg;
	t_param_len	*len_printf;
	int		len;
	
	len_printf = param_count();
	va_start(lst_arg, s);
	format(s, lst_arg, len_printf);
	va_end(lst_arg);
	len = len_printf->len;
	free(len_printf);
	return (len);
}
