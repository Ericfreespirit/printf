/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:21:55 by eriling           #+#    #+#             */
/*   Updated: 2021/01/19 08:40:37 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"


void itoa_base_var_init(long *n, int *sign, int *i, int *base, long *value)
{
	if(*value < 0)
		*n = -(long)*value;
	else
		*n = (long)*value;
	if (*value < 0 && *base == 10)
		*sign = -1;
	else 
		*sign = 0;
	if (*sign == -1)
		*i = 2;
	else 
		*i = 1;
}

char	*ft_itoa_base(long value, int base, char maj)
{
	char	*s;
	long	n;
	int		sign;
	int		i;
	
	itoa_base_var_init(&n, &sign, &i, &base, &value);
	while ((n /= base) > 0)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + maj - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;

	return (s);
}