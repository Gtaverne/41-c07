/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaverne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:10:08 by gtaverne          #+#    #+#             */
/*   Updated: 2020/09/23 15:50:21 by gtaverne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_space(char c);
int		ft_lenstr(char *str);
int		legitbase(char *base);
int		ft_l_tab(int nb, char *base_to);
char	*ft_convert_base2(int n, char *base_to);

int		value_inbase(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int result;

	sign = 1;
	i = 0;
	result = 0;
	if (legitbase(base) == 0)
		return (0);
	while (str[i] && ft_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (value_inbase(str[i], base) >= 0 && str[i])
	{
		result = result * (ft_lenstr(base)) + value_inbase(str[i], base);
		i++;
	}
	return (sign * result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	char	*res;

	if (legitbase(base_from) == 0 || legitbase(base_to) == 0)
		return (NULL);
	i = ft_atoi_base(nbr, base_from);
	res = ft_convert_base2(i, base_to);
	return (res);
}
