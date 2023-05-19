/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:13:10 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/18 03:18:33 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_free_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count)
	{
		pthread_mutex_destroy(&data->forks[i++]);
	}
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->writing);
	pthread_mutex_destroy(&data->extra);
	pthread_mutex_destroy(&data->max_eat_m);
	pthread_mutex_destroy(&data->eat_time_m);
	i = -1;
	while (++i < data->count)
		free(data->philos[i].pos_str);
	free(data->philos);
	free(data->forks);
}
