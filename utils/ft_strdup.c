/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:49:42 by eriling           #+#    #+#             */
/*   Updated: 2021/01/25 10:23:59 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*new_s;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	new_s = malloc(sizeof(*new_s) * (i + 1));
	if (new_s == NULL)
		return (NULL);
	new_s[i] = '\0';
	i = 0;
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	return (new_s);
}
