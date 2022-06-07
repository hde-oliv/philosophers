/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:46 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/05/28 22:06:47 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>

int	check_if_must_continue(t_data *data)
{
	int		i;
	int		eaten;
	t_philo	**philos;

	i = (data->args[T_PHILO]) - 1;
	eaten = 0;
	philos = data->t_philos;
	while (i != -1)
	{
		if ((get_timestamp() - (philos[i])->last_meal) > (size_t)data->args[T_DIE])
		{
			p_die(get_timestamp(), philos[i]);
			return (1);
		}
		if ((philos[i])->times_eaten >= (data->args)[T_LOOP])
			eaten++;
		i--;
	}
	if (data->args[T_LOOP] && (eaten >= (data->args)[T_PHILO]))
		return (1);
	return (0);
}

void	*watcher_routine(void *watcher_data)
{
	t_data	*data;

	data = watcher_data;
	while (!data->simulation)
	{
		data->simulation = check_if_must_continue(data);
		usleep(1000);
	}
	return (NULL);
}

void	create_watcher(t_data *data)
{
	pthread_t	watcher;

	pthread_create(&watcher, NULL, &watcher_routine, data);
	pthread_join(watcher, NULL);
}

void	destroy_everything(t_data *data)
{
	int		i;
	t_philo	**philos;

	i = (data->args)[0] - 1;
	philos = data->t_philos;
	while (i != -1)
	{
		pthread_mutex_destroy((data->mutexes)[i]);
		free((data->mutexes)[i]);
		free((data->philos)[i]);
		free(philos[i]);
		i--;
	}
	free(data->mutexes);
	free(data->philos);
	free(philos);
	free(data);
}
