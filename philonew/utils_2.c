/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:52:17 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/07/18 10:53:25 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// empty output when mutex is locked
// make lastprinted variable
int	mt_printf(char *str, t_data *d)
{
	int	out;
	int	onedied;

	out = 0;
	if (*d->lastprinted || (*d->onedied && ft_strcmp(str, "%ld %i died\n") != 0))
		return (pthread_mutex_unlock(d->datam), 0);
	pthread_mutex_lock(d->printfm);
	onedied = *d->onedied;
	if (!*d->lastprinted && onedied && !ft_strcmp(str, "%ld %i died\n"))
	{

		out = printf(str, (long)millsect(d), d->philonum +1);
		*d->lastprinted = 1;
		pthread_mutex_unlock(d->printfm);
		return (out);
	}
	out = printf(str, (long)millsect(d), d->philonum +1);
	pthread_mutex_unlock(d->printfm);

	// out = printf(str, (long)millsect(d), d->philonum +1); // testing only
	return (out);
}