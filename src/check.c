/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:00:45 by eriling           #+#    #+#             */
/*   Updated: 2020/12/29 17:32:34 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	is_conv(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	is_flag(const char c)
{
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

int	is_precision(const char c)
{
	if (c == '.' || c == '*')
		return (1);
	return (0);
}

int	is_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_check(const char c)
{
	if (is_conv(c) || is_flag(c) || is_precision(c)
		|| is_digit(c))
		return (1);
	return (0);
}
