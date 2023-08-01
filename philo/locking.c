/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:14:16 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/08/01 14:41:05 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	grabforks(t_data *d)
{
	if (d->nump == 1 || d->ttodie < d->ttoeat || d->ttodie < d->ttosleep
		|| d->lasteat + d->ttodie <= (long) millsect(d))
		return (1);
	if (pthread_mutex_lock(&d->forks[d->fork1]) == 0)
	{
		if (d->lasteat + d->ttodie <= (long) millsect(d))
		{
			pthread_mutex_unlock(&d->forks[d->fork1]);
			return (1);
		}
		pthread_mutex_lock(d->datam);
		mt_printf("%ld %i has taken a fork\n", d);
		pthread_mutex_unlock(d->datam);
		if (pthread_mutex_lock(&d->forks[d->fork2]) == 0)
		{
			pthread_mutex_lock(d->datam);
			mt_printf("%ld %i has taken a fork\n", d);
			pthread_mutex_unlock(d->datam);
			return (0);
		}
		else
			pthread_mutex_unlock(&d->forks[d->fork1]);
	}
	return (1);
}

int	eatandsleep(t_data *d)
{
	if (d->ttodie < d->ttoeat || d->ttodie < d->ttosleep
		|| d->lasteat + d->ttodie <= (long) millsect(d))
		return (1);
	eatandsleep_middle(d);
	pthread_mutex_lock(d->datam);
	if (d->timeseaten >= d->numberofndeats && d->numberofndeats)
	{
		d->finished = 1;
		return (pthread_mutex_unlock(d->datam), 1);
	}
	pthread_mutex_unlock(d->datam);
	pthread_mutex_lock(d->datam);
	mt_printf("%ld %i is sleeping\n", d);
	pthread_mutex_unlock(d->datam);
	if (d->lasteat + d->ttodie <= (long) millsect(d)
		+ d->ttosleep || *d->onedied)
		return (1);
	sleepmil(d->ttosleep, d);
	pthread_mutex_lock(d->datam);
	mt_printf("%ld %i is thinking\n", d);
	pthread_mutex_unlock(d->datam);
	return (0);
}

void	eatandsleep_middle(t_data *d)
{
	pthread_mutex_lock(d->datam);
	d->lasteat = millsect(d);
	d->timeseaten++;
	pthread_mutex_unlock(d->datam);
	pthread_mutex_lock(d->datam);
	mt_printf("%ld %i is eating\n", d);
	pthread_mutex_unlock(d->datam);
	sleepmil(d->ttoeat, d);
	pthread_mutex_unlock(&d->forks[d->fork2]);
	pthread_mutex_unlock(&d->forks[d->fork1]);
}
