/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:24:25 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/07/31 14:44:07 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkforallprinted(t_data **d)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	while (i < d[0]->nump)
	{
		if (d[i]->finished == 1)
			finished++;
		i++;
	}
	if (finished == d[0]->nump)
	{
		*d[0]->allfinished = 1;
		return (1);
	}
	else
		return (0);
}

int	checkfunct(t_data **d)
{
	int	i;
	int	oneddied;

	oneddied = 0;
	while (!oneddied)
	{
		i = 0;
		while (i < d[0]->nump)
		{
			pthread_mutex_lock(d[i]->datam);
			if (d[i]->lasteat + d[i]->ttodie <= (long) millsect(d[i])
				&& (d[i]->timeseaten < d[i]->numberofndeats
					|| !d[i]->numberofndeats))
			{
				*d[i]->onedied = 1;
				oneddied = 1;
				return (mt_printf("%ld %i died\n", d[i]), 0);
			}
			if (checkforallprinted(d))
				return (pthread_mutex_unlock(d[i]->datam), 0);
			pthread_mutex_unlock(d[i]->datam);
			i++;
		}
	}
	return (0);
}

void	freefunct(t_data **d)
{
	int	i;
	int	nump;

	i = 0;
	while (i < d[0]->nump)
		pthread_mutex_destroy(d[i++]->forks);
	free(d[0]->forks);
	pthread_mutex_destroy(d[0]->datam);
	free(d[0]->datam);
	pthread_mutex_destroy(d[0]->printfm);
	free(d[0]->printfm);
	i = 0;
	nump = d[0]->nump;
	while (i < nump)
		free(d[i++]);
	free(d);
}

void	detachall(t_data **d)
{
	int	i;

	i = 0;
	while (i < d[0]->nump)
	{
		pthread_detach(d[i]->tid);
		i++;
	}
}
