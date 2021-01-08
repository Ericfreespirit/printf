/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 08:20:20 by eriling           #+#    #+#             */
/*   Updated: 2021/01/08 08:20:34 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char	*ft_itoa(int nbr)
{
	char	*str;
	unsigned int	num;
	int	sign;
	int	i;
	
	num = (nbr < 0) ? -nbr : nbr;
	i = (nbr < 0) ? 2 : 1;
	sign = (nbr < 0) ? -1 : 0;

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
	sign == -1 ? str[0] = '-' : 0;
	return(str);
}