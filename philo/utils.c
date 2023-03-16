/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:58:19 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/03/16 10:58:07 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initforks(t_data **d)
{
	int				i;
	pthread_mutex_t	*out;

	out = malloc(d[0]->nump * sizeof(pthread_mutex_t));
	i = 0;
	while (i < d[0]->nump)
		pthread_mutex_init(&out[i++], NULL);
	i = 0;
	while (i < d[0]->nump)
		d[i++]->forks = out;
}

double	millsect(t_data *d)
{
	long double	out;

	gettimeofday(&d->time, NULL);
	out = d->time.tv_sec * 1000 + d->time.tv_usec / 1000;
	return (out);
}
