/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:24:25 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/07/19 13:15:36 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checkfunct(t_data **d)
{
	int	i;
	int	oneddied;

	oneddied = 0;
	while (!oneddied)
	{
		i = 0;
		while (i < d[0]->nump)
		{
			pthread_mutex_lock(d[i]->datam);//deadlock gone when rm this
			if (d[i]->lasteat + d[i]->ttodie <= (long) millsect(d[i])
				&& d[i]->timeseaten < d[i]->numberofndeats)
			{
				*d[i]->onedied = 1;
				oneddied = 1;
				mt_printf("%ld %i died\n", d[i]);
				return ;
			}
			else if (d[i]->timeseaten >= d[i]->numberofndeats)
				d[0]->nsfinishedprinting++; // now adds for every single one
			pthread_mutex_unlock(d[i]->datam);
			i++;
		}
		if (d[0]->numberofndeats && d[0]->nsfinishedprinting >= d[0]->nump)
			return ;
	}
	//maybe exit here manually after checking the times for every philo

}
