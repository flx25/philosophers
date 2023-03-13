/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:07:19 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/03/13 11:27:35 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	filld(int argc, char **argv, t_data *d)
{
	if (argc < 5)
	{
		printf("Please enter at least 4 arguments!\n");
		return (1);
	}
	d->nump = ft_atoi(argv[1]);
	d->ttodie = ft_atoi(argv[2]);
	d->ttoeat = ft_atoi(argv[3]);
	d->ttosleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->numberofeats = ft_atoi(argv[5]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (filld(argc, argv, &d) == 1)
		return (0);
}
