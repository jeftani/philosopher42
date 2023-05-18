/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:05:34 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/18 01:26:02 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	todie(t_data *data)
{
	int		i;
	long	result;

	while (!data->max_ate)
	{
		i = -1;
		while (++i < data->count && !data->stop_it)
		{
			pthread_mutex_lock(&data->meal);
			if ((int)(timeoftheday()
				- data->philos[i].last_ate) >= data->time_to_die)
			{
				result = (int)(timeoftheday() - data->philos[i].last_ate);
				philo_print("is died", &data->philos[i]);
				pthread_mutex_lock(&data->extra);
				data->stop_it = 1;
				pthread_mutex_unlock(&data->extra);
			}
			pthread_mutex_unlock(&data->meal);
		}
		if (data->stop_it)
			break ;
		ft_limit_meals(data);
	}
}
