/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:24:25 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/06/08 10:01:01 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checkfordeath(t_data **d)
{
	int	i;

	while (*d[0]->onedied == 0)
	{
		i = 0;
		while (i < d[0]->nump)
		{
			if (d[i]->lasteat + d[i]->ttodie <= (long) millsect(d[i])
				&& !pthread_mutex_lock(d[i]->onediedm))
			{
				mt_printf("%ld %i died\n", d[i]);
				*d[0]->onedied = 1;
				pthread_mutex_unlock(d[i]->onediedm);
			}
			i++;
		}

	}
	//maybe exit here manually after checking the times for every philo

}
