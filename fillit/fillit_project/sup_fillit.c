/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_fillit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:53:09 by udraugr-          #+#    #+#             */
/*   Updated: 2018/12/08 13:30:06 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		ft_sqrt(int a)
{
	int		i;

	i = 0;
	while (a > i * i)
		i++;
	return (i);
}

void	ft_fill_dot(char greed[20][20])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		while (j < 20)
			greed[i][j++] = '.';
		i++;
		j = 0;
	}
}

void	ft_increase_y(int *x, int *y)
{
	(*y)++;
	*x = 0;
}
