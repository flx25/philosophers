/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:07:19 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/03/14 11:38:53 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ptjoinall(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nump)
	{
		pthread_join(d->tids[i], NULL);
		i++;
	}
}

void	*philo(void *arg)
{
	t_data	*d;
	int		philnum;

	d = (t_data *) arg;
	philnum = d->philonum;
	printf("Runs\n ");
	printf("Philo number: %i\n", philnum);

	return (NULL);
}

int	filld(int argc, char **argv, t_data *d)
{
	if (argc < 5)
	{
		printf("Please enter at least 4 arguments!\n");
		return (1);
	}
	d->nump = ft_atoi(argv[1]);
	d->ttodie = ft_atoi(argv[2]);
	d->ttoeat = ft_atoi(argv[3]);
	d->ttosleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->numberofeats = ft_atoi(argv[5]);
	d->tids = malloc(d->nump * sizeof(pthread_t));
	if (d->tids == NULL)
		return (1);
	return (0);
}

void	createthreads(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nump)
	{
		d->philonum = i + 1;
		pthread_create(&d->tids[i], NULL, philo, d);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (filld(argc, argv, &d) == 1)
		return (0);
	createthreads(&d);
	ptjoinall(&d);
	free(d.tids);
}
