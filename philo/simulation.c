#include "header.h"

void	ft_time_counter(struct timeval start_time, int end_time)
{
	long	wait;

	wait = get_time(start_time) + end_time;
	while (get_time(start_time) < wait)
		usleep(10);
}

void	ft_take_fork(t_args *args)
{
	pthread_mutex_lock(args->left_fork);
	ft_status(args, "take left fork", 1);
	pthread_mutex_lock(args->right_fork);
	ft_status(args, "take right fork", 1);
	gettimeofday(&args->start_to_eat, NULL);
	ft_status(args, "is eating", 1);
	ft_time_counter(args->start_simulation, args->time_to_eat);
	pthread_mutex_unlock(args->left_fork);
	pthread_mutex_unlock(args->right_fork);
}

void	ft_sleep(t_args *args)
{
	ft_status(args, "is sleeping", 1);
	ft_time_counter(args->start_simulation, args->time_to_sleep);
}

void	*ft_threads(void *tmp)
{
	int		count;
	t_args	*args;

	count = -1;
	args = (t_args *)tmp;
	if (args->meals)
		count = args->meals;
	while (count)
	{
		if (args->number % 2 == 1)
			usleep(10);
		ft_take_fork(args);
		ft_sleep(args);
		ft_status(args, "is thinking", 1);
		if (count != -1)
			count--;
	}
	args->i_am_full = 1;
	return (NULL);
}

void	ft_start_simulation(t_args *arr_philo)
{
	int			i;

	i = 0;
	while (i < arr_philo[0].philo)
	{
		pthread_create(&arr_philo[i].thread_phil, NULL,
			ft_threads, &arr_philo[i]);
		usleep(500);
		i++;
	}
}
