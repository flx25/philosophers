/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:19 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/06/08 10:19:19 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*out;

	if ((nmemb >= __SIZE_MAX__ && size >= __SIZE_MAX__))
		return (NULL);
	out = (unsigned char *) malloc(nmemb * size);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		out[i] = 0;
		i++;
	}
	return (out);
}
