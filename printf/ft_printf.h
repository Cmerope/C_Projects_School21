/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 02:26:59 by cmerope           #+#    #+#             */
/*   Updated: 2021/01/31 05:29:45 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_all_arg
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
	int			len;
	int			len_mini_str;
}				t_all_flags;

int				ft_printf(const char *format, ...);
t_all_flags		ft_struct(void);
int				ft_full_struct(char *str, t_all_flags *element, va_list ap);
void			ft_write_all_str(char *str, t_all_flags *element, va_list arg);
void			ft_write_type_str(va_list arg, t_all_flags *element);
int				ft_search_type(char *str, t_all_flags *element, int iter);
void			ft_type(char *str, t_all_flags *element, int iter, int i);
int				ft_flag(char *str, t_all_flags *element);
void			ft_width(char *str, t_all_flags *element,
				va_list arg, int point);
int				ft_prec(char *str, t_all_flags *element, va_list arg);
void			ft_str_s(t_all_flags *element, va_list arg);
void			ft_str_c(t_all_flags *element, va_list arg);
void			ft_with_width_c(char arg_type_c, t_all_flags *element,
				int len2);
int				ft_str_di(t_all_flags *element, va_list arg);
void			out_w(char *arg_t, t_all_flags *elem, long arg_n, int len);
void			ft_w_di(char *arg_t, t_all_flags *elem, int len, long arg_n);
void			ft_elem_zero(long arg_n, int len, int len2, char *arg_type);
int				ft_str_u(t_all_flags *element, va_list arg);
int				ft_str_x(t_all_flags *element, va_list arg);
void			ft_without_width_x(t_all_flags *element, long arg_type_x,
				int len, int updown);
void			ft_with_width_x(unsigned long arg_type, t_all_flags *element,
				int sys, int len);
int				ft_str_p(t_all_flags *element, va_list arg);
void			ft_with_width_p(unsigned long arg_type, t_all_flags *element,
				int sys, int len);
size_t			ft_strlen(const char *str);
char			ft_putchar(char c);
int				ft_number_len(unsigned long len, int sys);
void			ft_write(char c, int len);
int				ft_atoi_prec(char *str);
char			*ft_itoa_numb(unsigned int n, int sys);
void			ft_putnbr_hex(unsigned long nb, int updown);
void			ft_arg_zero(t_all_flags *element);

#endif
