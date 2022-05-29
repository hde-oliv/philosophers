/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:25 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/05/28 22:06:26 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <bits/pthreadtypes.h>
# include <pthread.h>
# include <unistd.h>

# define BOLD		"\001\x1b[1m\002"
# define RED		"\001\x1b[31m\002"
# define GREEN 		"\001\x1b[32m\002"
# define YELLOW		"\001\x1b[33m\002"
# define BLUE		"\001\x1b[34m\002"
# define MAGENTA	"\001\x1b[35m\002"
# define CYAN		"\001\x1b[36m\002"
# define RESET		"\001\x1b[0m\002"

enum e_philo
{
	T_PHILO = 0,
	T_DIE,
	T_EAT,
	T_SLEEP,
	T_LOOP,
};

typedef enum e_action
{
	FIRST_FORK,
	SECOND_FORK,
	EAT,
	SLEEP,
	THINK,
}	t_action;

typedef struct s_data
{
	int				died;
	size_t			start_time;
	int				*args;
	pthread_t		**philos;
	pthread_mutex_t	**mutexes;
	void			*t_philos;
}	t_data;

typedef struct s_philo
{
	int				*args;
	int				number;
	size_t			last_meal;
	int				times_eaten;
	size_t			start_time;
	t_data			*data;
	pthread_mutex_t	**mutexes;
}	t_philo;

// Prints
void		p_take_a_fork(t_philo *philo);
size_t		p_eat(t_philo *philo);
void		p_sleep(t_philo *philo);
void		p_think(t_philo *philo);
void		p_die(t_philo *philo);

// Check
int			check_int_extremes(char **args, int size);
int			check_invalid_arguments(char **args, int size);
int			arguments_are_valid(int argc, char **args);

// Utils
int			ft_isdigit(int c);
int			ft_isspace(char c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
long long	ft_atoll(const char *str);

// Time
size_t		get_timestamp(void);

// Simulation
int			start_simulation(int arr[5]);

// Constructors
void		create_data_struct(t_data **data, int arr[5]);
t_philo		*create_philo_data(int *args, int number, t_data *data);
void		create_array_of_philo_data(t_philo ***p_arr, \
									int arr[5], t_data **data);

// Watcher
void		create_watcher(t_data *data);

// Action
int			do_action(t_action ac, t_philo *philo);
#endif
