/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:51:26 by eriling           #+#    #+#             */
/*   Updated: 2021/01/25 13:53:35 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_atoi(const char **str)
{
	long	sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	while (**str && **str >= '0' && **str <= '9')
	{
		nb = (nb * 10) + (**str - '0');
		if (nb < 0 && sign == -1)
			return (0);
		else if (nb < 0 && sign == 1)
			return (-1);
		(*str)++;
	}
	return (nb * sign);
}
