/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:22:13 by eriling           #+#    #+#             */
/*   Updated: 2020/12/15 22:49:16 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *s, ...)
{
	va_list lst_arg;

	va_start(lst_arg, s);
	format(s, lst_arg);
	va_end(lst_arg);
	return (1);// nb elements printed
}
