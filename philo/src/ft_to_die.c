/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:05:34 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/11 14:50:27 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void todie(t_data *data)
{
	int i;
	long result;
	while(!data->max_ate)
	{
		i = -1;
		while(++i < data->count && !data->stop_it)
		{
			pthread_mutex_lock(&data->meal);
			if((int)(timeoftheday() - data->philos[i].last_ate) >= data->time_to_die)
			{
					result = (int)(timeoftheday() - data->philos[i].last_ate);
					philo_print("is died",&data->philos[i]);
					pthread_mutex_lock(&data->extra);
						data->stop_it = 1;
					pthread_mutex_unlock(&data->extra);
			}
			pthread_mutex_unlock(&data->meal);
		}
			if(data->stop_it)
				break;
			int j = 0;

			while ( data->eat_count_max && j < data->count)
			{
				pthread_mutex_lock(&data->eat_time_m);
				if (data->philos[j].ate_times >= data->eat_count_max)
				{
				 j++;
				 pthread_mutex_unlock(&data->eat_time_m);
				}
				else
					{
						pthread_mutex_unlock(&data->eat_time_m);
						break;
					}

			}
				pthread_mutex_lock(&data->max_eat_m);
				data->max_ate = (j == data->count);
				pthread_mutex_unlock(&data->max_eat_m);
			}
}