/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:14:16 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/03/16 17:38:32 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//either last one does not eat at all, or i get a deadlock %mondulo -> problem lies with behavior of pthread other solution needed (deadlock)
int	grabforks(t_data *d)
{
	if (d->nump == 1)
		return (1);
	if (pthread_mutex_lock(&d->forks[d->philonum % d->nump]) == 0)
	{
		printf("%ld %i has taken a fork\n", (long)millsect(d), d->philonum);
		if (pthread_mutex_lock(&d->forks[(d->philonum + 1) % d->nump]) == 0)
		{
			printf("%ld %i has taken a fork\n", (long)millsect(d), d->philonum);
			return (0);
		}
		else
			pthread_mutex_unlock(&d->forks[d->philonum]);
	}
	return (1);
}

void	eatandsleep(t_data *d)
{
	printf("%ld %i is eating\n", (long)millsect(d), d->philonum);
	usleep(d->ttoeat * 1000);
	d->lasteat = millsect(d);
	d->timeseaten++;
	pthread_mutex_unlock(&d->forks[d->philonum]);
	pthread_mutex_unlock(&d->forks[(d->philonum + 1) % d->nump]);
	printf("%ld %i is sleeping\n", (long)millsect(d), d->philonum);
	usleep(d->ttosleep * 1000);
	printf("%ld %i is thinking\n", (long)millsect(d), d->philonum);
}
