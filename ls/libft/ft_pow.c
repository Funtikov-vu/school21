/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:35:12 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/09 17:41:19 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int base, int n)
{
	int res;

	res = 1;
	while (n)
	{
		res *= base;
		n--;
	}
	return (res);
}