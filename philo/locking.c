/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:14:16 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/03/21 11:24:51 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grabforks(t_data *d)
{
	if (d->nump == 1)
		return (1);
	if (pthread_mutex_lock(&d->forks[d->fork1]) == 0)
	{
		if (d->lasteat + d->ttodie <= (long) millsect(d))
		{
			pthread_mutex_unlock(&d->forks[d->fork1]);
			return (1);
		}
		printf("%ld %i has taken a fork\n", (long)millsect(d), d->philonum +1);
		if (pthread_mutex_lock(&d->forks[d->fork2]) == 0)
		{
			printf("%ld %i has taken a fork\n",
				(long)millsect(d), d->philonum +1);
			return (0);
		}
		else
			pthread_mutex_unlock(&d->forks[d->fork1]);
	}
	return (1);
}

int	eatandsleep(t_data *d)
{
	long	currenttime;

	currenttime = millsect(d);
	if (currenttime + d->ttoeat > d->lasteat + d->ttodie)
	{
		pthread_mutex_unlock(&d->forks[d->philonum]);
		pthread_mutex_unlock(&d->forks[(d->philonum + 1) % d->nump]);
		return (1);
	}
	printf("%ld %i is eating\n", (long)millsect(d), d->philonum +1);
	usleep(d->ttoeat * 1000);
	d->lasteat = millsect(d);
	d->timeseaten++;
	pthread_mutex_unlock(&d->forks[d->philonum]);
	pthread_mutex_unlock(&d->forks[(d->philonum + 1) % d->nump]);
	printf("%ld %i is sleeping\n", (long)millsect(d), d->philonum +1);
	usleep(d->ttosleep * 1000);
	printf("%ld %i is thinking\n", (long)millsect(d), d->philonum +1);
	return (0);
}
