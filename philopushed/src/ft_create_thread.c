/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:23:41 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/19 13:22:01 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_usleep(long time)
{
	long	start;

	start = timeoftheday();
	while (timeoftheday() - start < time)
		usleep(30);
}

void	*routine(void *param)
{
	t_philo	*philo;
	int		max;
	int		stop;

	philo = (t_philo *)param;
	while (1)
	{
		pthread_mutex_lock(&philo->data->max_eat_m);
		max = philo->data->max_ate;
		pthread_mutex_unlock(&philo->data->max_eat_m);
		pthread_mutex_lock(&philo->data->extra);
		stop = philo->data->stop_it;
		pthread_mutex_unlock(&philo->data->extra);
		if (!(!max && !stop))
			break ;
		philo_eat(philo);
		philo_print("is sleeping", philo);
		ft_usleep(philo->data->time_to_sleep);
		philo_print("is thinking", philo);
	}
	return (NULL);
}

int	ft_create_thread(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = timeoftheday();
	while (++i < data->count)
	{
		data->philos[i].data = data;
		data->philos[i].last_ate = timeoftheday();
		if (pthread_create(&(data->philos[i].thread_id), NULL, routine,
				&data->philos[i]))
			return (1);
		usleep(50);
	}
	todie(data);
	i = 0;
	if (data->count == 1)
		pthread_detach(data->philos[0].thread_id);
	else
	{
		while (i < data->count)
			pthread_join(data->philos[i++].thread_id, NULL);
	}
	ft_free_destroy(data);
	return (1);
}
