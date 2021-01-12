/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:45:11 by eriling           #+#    #+#             */
/*   Updated: 2021/01/12 09:04:57 by eriling          ###   ########.fr       */
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

typedef struct s_param_len
{
	int len;
} t_param_len;

int		is_conv(const char c);
int		is_flag(const char c);
int		is_precision(const char c);
int		is_digit(const char c);
int		is_check(const char c);
void	format(const char *s, va_list arg, t_param_len *len_printf);
void	handle_main(t_param *param, const char **s, va_list arg);
void  conversion(t_param *param, va_list arg,t_param_len *len_printf);
void 	parse_int(t_param*param, va_list arg,t_param_len *len_printf);
char	*ft_itoa(int nbr);
void ft_putstr(char *s,t_param_len *len_printf);
int	ft_strlen(char *s);
t_param_len	param_count();
char	*ft_strstr(char *str, char *to_find);
int		ft_strcmp(char *s1, char *s2);

#endif
