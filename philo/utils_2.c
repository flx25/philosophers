/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:52:17 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/06/08 15:21:53 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mt_printf(char *str, t_data *d)
{
	int	out;

	out = 0;
	if (!pthread_mutex_lock(d->onediedm)) // does not work for when someone dies
	{
		if (*d->onedied)
		{
			pthread_mutex_unlock(d->onediedm);
			return (out);
		}
		pthread_mutex_unlock(d->onediedm);
		pthread_mutex_lock(d->printfm);
		out = printf(str, (long)millsect(d), d->philonum +1);
		pthread_mutex_unlock(d->printfm);
	}

	// out = printf(str, (long)millsect(d), d->philonum +1); // testing only
	return (out);
}
