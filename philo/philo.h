#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

#define BOLD	"\001\x1b[1m\002"
#define RED		"\001\x1b[31m\002"
#define GREEN 	"\001\x1b[32m\002"
#define YELLOW	"\001\x1b[33m\002"
#define BLUE	"\001\x1b[34m\002"
#define MAGENTA	"\001\x1b[35m\002"
#define CYAN	"\001\x1b[36m\002"
#define RESET	"\001\x1b[0m\002"
#define N_PHILO	arr[0]
#define T_DIE 	arr[1]
#define T_EAT 	arr[2]
#define T_SLEEP	arr[3]
#define T_LOOP	arr[4]

// Actions
void		take_a_fork(int philo, struct timeval *time);
void		eat(int philo, struct timeval *time);
void		m_sleep(int philo, struct timeval *time);
void		think(int philo, struct timeval *time);
void		die(int philo, struct timeval *time);

// Check
int			check_int_extremes(char **args, int size);
int			check_invalid_arguments(char **args, int size);

// Utils
int			ft_isdigit(int c);
int			ft_isspace(char c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
long long	ft_atoll(const char *str);

#endif
