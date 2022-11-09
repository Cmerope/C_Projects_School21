#include "header.h"

int	ft_check_digit(char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp != '\0')
	{
		if (!(*tmp >= '0' && *tmp <= '9'))
			return (-1);
		tmp++;
	}
	return (0);
}

int	ft_check_space(char c)
{
	if ((c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r'))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int					m;
	unsigned long int	res;

	if (ft_check_digit(str) == -1)
		return (-1);
	while (ft_check_space(*str) == 1)
		str++;
	m = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			m = (-1);
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((res > 9223372036854775807) && m == (-1))
			return (0);
		if (res > 9223372036854775807)
			return (-1);
		str++;
	}
	return (res * m);
}

int	ft_parser(char **argv, int argc, t_args *args)
{
	int		i;
	long	nb;

	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb <= 0)
			return (ft_return("ERROR: incorrect number", 1));
		if (i == 1)
			args->philo = nb;
		else if (i == 2)
			args->time_to_live = nb;
		else if (i == 3)
			args->time_to_eat = nb;
		else if (i == 4)
			args->time_to_sleep = nb;
		else if (i == 5)
			args->meals = nb;
		i++;
	}
	return (0);
}
