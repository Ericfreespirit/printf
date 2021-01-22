/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:06:49 by eriling           #+#    #+#             */
/*   Updated: 2021/01/16 09:07:23 by eriling          ###   ########.fr       */
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
