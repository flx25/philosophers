/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:52:17 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/06/13 12:51:03 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mt_printf(char *str, t_data *d)
{
	int	out;

	out = 0;
	if (!pthread_mutex_lock(d->printfm)) // does not work for when someone dies
	{
		if (*d->onedied && ft_strcmp(str, "%ld %i died\n"))
		{
			pthread_mutex_unlock(d->printfm);
			return (out);
		}


		out = printf(str, (long)millsect(d), d->philonum +1);
		pthread_mutex_unlock(d->printfm);
	}

	// out = printf(str, (long)millsect(d), d->philonum +1); // testing only
	return (out);
}
