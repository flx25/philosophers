/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:14:16 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/05/24 14:31:46 by fvon-nag         ###   ########.fr       */
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
	if (d->ttodie < d->ttoeat)
		return (1);
	d->lasteat = millsect(d);
	d->timeseaten++;
	printf("%ld %i is eating\n", (long) d->lasteat, d->philonum +1);
	sleepmil(d->ttoeat, d);
	pthread_mutex_unlock(&d->forks[d->fork2]);
	pthread_mutex_unlock(&d->forks[d->fork1]);
	if (*d->onedied == 1)
		return (1);
	printf("%ld %i is sleeping\n", (long)millsect(d), d->philonum +1);
	sleepmil(d->ttosleep, d);
	printf("%ld %i is thinking\n", (long)millsect(d), d->philonum +1);
	// if (d->philonum % 2 == 1) //-> seems to work better without this
	// 	sleepmil(((d->ttoeat * 2) - d->ttosleep), d);
	return (0);
}
