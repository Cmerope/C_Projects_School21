/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <cmerope@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:00:34 by cmerope           #+#    #+#             */
/*   Updated: 2021/01/31 02:42:07 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_search_type(char *str, t_all_flags *element, int iter)
{
	int			start;
	int			i;

	start = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			iter++;
			break ;
		}
		i++;
		iter++;
		start++;
	}
	if (str[i] == '\0')
	{
		element->type = 0;
		element->len = iter;
		return (start);
	}
	ft_type(str, element, iter, i);
	return (start);
}

void			ft_type(char *str, t_all_flags *element, int iter, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == 's' || str[i] == 'c' || str[i] == 'd' ||
			str[i] == 'i' || str[i] == 'u' || str[i] == 'p' ||
			str[i] == 'x' || str[i] == 'X' || str[i] == '%')
		{
			element->type = str[i];
			element->len = iter;
			break ;
		}
		iter++;
		i++;
	}
}

int				ft_flag(char *str, t_all_flags *element)
{
	int			i;

	i = 1;
	while (!(str[i] >= '1' && str[i] <= '9') && str[i] != element->type
	&& str[i] != '.' && str[i] != '*')
	{
		if (str[i] == '0')
			element->zero = 1;
		else if (str[i] == '-')
		{
			element->minus = 1;
			element->zero = 0;
			while (!(str[i] >= '1' && str[i] <= '9')
				&& str[i] != element->type && str[i] != '.' && str[i] != '*')
				i++;
			return (i);
		}
		i++;
	}
	return (i);
}

void			ft_width(char *str, t_all_flags *element, va_list arg, int pos)
{
	if (str[pos] != '*')
	{
		if (str[pos] != element->type || str[pos] != '.')
		{
			element->width = ft_atoi_prec(&str[pos]);
		}
	}
	else if (str[pos] == '*')
	{
		element->width = va_arg(arg, int);
		if (element->width < 0)
		{
			element->minus = 1;
			element->zero = 0;
			element->width *= (-1);
		}
	}
}

int				ft_prec(char *str, t_all_flags *element, va_list arg)
{
	int i;

	i = 0;
	while (str[i] != '.' && str[i] != element->type)
		i++;
	if (str[i] == '.' && str[i + 1] == element->type)
		element->prec = 0;
	else if (str[i] == '.' && str[i + 1] != element->type)
	{
		i++;
		if (str[i] == '-')
			return (-1);
		if (str[i] != '*')
		{
			if (str[i] != element->type)
				element->prec = ft_atoi_prec(&str[i]);
		}
		else if (str[i] == '*')
		{
			element->prec = va_arg(arg, int);
			if (element->prec < 0)
				element->prec = -1;
		}
	}
	return (0);
}
