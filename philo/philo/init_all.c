#include "header.h"

void	init_struct(t_args *args)
{
	args->number = 0;
	args->philo = 0;
	args->time_to_live = 0;
	args->i_am_full = 0;
	args->time_to_eat = 0;
	args->time_to_sleep = 0;
	args->meals = 0;
	args->died = 0;
}

void	ft_init_mutex(t_args *args)
{
	int	i;

	i = 0;
	args->arr_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* args->philo);
	while (i < args->philo)
	{
		pthread_mutex_init(&args->arr_fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&args->dead, NULL);
	pthread_mutex_init(&args->status, NULL);
}

void	ft_arr_philo(t_args args, t_args *arr_philo)
{
	int	i;

	i = 0;
	while (i < args.philo)
	{
		arr_philo[i].thread_phil = args.thread_phil;
		arr_philo[i].number = i + 1;
		arr_philo[i].philo = args.philo;
		arr_philo[i].time_to_live = args.time_to_live;
		arr_philo[i].i_am_full = args.i_am_full;
		arr_philo[i].start_simulation = args.start_simulation;
		arr_philo[i].died = args.died;
		arr_philo[i].time_to_eat = args.time_to_eat;
		arr_philo[i].time_to_sleep = args.time_to_sleep;
		arr_philo[i].meals = args.meals;
		arr_philo[i].left_fork = &args.arr_fork[i];
		if (args.philo > 1)
			arr_philo[i].right_fork = &args.arr_fork[(i + 1) % args.philo];
		i++;
	}
}
