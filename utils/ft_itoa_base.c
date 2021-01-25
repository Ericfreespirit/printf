/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:21:55 by eriling           #+#    #+#             */
/*   Updated: 2021/01/25 09:46:46 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	itoa_base_var_init_1(long *n, int *sign, int *base, long *value)
{
	if (*value < 0)
		*n = -(long)*value;
	else
		*n = (long)*value;
	if (*value < 0 && *base == 10)
		*sign = -1;
	else
		*sign = 0;
}

void	itoa_base_var_init_2(int *i, int *sign)
{
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

	itoa_base_var_init_1(&n, &sign, &base, &value);
	itoa_base_var_init_2(&i, &sign);
	while ((n /= base) > 0)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		if (n % base < 10)
			s[i] = n % base + '0';
		else
			s[i] = n % base + maj - 10;
		n /= base;
	}
	if (i == 0)
		s[i] = '-';
	return (s);
}
