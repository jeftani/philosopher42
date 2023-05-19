/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:36:05 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/19 00:08:50 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		data->philos[i].ate_times = 0;
		data->philos[i].ffork = i;
		data->philos[i].sfork = (i + 1) % data->count;
		data->philos[i].pos = i + 1;
		data->philos[i].pos_str = ft_itoa(i + 1);
		i++;
	}
}

int	ft_mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL))
			return (1);
	}
	if (pthread_mutex_init(&data->meal, NULL))
		return (0);
	if (pthread_mutex_init(&data->writing, NULL))
		return (0);
	if (pthread_mutex_init(&data->extra, NULL))
		return (0);
	if (pthread_mutex_init(&data->max_eat_m, NULL))
		return (0);
	if (pthread_mutex_init(&data->eat_time_m, NULL))
		return (0);
	ft_init_philos(data);
	return (1);
}

int	ft_fill(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->count);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->count);
	if (data->forks == NULL)
		return (0);
	ft_mutex_init(data);
	return (1);
}

int	ft_init(t_data *data, char **argv, int argc)
{
	data->count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->eat_count_max = ft_atoi(argv[5]);
	ft_fill(data);
	return (1);
}
