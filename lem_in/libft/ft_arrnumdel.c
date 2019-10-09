/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnumdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:52:28 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/11 15:53:25 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrnumdel(t_arrnum *a)
{
	if (a)
	{
		if (a->arr)
			free(a->arr);
		free(a);
	}
}