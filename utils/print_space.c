/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:26:50 by eriling           #+#    #+#             */
/*   Updated: 2021/01/15 15:27:07 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void print_space(int nb, char c, t_param_len *len_printf)
{
	if (nb <= 0)
		return;
	while (nb > 0)
	{
		len_printf->len += write(1,&c,1);
		nb--;
	}
}