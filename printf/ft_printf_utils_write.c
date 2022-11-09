/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_write.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 01:21:37 by cmerope           #+#    #+#             */
/*   Updated: 2021/01/31 01:30:59 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_itoa_numb(unsigned int n, int sys)
{
	char			*s;
	unsigned int	i;

	i = ft_number_len(n, sys);
	s = (char*)malloc(sizeof(char) * i + 1);
	if (!s)
	{
		free(s);
		return (NULL);
	}
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	s[i] = '\0';
	i--;
	while (n > 0)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (s);
}

int					ft_atoi_prec(char *str)
{
	int				number;

	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == '0' || *str == '-')
		str++;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number);
}

void				ft_putnbr_hex(unsigned long nb, int updown)
{
	if (nb >= 16)
	{
		ft_putnbr_hex(nb / 16, updown);
		ft_putnbr_hex(nb % 16, updown);
	}
	else
	{
		if (nb == 10)
			nb = (updown == 1) ? 17 : 49;
		if (nb == 11)
			nb = (updown == 1) ? 18 : 50;
		if (nb == 12)
			nb = (updown == 1) ? 19 : 51;
		if (nb == 13)
			nb = (updown == 1) ? 20 : 52;
		if (nb == 14)
			nb = (updown == 1) ? 21 : 53;
		if (nb == 15)
			nb = (updown == 1) ? 22 : 54;
		ft_putchar(nb + 48);
	}
}

void				ft_write(char c, int len)
{
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
	}
}

void				ft_arg_zero(t_all_flags *element)
{
	int				len2;

	len2 = element->width - ((element->type == 'p') ? 2 : 0);
	if (element->width == 0 && element->type == 'p')
	{
		write(1, "0x", 2);
		element->len_mini_str = 2;
	}
	else
	{
		if (element->minus == 1 && element->type == 'p')
			write(1, "0x", 2);
		ft_write(' ', len2);
		if (element->minus == 0 && element->type == 'p')
			write(1, "0x", 2);
		element->len_mini_str = element->width;
	}
}
