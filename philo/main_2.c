/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:24:25 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/06/06 10:17:52 by fvon-nag         ###   ########.fr       */
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
			if (d[i]->lasteat + d[i]->ttodie <= (long) millsect(d[i]))
			{
				printf("%ld %i died\n", (long)millsect(d[i]), d[i]->philonum +1);
				*d[0]->onedied = 1;
				return ;
			}
			i++;
		}

	}
	//maybe exit here manually after checking the times for every philo

}