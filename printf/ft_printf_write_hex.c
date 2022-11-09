/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:31:44 by cmerope           #+#    #+#             */
/*   Updated: 2021/01/31 05:29:06 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_str_x(t_all_flags *element, va_list arg)
{
	unsigned int	arg_type_x;
	int				len;
	int				updown;
	int				sys;

	sys = 0;
	updown = (element->type == 'x') ? 0 : 1;
	if (element->prec != -1 && element->zero == 1)
		element->zero = 0;
	arg_type_x = va_arg(arg, unsigned int);
	if (arg_type_x == 0 && element->prec == 0)
	{
		ft_arg_zero(element);
		return (0);
	}
	len = ft_number_len(arg_type_x, sys);
	ft_with_width_x(arg_type_x, element, updown, len);
	return (0);
}

void		ft_without_width_x(t_all_flags *element,
		long arg_type_x, int len, int updown)
{
	int		len2;

	if (element->prec <= len)
	{
		ft_putnbr_hex(arg_type_x, updown);
		element->len_mini_str = len;
	}
	else if (element->prec > len)
	{
		len2 = element->prec - len;
		ft_write('0', len2);
		ft_putnbr_hex(arg_type_x, updown);
		element->len_mini_str = element->prec;
	}
}

void		ft_with_width_x(unsigned long arg_type,
		t_all_flags *element, int updown, int len)
{
	int		len2;

	len2 = element->width - len;
	if (element->prec > len)
		len2 = element->width - element->prec;
	if (element->width >= len && element->width > element->prec)
	{
		if (element->zero == 1)
		{
			ft_write('0', len2);
			ft_putnbr_hex(arg_type, updown);
		}
		else
		{
			if (element->minus == 1)
				ft_without_width_x(element, arg_type, len, updown);
			ft_write(' ', len2);
			if (element->zero == 0 && element->minus == 0)
				ft_without_width_x(element, arg_type, len, updown);
		}
		element->len_mini_str = element->width;
	}
	else
		ft_without_width_x(element, arg_type, len, updown);
}

int			ft_str_p(t_all_flags *element, va_list arg)
{
	unsigned long		arg_type_p;
	int					len;
	int					sys;

	sys = 0;
	if (element->zero == 1 || element->prec > 0)
	{
		element->prec = -1;
		element->zero = 0;
	}
	arg_type_p = va_arg(arg, unsigned long);
	if (arg_type_p == 0 && element->prec == 0)
	{
		ft_arg_zero(element);
		return (0);
	}
	len = ft_number_len(arg_type_p, sys) + 2;
	ft_with_width_p(arg_type_p, element, sys, len);
	return (0);
}

void		ft_with_width_p(unsigned long arg_type,
		t_all_flags *element, int sys, int len)
{
	int		len2;

	len2 = element->width - len;
	if (element->width <= len)
	{
		len2 = len;
		write(1, "0x", 2);
		ft_putnbr_hex(arg_type, sys);
		element->len_mini_str = len;
	}
	else
	{
		if (element->minus == 1)
		{
			write(1, "0x", 2);
			ft_putnbr_hex(arg_type, sys);
		}
		ft_write(' ', len2);
		if (element->minus == 0 && element->zero == 0)
		{
			write(1, "0x", 2);
			ft_putnbr_hex(arg_type, sys);
		}
		element->len_mini_str = element->width;
	}
}
