/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:31:11 by gtaverne          #+#    #+#             */
/*   Updated: 2020/09/26 16:13:28 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int		ft_lenstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		legitbase(char *base)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (base[i])
	{
		if (ft_space(base[i]) || base[i] == '+' || base[i] == '-')
			return (0);
		k = i - 1;
		while (k >= 0)
		{
			if (base[i] == base[k])
				return (0);
			k--;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int		ft_l_tab(long int nb, char *base_to)
{
	int res;
	int i;

	res = 0;
	i = 0;
	if (nb < 0)
	{
		res++;
		nb = -nb;
	}
	if (nb == 0)
		return (0);
	while ((nb / ft_lenstr(base_to)) > 0)
	{
		nb = nb / ft_lenstr(base_to);
		res++;
	}
	res++;
	return (res);
}

char	*ft_convert_base2(int n, char *base_to)
{
	char			*tab;
	int				i;
	int				l_tab;
	long int		quo;

	l_tab = ft_l_tab((long int)n, base_to);
	if (!(tab = malloc(sizeof(char) * (l_tab + 1))))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		tab[0] = '-';
		quo = -(long int)n;
	}
	else
		quo = (long int)n;
	while (i < l_tab && quo > 0)
	{
		tab[l_tab - i - 1] = base_to[quo % ft_lenstr(base_to)];
		quo = quo / ft_lenstr(base_to);
		i++;
	}
	tab[l_tab] = '\0';
	return (tab);
}
