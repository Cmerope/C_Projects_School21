#include "header.h"

int	ft_check_dead(t_args *arr_philo, int philo, int time_to_live)
{
	int	i;
	int	time;

	i = 1;
	while (i && !arr_philo[i - 1].i_am_full)
	{
		time = (int)get_time(arr_philo[i - 1].start_to_eat);
		if (time > time_to_live)
		{
			pthread_mutex_lock(&arr_philo[0].dead);
			ft_status(&arr_philo[i - 1], "died", 0);
			pthread_mutex_unlock(&arr_philo[0].dead);
			return (1);
		}
		if (i == philo - 1)
			break ;
		i++;
	}
	return (0);
}

int	ft_check_full(t_args *arr_philo)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i && arr_philo[i - 1].i_am_full)
	{
		if (arr_philo[i - 1].i_am_full)
			j++;
		if (j == arr_philo->number)
			return (1);
	}
	return (0);
}

int	ft_monitor(t_args *arr_philo, int philo, int time_to_live)
{
	while (1)
	{
		if (ft_check_dead(arr_philo, philo, time_to_live))
			return (1);
		if (ft_check_full(arr_philo))
			return (1);
	}
	return (0);
}

void	ft_only_one(t_args *args)
{
	pthread_mutex_lock(args->left_fork);
	printf("%ld %d %s\n", get_time(args->start_simulation), args->number,
		"take left fork");
	ft_time_counter(args->start_simulation, args->time_to_live);
	printf("%ld %d %s\n", get_time(args->start_simulation), args->number,
		"died");
	pthread_mutex_unlock(args->left_fork);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_args	*arr_philo;

	if (argc != 6 && argc != 5)
		return (ft_return("ERROR: wrong number of arguments", 1));
	init_struct(&args);
	gettimeofday(&args.start_simulation, NULL);
	if (ft_parser(argv, argc, &args) == 1)
		return (1);
	ft_init_mutex(&args);
	arr_philo = (t_args *)malloc(sizeof(t_args) * args.philo);
	if (!arr_philo)
		return (ft_return("ERROR: wrong malloc", 1));
	ft_arr_philo(args, arr_philo);
	if (args.philo == 1)
	{
		ft_only_one(&arr_philo[0]);
		free(arr_philo);
		free(args.arr_fork);
		return (0);
	}
	ft_start_simulation(arr_philo);
	ft_monitor(arr_philo, args.philo, args.time_to_live);
	return (0);
}
