/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 08:20:20 by eriling           #+#    #+#             */
/*   Updated: 2021/01/16 09:23:41 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void itoa_var_init(unsigned int *num, int *nbr, int *i, int *sign)
{
	if (*nbr < 0)
		*num = -(*nbr);
	else
		*num = *nbr;
	if (*nbr < 0)
		*i = 2;
	else
		*i = 1;
	if (*nbr < 0)
		*sign = -1;
	else 	
		*sign = 0;
}

char	*ft_itoa(int nbr)
{
	char	*str;
	unsigned int	num;
	int	sign;
	int	i;
	
	itoa_var_init(&num, &nbr, &i, &sign);
	while((num /= 10) > 0)
		i++;
	if(!(str =(char*)malloc(sizeof(*str)*i+1)))
		return(NULL);
	str[i] = '\0';

	num = (nbr < 0) ? -nbr : nbr;
	while(i-- + sign)
	{
		str[i] = ((num % 10) + '0'); 
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return(str);
}