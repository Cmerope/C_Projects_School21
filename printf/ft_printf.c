/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 00:37:45 by cmerope           #+#    #+#             */
/*   Updated: 2021/01/31 02:25:14 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all_flags		ft_struct(void)
{
	t_all_flags	element;

	element.minus = 0;
	element.zero = 0;
	element.width = 0;
	element.prec = -1;
	element.type = 0;
	element.len = 0;
	element.len_mini_str = 0;
	return (element);
}

int				ft_full_struct(char *str, t_all_flags *element, va_list arg)
{
	int			point;

	point = ft_flag(str, element);
	ft_width(str, element, arg, point);
	point = ft_prec(str, element, arg);
	return (point);
}

void			ft_write_all_str(char *str, t_all_flags *element, va_list arg)
{
	int			i;
	int			max;

	i = 0;
	max = element->len;
	while (str[i] != 0 && i < max)
	{
		if (str[i] == '%')
		{
			ft_write_type_str(arg, element);
			break ;
		}
		write(1, &str[i], 1);
		i++;
	}
}

void			ft_write_type_str(va_list arg, t_all_flags *element)
{
	if (element->type == 's')
		ft_str_s(element, arg);
	if (element->type == 'c')
		ft_str_c(element, arg);
	if (element->type == 'd' || element->type == 'i')
		ft_str_di(element, arg);
	if (element->type == 'u')
		ft_str_u(element, arg);
	if (element->type == 'x' || element->type == 'X')
		ft_str_x(element, arg);
	if (element->type == 'p')
		ft_str_p(element, arg);
	if (element->type == '%')
		ft_str_c(element, arg);
}

int				ft_printf(const char *format, ...)
{
	t_all_flags	element;
	va_list		arg;
	int			iter;
	int			start;
	int			result;

	iter = 0;
	result = 0;
	va_start(arg, (char*)format);
	element = ft_struct();
	while (((char *)format)[iter] != '\0' && iter < (int)ft_strlen(format))
	{
		start = ft_search_type(&((char*)format)[iter], &element, iter);
		if (ft_full_struct(&((char*)format)[start + iter], &element, arg) == -1)
		{
			va_end(arg);
			return (-1);
		}
		ft_write_all_str(&((char*)format)[iter], &element, arg);
		iter = element.len + 1;
		result += (start + element.len_mini_str);
		element = ft_struct();
	}
	va_end(arg);
	return (result);
}
