/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:07:19 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/03/16 11:39:16 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//need to fix die timer
void	ptjoinall(t_data **d)
{
	int	i;

	i = 0;
	while (i < d[0]->nump)
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
	d->lasteat = millsect(d);
	printf("%i\n", d->nump);
	while (d->timeseaten < d->numberofndeats || d->numberofndeats == 0)
	{
		if (grabforks(d) == 0)
			eatandsleep(d);
		if (d->lasteat + d->ttodie >= millsect(d))
		{
			printf("%ld %i died\n", (long)millsect(d), d->philonum);
			return (NULL);
		}
	}
	return (NULL);
}

int	filld(int argc, char **argv, t_data **d)
{
	int	i;
	int	nump;

	if (argc < 5)
	{
		printf("Please enter at least 4 arguments!\n");
		return (1);
	}
	i = 0;
	nump = ft_atoi(argv[1]);
	while (i < nump)
	{
		d[i]->nump = nump;
		d[i]->ttodie = ft_atoi(argv[2]);
		d[i]->ttoeat = ft_atoi(argv[3]);
		d[i]->ttosleep = ft_atoi(argv[4]);
		d[i]->philonum = i + 1;
		d[i]->timeseaten = 0;
		if (argc == 6)
			d[i]->numberofndeats = ft_atoi(argv[5]);
		else
			d[i]->numberofndeats = 0;
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
		pthread_create(&d[i]->tid, NULL, philo, d[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	**d;
	int		i;
	int		nump;

	i = 0;
	nump = ft_atoi(argv[1]);
	d = malloc(nump * sizeof(t_data *));
	while (i < nump)
	{
		d[i] = malloc(nump * sizeof(t_data));
		i++;
	}
	if (filld(argc, argv, d) == 1)
		return (0);
	initforks(d);
	createthreads(d);
	ptjoinall(d);
	//destroy all mutexes
	free(d); //free every node seperate
	//free all forks free(d[0]->forks) and destroy all mutexes
}
