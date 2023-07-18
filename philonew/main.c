/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:07:19 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/07/18 11:12:13 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// maybe use usleeps with the time needed for eating instead or addition
// ./philo 4 310 200 100
// ./philo 5 800 200 200 someone dies still
// maybe need to unlock mutexes on dying
// need to find a way to exit clean, exit is forbidden

void	ptjoinall(t_data **d) // maybe do not need this
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
	int		lastprinted;

	//waited = 0;
	d = (t_data *) arg;
	gettimeofday(&d->time, NULL);
	d->lasteat = millsect(d);
	lastprinted = 0;
	//sleepmil(((d->philonum % 3) * d->ttoeat), d);
	while (!lastprinted && (d->timeseaten < d->numberofndeats
			|| d->numberofndeats == 0))
	{
		pthread_mutex_lock(d->datam);
		lastprinted = *d->lastprinted;
		pthread_mutex_unlock(d->datam);
		if (!lastprinted && grabforks(d) == 0)
			eatandsleep(d);
		if (lastprinted)
			return (NULL);
	}
	return (NULL);
}

int	filld(int argc, char **argv, t_data **d, int *isdead, int *lastprinted)
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
		d[i]->onedied = isdead;
		d[i]->lastprinted = lastprinted;
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
	t_data	**d;
	int		i;
	int		nump;
	int		isdead;
	int		lastprinted;

	isdead = 0;
	if (argc < 5)
		return (printf("Please enter at least 4 arguments!\n"), 0);
	i = 0;
	nump = ft_atoi(argv[1]);
	d = ft_calloc(nump, sizeof(t_data *));
	while (i < nump)
	{
		d[i] = ft_calloc(nump, sizeof(t_data));
		i++;
	}
	filld(argc, argv, d, &isdead, &lastprinted);
	initforks(d);
	assignforks(d);
	createthreads(d);
	checkfunct(d);
	ptjoinall(d);
	//destroy all mutexes
	free(d); //free every node seperate
	//free all forks free(d[0]->forks) and destroy all mutexes
}