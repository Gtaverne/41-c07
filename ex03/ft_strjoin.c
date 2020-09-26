/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:37:38 by gtaverne          #+#    #+#             */
/*   Updated: 2020/09/26 16:16:04 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int offset;

	i = 0;
	offset = ft_len(dest);
	while (src[i])
	{
		dest[offset + i] = src[i];
		i++;
	}
	dest[offset + i] = 0;
	return (dest);
}

int		total_length(int size, char **strs, char *sep)
{
	int i;
	int res;

	res = 0;
	i = 0;
	while (i < size)
	{
		res += ft_len(strs[i]);
		i++;
	}
	res += (size - 1) * ft_len(sep);
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*tab;
	int		ttal;

	ttal = total_length(size, strs, sep);
	if (!(tab = malloc(sizeof(char) * (ttal + 1))))
		return (NULL);
	i = 0;
	tab[0] = 0;
	while (i < size - 1)
	{
		tab = ft_strcat(tab, strs[i]);
		tab = ft_strcat(tab, sep);
		i++;
	}
	tab = ft_strcat(tab, strs[size - 1]);
	return (tab);
}
