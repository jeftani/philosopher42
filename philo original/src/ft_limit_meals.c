/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limit_meals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 01:24:15 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/18 01:26:52 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_limit_meals(t_data *data)
{
	int	j;

	j = 0;
	while (data->eat_count_max && j < data->count)
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
			break ;
		}
	}
	pthread_mutex_lock(&data->max_eat_m);
	data->max_ate = (j == data->count);
	pthread_mutex_unlock(&data->max_eat_m);
}
