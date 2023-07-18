/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:24:25 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/07/18 10:37:39 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checkfunct(t_data **d)
{
	int	i;

	while (*d[0]->onedied == 0)
	{
		i = 0;
		while (i < d[0]->nump)
		{
			pthread_mutex_lock(d[i]->datam);//deadlock gone when rm this
			if (d[i]->lasteat + d[i]->ttodie <= (long) millsect(d[i])
			&& !*d[i]->lastprinted)
			{
				*d[i]->onedied = 1;
				mt_printf("%ld %i died\n", d[i]);
			}
			pthread_mutex_unlock(d[i]->datam);
			i++;
		}

	}
	//maybe exit here manually after checking the times for every philo

}
