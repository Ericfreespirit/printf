/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:45:11 by eriling           #+#    #+#             */
/*   Updated: 2021/01/25 13:53:51 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_param
{
	char	conv;
	int		minus;
	int		zero;
	int		point;
	int		width;
}					t_param;

typedef struct		s_param_len
{
	int	len;
}					t_param_len;

int					is_conv(const char c);
int					is_flag(const char c);
int					is_precision(const char c);
int					is_digit(const char c);
int					is_check(const char c);
void				format(const char *s, va_list arg, t_param_len *len_printf);
void				handle_main(t_param *param, const char **s, va_list arg);
int					handle_conv(t_param *param, char c);
void				handle_end(t_param *param, char const **s);
void				handle_precision(t_param *param
, char const **s, va_list arg);

void				handle_width_digit(t_param *param, char const **s);
void				handle_width_star(t_param *param, va_list arg);
void				handle_end(t_param *param, char const **s);
void				conversion(t_param *param, va_list arg
, t_param_len *len_printf);
void				print_diu_hex(t_param*param, va_list arg
, t_param_len *len_printf);
char				*ft_itoa_base(long value, int base, char maj);
void				ft_putstr(char *s, t_param_len *len_printf);
int					ft_strlen(char *s);
t_param_len			*param_count(void);
t_param				*param_default(void);
char				*ft_strstr(char *str, char *to_find);
int					ft_strcmp(char *s1, char *s2);
void				precision_is_positive(char *res
, t_param_len *len_printf, t_param *param);
void				res_is_neg(char *res
, t_param_len *len_printf, t_param *param);
void				print_space(int nb, char c
, t_param_len *len_printf);
void				res_is_blank(int space
, t_param_len *len_printf, t_param *param);
void				is_else(int space, char *res
, t_param_len *len_printf, t_param *param);
void				var_init_int(t_param *param, int *space
, int *zero_precision, int len);
void				p_precision_is_positive(char *res
, t_param_len *len_printf, t_param *param);
void				p_res_is_blank(int zero_precision, int space
, t_param_len *len_printf, t_param *param);
void				p_is_else(int space, char *res
, t_param_len *len_printf, t_param *param);
void				print_p(t_param *param, va_list arg
, t_param_len *len_printf);
void				print_s(t_param *param, va_list arg
, t_param_len *len_printf);
void				res_is_minus(int space, char *res
, t_param_len *len_printf, t_param *param);
char				*ft_strdup(char *s);
void				var_init_char(t_param *param, int *space, int len);
void				print_c_percent(t_param *param
, va_list arg, t_param_len *len_printf);
int					ft_atoi(const char **str);
int					ft_printf(const char *s, ...);

#endif
