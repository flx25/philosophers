/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:49:03 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/03/16 10:57:20 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				nump;
	int				ttodie;
	int				ttoeat;
	int				ttosleep;
	int				numberofndeats;
	int				philonum;
	pthread_t		tid;
	pthread_mutex_t	*forks;
	int				timeseaten;
	int				lasteat;
	struct timeval	time;
}				t_data;

int		ft_atoi(const char *nptr);
void	initforks(t_data **d);
int		grabforks(t_data *d);
void	eatandsleep(t_data *d);
double	millsect(t_data *d);

#endif
