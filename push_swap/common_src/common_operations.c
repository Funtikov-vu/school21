/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:53:25 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/08 20:00:43 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sarr(t_arrnum *arrnum)
{
	int temp;

	if (arrnum->size <= 1)
		return ;
	temp = arrnum->arr[0];
	arrnum->arr[0] = arrnum->arr[1];
	arrnum->arr[1] = temp;
}

void	rarr(t_arrnum *arrnum)
{
	int temp;

	temp = arrnum->arr[0];
	if (arrnum->size <= 1)
		return ;
	ft_memmove(arrnum->arr, arrnum->arr + 1, sizeof(int) * (arrnum->size - 1));
	arrnum->arr[arrnum->size - 1] = temp;
}

void	rrarr(t_arrnum *arrnum)
{
	int temp;

	temp = arrnum->arr[arrnum->size - 1];
	if (arrnum->size <= 1)
		return ;
	ft_memmove(arrnum->arr + 1, arrnum->arr, sizeof(int) * (arrnum->size - 1));
	arrnum->arr[0] = temp;
}

void	parr(t_arrnum *arrnum1, t_arrnum *arrnum2)
{
	if (arrnum1->size == 0)
		return ;
	ft_memmove(arrnum2->arr + 1, arrnum2->arr, sizeof(int) * (arrnum2->size));
	arrnum2->size += 1;
	arrnum2->arr[0] = arrnum1->arr[0];
	ft_memmove(arrnum1->arr, arrnum1->arr + 1,
			sizeof(int) * (arrnum1->size - 1));
	arrnum1->size -= 1;
}
