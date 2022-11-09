#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args
{
	int				number;
	int				philo;
	int				time_to_live;
	int				i_am_full;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				died;
	pthread_t		thread_phil;
	struct timeval	start_to_eat;
	struct timeval	start_simulation;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*arr_fork;
	pthread_mutex_t	status;
	pthread_mutex_t	dead;

}					t_args;

void	init_struct(t_args *args);
void	ft_init_mutex(t_args *args);
void	ft_arr_philo(t_args args, t_args *arr_philo);
int		ft_parser(char **argv, int argc, t_args *args);
void	ft_start_simulation(t_args *args);
void	ft_time_counter(struct timeval start_time, int time_to_sleep);
long	get_time(struct timeval time);
void	ft_status(t_args *args, char *str, int i);
int		ft_return(char *str, int result);
#endif
