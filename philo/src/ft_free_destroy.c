/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:13:10 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/11 13:09:57 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void ft_free_destroy(t_data *data)
{
	int i = 0;
	while(i < data->count)
	{
		int number = pthread_mutex_destroy(&data->forks[i++]);
		if(number == 0)
			printf("mutex not destroyed");
	}
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->writing);
	pthread_mutex_destroy(&data->extra);
	pthread_mutex_destroy(&data->max_eat_m);
	pthread_mutex_destroy(&data->eat_time_m);

		//free(data->philos);
		//free(data->forks);
	i = 0;
	while(i < data->count)
	{
		free(data->philos[i].pos_str);
		i++;
	}
}