/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 16:31:16 by gtaverne          #+#    #+#             */
/*   Updated: 2020/09/20 20:49:22 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = 0;
	if (max <= min)
	{
		range = NULL;
		return (0);
	}
	*range = malloc((max - min + 1) * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (i < max - min)
	{
		**range = i + min;
		i++;
	}
	return (max - min);
}
