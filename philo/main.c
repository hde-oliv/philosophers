/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:06:22 by hde-oliv          #+#    #+#             */
/*   Updated: 2022/05/28 22:06:23 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_int_args_array(char **args, int argc, int arr[5])
{
	arr[0] = ft_atoi(args[0]);
	arr[1] = ft_atoi(args[1]);
	arr[2] = ft_atoi(args[2]);
	arr[3] = ft_atoi(args[3]);
	if (argc != 6)
		arr[4] = 0;
	else
		arr[4] = ft_atoi(args[4]);
}

int	main(int argc, char *argv[])
{
	int				arr[5];
	char			**args;

	args = &argv[1];
	if (argc < 5 || argc > 6)
		return (printf(RED "Error: " RESET "Invalid argument list\n"));
	if (!arguments_are_valid(argc - 1, args))
		return (printf(RED "Error: " RESET \
					"Invalid argument in argument list\n"));
	create_int_args_array(args, argc, arr);
	start_simulation(arr);
	return (0);
}
