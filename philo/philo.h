/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:49:03 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/07/31 14:35:16 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_mainstruct
{
	int				nump;
	int				i;
	int				lastprinted;
	int				finishedall;
	int				isdead;
}				t_mainstruct;

typedef struct s_data
{
	int				nump;
	int				ttodie;
	int				ttoeat;
	int				ttosleep;
	int				numberofndeats;
	int				philonum;
	int				fork1;
	int				fork2;
	pthread_t		tid;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*datam;
	pthread_mutex_t	*printfm;
	int				*onedied;
	int				*lastprinted;
	int				timeseaten;
	double			lasteat;
	struct timeval	time;
	double			starttime;
	int				finished;
	int				*allfinished;
}				t_data;

int		ft_atoi(const char *nptr);
void	initforks(t_data **d);
int		grabforks(t_data *d);
int		eatandsleep(t_data *d);
double	millsect(t_data *d);
void	assignforks(t_data **d);
double	millsectf(t_data *d);
void	sleepmil(int waittime, t_data *d);
void	*ft_calloc(size_t nmemb, size_t size);
int		checkfunct(t_data **d);
int		mt_printf(char *str, t_data *d);
int		ft_strcmp(char *s1, char *s2);
void	freefunct(t_data **d);
void	detachall(t_data **d);
void	*ft_memset(void *s, int c, size_t n);
void	eatandsleep_middle(t_data *d);

#endif
