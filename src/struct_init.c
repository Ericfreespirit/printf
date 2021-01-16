/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:09:00 by eriling           #+#    #+#             */
/*   Updated: 2021/01/16 09:09:23 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

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