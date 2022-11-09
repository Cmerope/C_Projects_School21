#include "header.h"

long	get_time(struct timeval t)
{
	struct timeval	t2;

	gettimeofday(&t2, NULL);
	return ((t2.tv_sec - t.tv_sec) * 1000 + (t2.tv_usec - t.tv_usec) / 1000);
}

void	ft_status(t_args *args, char *str, int i)
{
	pthread_mutex_lock(&args->status);
	printf("%ld %d %s\n", get_time(args->start_simulation), args->number, str);
	if (i)
		pthread_mutex_unlock(&args->status);
}

int	ft_return(char *str, int result)
{
	printf("%s\n", str);
	return (result);
}
