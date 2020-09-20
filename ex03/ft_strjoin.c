/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:47:52 by gtaverne          #+#    #+#             */
/*   Updated: 2020/09/20 20:34:39 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	while (*(dest + i) != '\0')
	{
		i++;
	}
	dest_len = i;
	i = 0;
	while (*(src + i) != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest);
}

int		nb_sep(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i - 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*tab;
	int		ns;

	ns = nb_sep(strs);
	if (size == 0)
	{
		tab = malloc(sizeof(char));
		return (tab);
	}
	tab = malloc((size + 1 + ns * ft_len(sep)) * sizeof(char));
	if (tab == NULL)
		return (tab);
	tab[0] = 0;
	i = 0;
	while (i < ns)
	{
		tab = ft_strcat(tab, strs[i]);
		tab = ft_strcat(tab, sep);
		i++;
	}
	tab = ft_strcat(tab, strs[ns]);
	return (tab);
}
