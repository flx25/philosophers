/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:49:03 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/03/13 13:44:41 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>

typedef struct s_data
{
	int	nump;
	int	ttodie;
	int	ttoeat;
	int	ttosleep;
	int	numberofeats;
}				t_data;

int	ft_atoi(const char *nptr);

#endif