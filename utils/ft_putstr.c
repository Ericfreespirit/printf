/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 08:27:53 by eriling           #+#    #+#             */
/*   Updated: 2021/01/20 15:18:30 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	ft_putstr(char *s, t_param_len *len_printf)
{
	if (!s)
		return;
	while(*s)
		len_printf->len += write(1, s++, 1);
}
