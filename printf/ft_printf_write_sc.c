/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_sc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:32:39 by cmerope           #+#    #+#             */
/*   Updated: 2021/01/31 03:27:07 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_str_s(t_all_flags *element, va_list arg)
{
	char	*arg_type;
	int		len;

	element->zero = 0;
	arg_type = va_arg(arg, char*);
	if (arg_type == NULL)
		arg_type = "(null)";
	len = (int)ft_strlen(arg_type);
	if (element->prec < len && element->prec != -1)
		len = element->prec;
	if (element->width >= len)
	{
		if (element->minus == 1)
			write(1, arg_type, len);
		ft_write(' ', (element->width - len));
		if (element->minus == 0 && element->zero == 0)
			write(1, arg_type, len);
		element->len_mini_str = element->width;
	}
	else
	{
		write(1, arg_type, len);
		element->len_mini_str = len;
	}
}

void		ft_str_c(t_all_flags *element, va_list arg)
{
	char	arg_type_c;
	int		len;
	int		len2;

	len = 1;
	arg_type_c = (element->type == '%') ? '%' : (va_arg(arg, int));
	len2 = element->width - 1;
	ft_with_width_c(arg_type_c, element, len2);
}

void		ft_with_width_c(char arg_type_c, t_all_flags *element, int len2)
{
	if (element->width >= 1)
	{
		if (element->zero == 1)
		{
			ft_write('0', len2);
			write(1, &arg_type_c, 1);
		}
		else
		{
			if (element->minus == 1)
				write(1, &arg_type_c, 1);
			ft_write(' ', len2);
			if (element->minus == 0 && element->zero == 0)
				write(1, &arg_type_c, 1);
		}
		element->len_mini_str = element->width;
	}
	else
	{
		write(1, &arg_type_c, 1);
		element->len_mini_str = 1;
	}
}
