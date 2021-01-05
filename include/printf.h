/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:45:11 by eriling           #+#    #+#             */
/*   Updated: 2020/12/30 21:01:28 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_param
{
	char conv;
	int	minus;
	int	zero;
	int point;
	int	width;
	int error;

}	t_param;

int		is_conv(const char c);
int		is_flag(const char c);
int		is_precision(const char c);
int		is_digit(const char c);
int		is_check(const char c);
void	format(const char *s, va_list arg);
void	handle_main(t_param *param, const char **s, va_list arg);

#endif
