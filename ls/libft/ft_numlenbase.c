/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:25:42 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 19:43:22 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlenbase(long long int nb, int base)
{
	int res;

	if (nb < 0)
	{
		res = 2;
		nb = -nb;
	}
	else
		res = 1;
	while (nb >= base)
	{
		nb /= base;
		res++;
	}
	return (res);
}

int	ft_numlen(int nb)
{
	int res;

	if (nb < 0)
	{
		res = 2;
		nb = -nb;
	}
	else
		res = 1;
	while (nb >= 10)
	{
		nb /= 10;
		res++;
	}
	return (res);
}
