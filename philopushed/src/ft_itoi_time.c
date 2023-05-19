/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 01:17:59 by ajeftani          #+#    #+#             */
/*   Updated: 2023/05/18 01:18:32 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	timeoftheday(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_intcounter(int number)
{
	int	lentgh;

	lentgh = 0;
	if (number <= 0)
		lentgh++;
	while (number != 0)
	{
		lentgh++;
		number = number / 10;
	}
	return (lentgh);
}

char	*ft_itoa(int n)
{
	char		*myres;
	int			lentgh;
	long long	number;

	lentgh = ft_intcounter(n);
	number = (long)n;
	myres = (char *)malloc((lentgh + 1) * sizeof(char));
	if (!myres)
		return (0);
	if (number < 0)
	{
		myres[0] = '-';
		number *= -1;
	}
	if (number == 0)
		myres[0] = '0';
	myres[lentgh--] = '\0';
	while (number)
	{
		myres[lentgh--] = (number % 10) + '0';
		number /= 10;
	}
	return (myres);
}
