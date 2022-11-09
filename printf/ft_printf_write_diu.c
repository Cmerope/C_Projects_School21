/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_diu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:41:25 by cmerope           #+#    #+#             */
/*   Updated: 2021/01/31 03:10:58 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_str_di(t_all_flags *element, va_list arg)
{
	char			*arg_type;
	int				arg_type_int;
	int				sys;
	int				len;

	sys = 1;
	arg_type_int = va_arg(arg, int);
	if (arg_type_int < 0)
		arg_type = ft_itoa_numb((arg_type_int * (-1)), sys);
	else
		arg_type = ft_itoa_numb(arg_type_int, sys);
	len = (int)ft_strlen(arg_type);
	if (element->prec != -1 && element->zero == 1)
		element->zero = 0;
	if (arg_type_int == 0 && element->prec == 0)
	{
		ft_arg_zero(element);
		return (0);
	}
	ft_w_di(arg_type, element, len, arg_type_int);
	return (0);
}

void				out_w(char *arg_t, t_all_flags *elem, long arg_n, int len)
{
	int				len2;

	if (elem->prec <= len)
	{
		if (arg_n < 0)
			write(1, "-", 1);
		write(1, arg_t, len);
		elem->len_mini_str = (arg_n < 0 ? (len + 1) : len);
	}
	else if (elem->prec > len)
	{
		if (arg_n < 0)
			write(1, "-", 1);
		len2 = elem->prec - len;
		ft_write('0', len2);
		write(1, arg_t, len);
		elem->len_mini_str = (arg_n < 0 ? (elem->prec + 1) : elem->prec);
	}
}

void				ft_w_di(char *arg_t, t_all_flags *elem, int len, long arg_n)
{
	int				len2;

	len2 = elem->width - (arg_n < 0 ? len + 1 : len);
	if (elem->prec > len)
		len2 = elem->width - (arg_n < 0 ? elem->prec + 1 : elem->prec);
	if (elem->width >= (arg_n < 0 ? len + 1 : len) && elem->width >
			(arg_n < 0 ? elem->prec + 1 : elem->prec))
	{
		if (elem->zero == 1 && elem->minus == 0)
			ft_elem_zero(arg_n, len, len2, arg_t);
		else
		{
			if (elem->minus == 1)
				out_w(arg_t, elem, arg_n, len);
			ft_write(' ', len2);
			if (elem->zero == 0 && elem->minus == 0)
				out_w(arg_t, elem, arg_n, len);
		}
		elem->len_mini_str = elem->width;
	}
	else
		out_w(arg_t, elem, arg_n, len);
	free(arg_t);
}

void				ft_elem_zero(long arg_n, int len, int len2, char *arg_type)
{
	if (arg_n < 0)
		write(1, "-", 1);
	ft_write('0', len2);
	write(1, arg_type, len);
}

int					ft_str_u(t_all_flags *element, va_list arg)
{
	char			*arg_type;
	unsigned int	arg_type_u;
	int				len;
	int				sys;

	sys = 1;
	arg_type_u = va_arg(arg, unsigned int);
	arg_type = ft_itoa_numb(arg_type_u, sys);
	len = (unsigned int)ft_strlen(arg_type);
	if (element->prec != -1 && element->zero == 1)
		element->zero = 0;
	if (arg_type_u == 0 && element->prec == 0)
	{
		ft_arg_zero(element);
		return (0);
	}
	ft_w_di(arg_type, element, len, arg_type_u);
	return (0);
}
