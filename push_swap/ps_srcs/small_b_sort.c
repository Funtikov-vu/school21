/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_b_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:47:01 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 14:52:10 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort_b_2(t_arrnum *a, t_arrnum *b, int end, char **res)
{
	if (b->arr[0] > b->arr[1] && b->arr[0] < b->arr[2])
	{
		pa(a, b);
		sb(0, b);
		pa(a, b);
		sa(a, b);
		pa(a, b);
		*res = ft_strjdelfst(*res, "pa sb pa sa pa ");
	}
	else if (b->arr[2] > b->arr[0] && b->arr[2] < b->arr[1])
	{
		sb(0, b);
		*res = ft_strjdelfst(*res, "sb ");
		small_sort_b(a, b, end, res);
	}
	else if (b->arr[1] > b->arr[0] && b->arr[1] < b->arr[2])
	{
		sb(0, b);
		*res = ft_strjdelfst(*res, "sb ");
		small_sort_b(a, b, end, res);
	}
}

void	three_sort_b(t_arrnum *a, t_arrnum *b, int end, char **res)
{
	if (b->arr[1] < b->arr[0] && b->arr[1] > b->arr[2])
	{
		pa(a, b);
		pa(a, b);
		pa(a, b);
		*res = ft_strjdelfst(*res, "pa pa pa ");
	}
	else if (b->arr[2] < b->arr[0] && b->arr[2] > b->arr[1])
	{
		pa(a, b);
		*res = ft_strjdelfst(*res, "pa ");
		small_sort_b(a, b, end - 1, res);
	}
	else if (b->arr[0] < b->arr[1] && b->arr[0] > b->arr[2])
	{
		sb(0, b);
		*res = ft_strjdelfst(*res, "sb ");
		small_sort_b(a, b, end, res);
	}
	else
		return (three_sort_b_2(a, b, end, res));
}

void	small_sort_b(t_arrnum *a, t_arrnum *b, int end, char **res)
{
	int i;

	i = 0;
	if (end <= 2)
	{
		if (end == 2)
			if (b->arr[0] < b->arr[1])
			{
				*res = ft_strjdelfst(*res, "sb ");
				sb(0, b);
			}
		while (i < end)
		{
			pa(a, b);
			*res = ft_strjdelfst(*res, "pa ");
			i++;
		}
	}
	else
		return (three_sort_b(a, b, end, res));
}
