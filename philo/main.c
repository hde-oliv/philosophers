#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <unistd.h>

int	arguments_are_valid(int argc, char **args)
{
	if (check_invalid_arguments(args, argc))
		return (0);
	if (check_int_extremes(args, argc))
		return (0);
	return (1);
}

void	create_int_args_array(char **args, int argc, int arr[5])
{
	arr[0] = ft_atoi(args[0]);
	arr[1] = ft_atoi(args[1]);
	arr[2] = ft_atoi(args[2]);
	arr[3] = ft_atoi(args[3]);
	if (argc != 6)
		arr[4] = -1;
	else
		arr[4] = ft_atoi(args[4]);
}

typedef struct	s_data
{
	int				*arr;
	int				no;
	pthread_mutex_t	**mutex;
	struct timeval	*time;
}	t_data;

void	*routine(void *data)
{
	int	i;
	int	*arr;
	pthread_mutex_t	**mutex;
	int	times;

	i = ((t_data *)data)->no;
	arr = ((t_data *)data)->arr;
	mutex = ((t_data *)data)->mutex;
	times = T_LOOP;
	while (times != 0)
	{
		think(i, ((t_data *)data)->time);
		if (!pthread_mutex_lock(mutex[i - 1]))
			take_a_fork(i, ((t_data *)data)->time);
		if (!pthread_mutex_lock(mutex[i % N_PHILO]))
			take_a_fork(i, ((t_data *)data)->time);
		eat(i, ((t_data *)data)->time);
		usleep(T_EAT);
		pthread_mutex_unlock(mutex[i % N_PHILO]);
		pthread_mutex_unlock(mutex[i - 1]);
		m_sleep(1, ((t_data *)data)->time);
		usleep(T_SLEEP);
		times--;
	}
	return (NULL);
}

int	start_simulation(struct timeval *time, int arr[5])
{
	pthread_t		*philo;
	pthread_mutex_t	**mutex;
	int			i;
	t_data		data;

	philo = (pthread_t *)malloc(sizeof(pthread_t) * N_PHILO);
	mutex = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * N_PHILO);
	i = N_PHILO - 1;
	while (i != -1)
	{
		philo[i] = (pthread_t)malloc(sizeof(pthread_t));
		mutex[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(mutex[i], NULL);
		i--;
	}
	i = N_PHILO - 1;
	data.arr = arr;
	data.time = time;
	data.mutex = mutex;
	while (i != -1)
	{
		data.no = i + 1;
		pthread_create(&philo[i], NULL, &routine, &data);
		pthread_join(philo[i], NULL);
		i--;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int				arr[5];
	char			**args;
	struct timeval	time;

	args = &argv[1];
	if (argc < 5 || argc > 6)
		return (printf(RED "Error: " RESET "Invalid argument list\n"));
	if (!arguments_are_valid(argc - 1, args))
		return (printf(RED "Error: " RESET "Invalid argument in argument list\n"));
	create_int_args_array(args, argc, arr);
	(void)time;
	start_simulation(&time, arr);
	return (0);
}
