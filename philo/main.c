/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:07:19 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/08/01 14:44:32 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 1 800 200 200
// ./philo 5 800 200 200
// ./philo 5 800 200 200 7
// ./philo 4 410 200 200
// ./philo 4 310 200 100

void	ptjoinall(t_data **d)
{
	int	i;

	i = 0;
	while (i < d[0]->nump && *d[0]->onedied == 0)
	{
		pthread_join(d[i]->tid, NULL);
		i++;
	}
}

void	*philo(void *arg)
{
	t_data	*d;

	d = (t_data *) arg;
	gettimeofday(&d->time, NULL);
	pthread_mutex_lock(d->datam);
	d->lasteat = millsect(d);
	pthread_mutex_unlock(d->datam);
	while ((d->timeseaten < d->numberofndeats
			|| d->numberofndeats == 0))
	{
		if (grabforks(d) == 0)
			eatandsleep(d);
		pthread_mutex_lock(d->datam);
		if (d->timeseaten >= d->numberofndeats && d->numberofndeats)
			return (pthread_mutex_unlock(d->datam), NULL);
		pthread_mutex_unlock(d->datam);
	}
	return (NULL);
}

int	filld(int argc, char **argv, t_data **d, t_mainstruct *ms)
{
	int	i;
	int	nump;

	i = 0;
	nump = ft_atoi(argv[1]);
	while (i < nump)
	{
		d[i]->nump = nump;
		d[i]->ttodie = ft_atoi(argv[2]);
		d[i]->ttoeat = ft_atoi(argv[3]);
		d[i]->ttosleep = ft_atoi(argv[4]);
		d[i]->philonum = i;
		d[i]->onedied = &ms->isdead;
		d[i]->allfinished = &ms->finishedall;
		d[i]->lastprinted = &ms->lastprinted;
		if (argc == 6)
			d[i]->numberofndeats = ft_atoi(argv[5]);
		i++;
	}
	return (0);
}

void	createthreads(t_data **d)
{
	int	i;

	i = 0;
	while (i < d[0]->nump)
	{
		d[i]->starttime = millsect(d[i]);
		pthread_create(&d[i]->tid, NULL, philo, d[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data			**d;
	t_mainstruct	ms;

	ft_memset(&ms, 0, sizeof(t_mainstruct));
	if (argc < 5)
		return (printf("Please enter at least 4 arguments!\n"), 0);
	ms.nump = ft_atoi(argv[1]);
	d = ft_calloc(ms.nump, sizeof(t_data *));
	while (ms.i < ms.nump)
	{
		d[ms.i] = ft_calloc(ms.nump, sizeof(t_data));
		ms.i++;
	}
	filld(argc, argv, d, &ms);
	initforks(d);
	assignforks(d);
	createthreads(d);
	checkfunct(d);
	ptjoinall(d);
	detachall(d);
	freefunct(d);
	return (0);
}
