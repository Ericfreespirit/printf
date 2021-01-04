/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:40:04 by eriling           #+#    #+#             */
/*   Updated: 2021/01/03 16:48:17 by eriling          ###   ########.fr       */
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

int handle_main(t_param *param, char const *str,int pos)
{
	// Fill param
	return (1);
}
