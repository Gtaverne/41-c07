/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:24:31 by gtaverne          #+#    #+#             */
/*   Updated: 2020/09/26 16:14:45 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;
	int	diff;

	i = 0;
	if (min >= max)
		return (NULL);
	diff = max - min;
	if (!(tab = malloc(sizeof(int) * diff)))
		return (NULL);
	while (i < diff)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
